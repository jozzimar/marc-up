#include "marcacion.hpp"
#include <iostream>
#include <list>

const unsigned int ENTER_1 = 36;
const unsigned int ENTER_2 = 104;
int press = 0;
std::string dias[] = {"Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado"};
std::string meses[] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};
cppdb::statement sentencia; 

struct usuario 
{
	unsigned int id;
	std::string username;
	std::string password;
};

struct marcacion
{
	unsigned int usuario_id;
	std::string dia;
	std::string fecha;
	int horas_ord;
	int horas_extras;
	int tiempo;
	std::time_t entrada;
	std::time_t salida;
	bool en_curso;
};

std::list<usuario> usuarios;
std::list<marcacion> marcaciones;

Marcacion::Marcacion ()
{
	this->entry_id_clerk.add_events (Gdk::KEY_RELEASE_MASK);
  	this->entry_id_clerk.signal_key_release_event().connect (sigc::mem_fun (*this, &Marcacion::key_enter));
  	
	this->set_mark_clerk();
	this->add(this->caja_program);
	
	this->set_resizable(false);
	this->set_position (Gtk::WIN_POS_CENTER);
	this->set_border_width (20);
	this->set_title ("Marc Up");
	this->show_all ();

	this->session.open("sqlite3:db=../db.sqlite");
	sentencia = this->session << "PRAGMA foreign_keys=ON" << cppdb::exec;
	
	cppdb::result query = this->session << "SELECT id, username, password FROM 'usuario' INNER JOIN 'usuarios_grupos' WHERE 'usuario'.id='usuarios_grupos'.'usuario_id' AND 'usuarios_grupos'.'grupo_id'=2";
		
	while (query.next ())
	{
		usuario nuevo = usuario ();
		nuevo.id = query.get<int>("id");
		nuevo.username = query.get<std::string>("username");
		nuevo.password = query.get<std::string>("password");
		usuarios.push_back (nuevo);
		
		marcacion nueva = marcacion ();
		nueva.usuario_id = nuevo.id;
		nueva.en_curso = false;
		marcaciones.push_back (nueva);
	}
}

Marcacion::~Marcacion ()
{
}

void Marcacion::set_mark_clerk()
{
	
	//inicialización del contenedor principal
	this->caja_program.set_orientation(Gtk::Orientation (Gtk::ORIENTATION_VERTICAL));
	
	//inicialización del contenedor del logo
	this->caja_image.set_orientation(Gtk::Orientation (Gtk::ORIENTATION_HORIZONTAL));
	
	//inicialización del contenedor campo usuario
	this->caja_type_and_users.set_orientation(Gtk::Orientation (Gtk::ORIENTATION_VERTICAL));
	
	//inicialización de el image con el logo
	this->logo.set("images/logo.png");
	this->logo.set_margin_bottom(25);
		
	this->entry_id_clerk.set_visibility (true);
	this->label_id_clerk.set_text("Numero de Identificación");
	this->label_id_clerk.set_margin_bottom(5);
	this->label_id_clerk.set_alignment (Gtk::ALIGN_START);
	this->entry_id_clerk.set_text("");
	this->entry_id_clerk.set_margin_bottom(25);
	
	this->label_marker_register.set_text("");
	
	//empaquetado del contenedor principal	
	this->caja_program.pack_start(this->caja_image);
	this->caja_program.pack_start(this->caja_type_and_users);	
	
	//empaquetado del encabezado
	this->caja_image.pack_start(this->logo);
	this->caja_type_and_users.pack_start(this->label_id_clerk);
	this->caja_type_and_users.pack_start(this->entry_id_clerk);
	this->caja_type_and_users.pack_start(this->label_marker_register);
	
}

bool Marcacion::key_enter (GdkEventKey* event)
{
	std::string tipo = std::string ();
	
	if((event->hardware_keycode == ENTER_1 or event->hardware_keycode == ENTER_2)and(press==0))
	{
		this->label_id_clerk.set_text("Contraseña");
 		this->entry_id_clerk.set_visibility (false);
 		press=1;
 		
 		this->username = this->entry_id_clerk.get_text ();

		this->entry_id_clerk.set_text("");
		return true;
	}
	
	if((event->hardware_keycode == ENTER_1 or event->hardware_keycode == ENTER_2)and(press==1))
	{
		
		this->label_id_clerk.set_text("Numero de Identificación");
 		this->entry_id_clerk.set_visibility (true);
 		
 		press=0;
 		
		this->password = this->entry_id_clerk.get_text ();
		
		bool encontrado = false;			
		for (std::list<usuario>::iterator iterador_usuario = usuarios.begin (); iterador_usuario != usuarios.end (); ++iterador_usuario)
		{
			if(iterador_usuario->username == this->username and iterador_usuario->password == this->password)
			{	
				encontrado = true;

				for (std::list<marcacion>::iterator iterador_marcacion = marcaciones.begin (); iterador_marcacion != marcaciones.end (); ++iterador_marcacion)
				{
					if (iterador_usuario->id == iterador_marcacion->usuario_id)
					{
						if (!iterador_marcacion->en_curso)
		 				{
		 					tipo = "entrada";
 							iterador_marcacion->en_curso = true;
 							std::time (&iterador_marcacion->entrada);
 							break;
 						}
 					
 						if (iterador_marcacion->en_curso)
 						{
 							tipo = "salida";
 							std::time_t hoy;
 							std::tm *hoy_info;
 							
 							std::time (&hoy);
 							hoy_info = std::gmtime (&hoy);
 							
 							std::stringstream fecha;
 							
 							fecha << hoy_info->tm_mday << "/" << (hoy_info->tm_mon+1) << "/" << (hoy_info->tm_year + 1900);
 							
 							iterador_marcacion->en_curso = false;
 							std::time (&iterador_marcacion->salida);
 							iterador_marcacion->dia = dias[hoy_info->tm_wday];
 							iterador_marcacion->fecha = fecha.str ();
 							
 							iterador_marcacion->tiempo += (iterador_marcacion->salida - iterador_marcacion->entrada)/60;
 							if (iterador_marcacion->tiempo <= 8)
 							{
 								iterador_marcacion->horas_ord = iterador_marcacion->tiempo;
 							}
 							else
 							{
 								iterador_marcacion->horas_extras = iterador_marcacion->tiempo-8;
 							}
 							
 							cppdb::result query = this->session << "SELECT * FROM 'marcacion' WHERE 'marcacion'.'usuario_id'=? AND 'marcacion'.'fecha'=?" << iterador_marcacion->usuario_id << iterador_marcacion->fecha << cppdb::row;
 							
 							if (!query.empty ())
 							{
 								sentencia = this->session << "UPDATE 'marcacion' SET 'horas_ord'=?, 'horas_extras'=? WHERE 'marcacion'.'usuario_id'=? AND 'marcacion'.'fecha'=?" << iterador_marcacion->horas_ord << iterador_marcacion->horas_extras << iterador_marcacion->usuario_id << iterador_marcacion->fecha << cppdb::exec;
 							}
 							else
 							{
 								sentencia = this->session << "INSERT INTO 'marcacion' ('usuario_id', 'dia', 'fecha', 'horas_ord', 'horas_extras') VALUES (?, ?, ?, ?, ?)" << iterador_marcacion->usuario_id << iterador_marcacion->dia << iterador_marcacion->fecha << iterador_marcacion->horas_ord << iterador_marcacion->horas_extras << cppdb::exec;
 							}
 							
 							break;
 						}
 					}
 				}
 				break;
			}
			
		}
		
		if (encontrado)
		{
			this->label_marker_register.set_text("Marcación de "+tipo+" registrada.");
		}
		else
		{
			this->label_marker_register.set_text("Usuario o contraseña invalida.");
		}

		this->entry_id_clerk.set_text("");
		sigc::slot<bool> my_slot = sigc::bind (sigc::mem_fun(*this, &Marcacion::reset_label_marcacion), 0);
 		sigc::connection conn = Glib::signal_timeout ().connect (my_slot, 3000);	 		
 		
 		return true;
 	}
	return false;
}

bool Marcacion::reset_label_marcacion (int valor)
{	
	this->label_marker_register.set_text ("");
	
	return false;
}
