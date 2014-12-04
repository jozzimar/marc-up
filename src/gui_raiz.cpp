#include "gui_raiz.hpp"
#include <iostream>
#include <fstream>


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
};

std::list<usuario> usuarios;
std::list<marcacion> marcaciones;

Gui_raiz::Gui_raiz ()
  
{

	this->button_in.signal_clicked ().connect (sigc::mem_fun (*this, &Gui_raiz::layout_login) );
	this->button_add_clerk.signal_clicked ().connect (sigc::mem_fun (*this, &Gui_raiz::layout_add_clerk) );
	
	this->button_save_add_clerk.signal_clicked ().connect (sigc::mem_fun (*this, &Gui_raiz::save_add_clerk) );
	this->button_cancel_add_clerk.signal_clicked ().connect (sigc::mem_fun (*this, &Gui_raiz::cancel_add_clerk) );
	
	this->button_rid_clerk.signal_clicked ().connect (sigc::mem_fun (*this, &Gui_raiz::layout_rid_clerk) );
	this->button_delete_clerk.signal_clicked ().connect (sigc::mem_fun (*this, &Gui_raiz::delete_clerk) );
	this->button_cancel_rid_clerk.signal_clicked ().connect (sigc::mem_fun (*this, &Gui_raiz::cancel_rid_clerk) );
	
	this->button_generate_report.signal_clicked ().connect (sigc::mem_fun (*this, &Gui_raiz::layout_report) );
	this->button_cancel_report.signal_clicked ().connect (sigc::mem_fun (*this, &Gui_raiz::cancel_report) );
	this->combo_type_report.signal_changed().connect( sigc::mem_fun(*this,&Gui_raiz::on_combo_clerk) );
	
	this->button_generate.signal_clicked ().connect (sigc::mem_fun (*this, &Gui_raiz::generar_reporte) );
	
	this->session.open("sqlite3:db=db.sqlite");
	cppdb::statement sentencia = this->session << "PRAGMA foreign_keys=ON" << cppdb::exec;
	
	this->set_login();
	this->set_admin ();
	this->set_add_clerk();
	this->set_rid_clerk();
	this->set_report();
	this->add(this->caja_login);
	
	this->set_resizable(false);
	this->set_position (Gtk::WIN_POS_CENTER);
	this->set_border_width (20);
	this->set_title ("Marc Up");
	this->show_all ();
	
	//this->caja_add_clerk.hide();
	
	cppdb::result query = this->session << "SELECT id, username, password FROM 'usuario' WHERE 'usuario'.'id'>1";
		
	while (query.next ())
	{
		usuario nuevo = usuario ();
		nuevo.id = query.get<int>("id");
		nuevo.username = query.get<std::string>("username");
		nuevo.password = query.get<std::string>("password");
		usuarios.push_back (nuevo);
	}
	
	query = this->session << "SELECT usuario_id, dia, fecha, horas_ord, horas_extras FROM 'marcacion'";
	
	while (query.next ())
	{
		marcacion nueva = marcacion ();
		nueva.usuario_id = query.get<unsigned int>("usuario_id");
		nueva.dia = query.get<std::string>("dia");
		nueva.fecha = query.get<std::string>("fecha");
		nueva.horas_ord = query.get<int>("horas_ord");
		nueva.horas_extras = query.get<int>("horas_extras");
		marcaciones.push_back (nueva);
	}
}

Gui_raiz::~Gui_raiz ()
{
}

void Gui_raiz::set_login()
{
	//inicialización del contenedor principal
	this->caja_login.set_orientation(Gtk::Orientation (Gtk::ORIENTATION_VERTICAL));
	
	//inicialización del contenedor del logo
	this->caja_encabezado_login.set_orientation(Gtk::Orientation (Gtk::ORIENTATION_HORIZONTAL));
	
	//inicialización del contenedor campo usuario
	this->caja_usuarios.set_orientation(Gtk::Orientation (Gtk::ORIENTATION_VERTICAL));
	
	//inicialización del contenedor campo contraseña
	this->caja_passwords.set_orientation(Gtk::Orientation (Gtk::ORIENTATION_VERTICAL));
	
	//inicialización de el image con el logo
	this->logo_login.set("images/logo.png");
	
	//inicialización de los campos usuario label y entry
	this->usuario_label.set_margin_top(25);
	this->usuario_label.set_text ("Usuario");
	this->usuario_label.set_alignment (Gtk::ALIGN_START);
	this->usuario_entry.set_text("");
	this->usuario_entry.set_margin_bottom(25);
	this->password_entry.set_visibility (false);
	this->password_label.set_text("Contraseña");
	this->password_label.set_alignment (Gtk::ALIGN_START);
	this->password_entry.set_text("");
	this->password_entry.set_margin_bottom(25);
	this->button_in.set_label ("Entrar");
	
	//empaquetado del contenedor principal	
	this->caja_login.pack_start(this->caja_encabezado_login);
	this->caja_login.pack_start(this->caja_usuarios);	
	this->caja_login.pack_start(this->caja_passwords);
	this->caja_login.pack_start(this->caja_button_login);

	//empaquetado del encabezado
	this->caja_encabezado_login.pack_start(this->logo_login);

	//empaquetado de los campos usuario
	this->caja_usuarios.set_spacing (0);
	this->caja_usuarios.pack_start(this->usuario_label);
	this->caja_usuarios.pack_start(this->usuario_entry);

	//empaquetado de los campos password
	this->caja_passwords.pack_start(this->password_label);
	this->caja_passwords.pack_start(this->password_entry);
	
	this->caja_button_login.pack_end(this->button_in, Gtk::PACK_SHRINK);
}


void Gui_raiz::set_admin()
{
	//inicialización del contenedor principal
	this->caja_admin.set_orientation(Gtk::Orientation (Gtk::ORIENTATION_VERTICAL));
	
	//inicialización del contenedor del logo
	this->caja_encabezado_admin.set_orientation(Gtk::Orientation (Gtk::ORIENTATION_HORIZONTAL));
	
	//inicializacion de contenedor imagenes y botones
	this->caja_button_admin.set_orientation(Gtk::Orientation (Gtk::ORIENTATION_HORIZONTAL));
	this->caja_images.set_orientation(Gtk::Orientation (Gtk::ORIENTATION_HORIZONTAL));
	
	//inicializacion de imagenes
	this->logo_admin.set("images/logo.png");
	this->logo_admin.set_margin_bottom(25);
	this->add_clerk.set("images/add1.png");
	this->add_clerk.set_margin_bottom(15);
	this->rid_clerk.set("images/rid1.png");
	this->rid_clerk.set_margin_bottom(15);
	this->report.set("images/report1.png");
	this->report.set_margin_bottom(15);
	
	//inicialización de los button e images
	this->button_add_clerk.set_label("CREAR/ACTUALIZAR");
	this->button_add_clerk.set_border_width(10);
	this->button_rid_clerk.set_label("ELIMINAR");
	this->button_rid_clerk.set_border_width(10);
	
	this->button_generate_report.set_label("GENERAR REPORTE");
	this->button_generate_report.set_border_width(10);
	
	//empaquetado del contenedor principal	
	this->caja_admin.pack_start(this->caja_encabezado_admin);
	this->caja_admin.pack_start(this->caja_images);
	this->caja_admin.pack_start(this->caja_button_admin);
	
	//empaquetado del encabezado
	this->caja_encabezado_admin.pack_start(this->logo_admin);

	//empaquetado de los button
	this->caja_button_admin.set_spacing (0);
	this->caja_button_admin.pack_start(this->button_add_clerk);
	this->caja_button_admin.pack_start(this->button_rid_clerk);
	this->caja_button_admin.pack_start(this->button_generate_report);
	
	//empaquetado de las imagenes
	this->caja_images.pack_start(this->add_clerk);
	this->caja_images.pack_start(this->rid_clerk);
	this->caja_images.pack_start(this->report);
}

void Gui_raiz::set_add_clerk()
{
	//inicialización del contenedor principal
	this->caja_add_clerk.set_orientation(Gtk::Orientation (Gtk::ORIENTATION_VERTICAL));
	
	//inicialización del contenedor del logo
	this->caja_encabezado_add_clerk.set_orientation(Gtk::Orientation (Gtk::ORIENTATION_HORIZONTAL));
	
	// inicializacion de contenedor columnas
	this->caja_blok1_add_clerk.set_orientation(Gtk::Orientation (Gtk::ORIENTATION_VERTICAL));
	this->caja_blok1_add_clerk.set_border_width(25);
	this->caja_blok2_add_clerk.set_orientation(Gtk::Orientation (Gtk::ORIENTATION_VERTICAL));
	this->caja_blok2_add_clerk.set_border_width(25);
	this->caja_buttons_add_clerk.set_orientation (Gtk::Orientation(Gtk::ORIENTATION_HORIZONTAL));
	
	//inicializacion de imagenes
	this->logo_add_clerk.set("images/logo.png");
	this->logo_add_clerk.set_margin_bottom(25);
	
	//inicialización de los campos usuario label, entry y combo bloque 1
	this->label_type_id.set_text ("Tipo de Identificacion");
	this->label_type_id.set_margin_bottom(5);
	this->label_type_id.set_alignment (Gtk::ALIGN_START);

	this->combo_type_id.append ("");
	this->combo_type_id.append ("RC");	
	this->combo_type_id.append ("CC");
	this->combo_type_id.append ("CE");
	this->combo_type_id.append ("NUIP");
	this->combo_type_id.set_margin_bottom(25);
	
	this->label_name.set_text("Nombres");
	this->label_name.set_margin_bottom(5);
	this->label_name.set_alignment (Gtk::ALIGN_START);

	this->entry_name.set_text("");
	this->entry_name.set_margin_bottom(25);
	
	this->label_eps.set_text("Eps");
	this->label_eps.set_margin_bottom(5);
	this->label_eps.set_alignment (Gtk::ALIGN_START);

	this->entry_eps.set_text("");
	this->entry_eps.set_margin_bottom(25);
	
	this->label_appointment.set_text("Cargo");
	this->label_appointment.set_alignment (Gtk::ALIGN_START);

	this->combo_appointment.append("");
	this->combo_appointment.append("Aprendiz SENA");	
	this->combo_appointment.append("Asistente Técnico");
	this->combo_appointment.append("Auxiliar Técnico");
	this->combo_appointment.append("Jefe de Grupo");
	this->combo_appointment.set_margin_bottom(25);
	
	this->button_save_add_clerk.set_label ("Save");
	this->button_save_add_clerk.set_border_width(25);
	
	//inicialización de los campos usuario label, entry y combo bloque 2
	this->label_num_id.set_text("Numero de Identificacion");
	this->label_num_id.set_margin_bottom(5);
	this->label_num_id.set_alignment (Gtk::ALIGN_START);
	
	this->entry_num_id.set_text("");
	this->entry_num_id.set_margin_bottom(25);
	
	this->label_surname.set_text("Apellidos");
	this->label_surname.set_margin_bottom(5);
	this->label_surname.set_alignment (Gtk::ALIGN_START);
	
	this->entry_surname.set_text("");
	this->entry_surname.set_margin_bottom(25);
	
	this->label_arl.set_text("Arl");
	this->label_arl.set_margin_bottom(5);
	this->label_arl.set_alignment (Gtk::ALIGN_START);
	
	this->entry_arl.set_text("");
	this->entry_arl.set_margin_bottom(25);

	this->label_area.set_text("Contraseña");
	this->label_area.set_alignment (Gtk::ALIGN_START);
	
	this->entry_contra.set_margin_bottom(25);
	this->entry_contra.set_visibility (false);
	this->entry_contra.set_text("");
	this->entry_contra.set_margin_bottom(25);	
	
	
	this->button_cancel_add_clerk.set_label ("Cancel");
	this->button_cancel_add_clerk.set_border_width(25);

	// empaquetado en la caja principal
	this->caja_add_clerk.pack_start(this->caja_encabezado_add_clerk);
	this->caja_add_clerk.pack_start(this->grid_unit_add_clerk);
	this->caja_add_clerk.pack_start(this->caja_buttons_add_clerk);
	
	//empaquetado en la caja que une las columnas
	this->grid_unit_add_clerk.add(this->caja_blok1_add_clerk);
	this->grid_unit_add_clerk.add(this->caja_blok2_add_clerk);
	
	//empaquetado del encabezado
	this->caja_encabezado_add_clerk.pack_start(this->logo_add_clerk);
	
	//empaquetado del bloque 1
	this->caja_blok1_add_clerk.pack_start(this->label_type_id);
	this->caja_blok1_add_clerk.pack_start(this->combo_type_id);
	this->caja_blok1_add_clerk.pack_start(this->label_name);
	this->caja_blok1_add_clerk.pack_start(this->entry_name);
	this->caja_blok1_add_clerk.pack_start(this->label_eps);
	this->caja_blok1_add_clerk.pack_start(this->entry_eps);
	this->caja_blok1_add_clerk.pack_start(this->label_appointment);
	this->caja_blok1_add_clerk.pack_start(this->combo_appointment);
	
	//empaquetado del bloque 2
	this->caja_blok2_add_clerk.pack_start(this->label_num_id);
	this->caja_blok2_add_clerk.pack_start(this->entry_num_id);
	this->caja_blok2_add_clerk.pack_start(this->label_surname);
	this->caja_blok2_add_clerk.pack_start(this->entry_surname);
	this->caja_blok2_add_clerk.pack_start(this->label_arl);
	this->caja_blok2_add_clerk.pack_start(this->entry_arl);
	this->caja_blok2_add_clerk.pack_start(this->label_area);
	this->caja_blok2_add_clerk.pack_start(this->entry_contra);
	
	// empaquetado de botones
	this->caja_buttons_add_clerk.pack_start(this->button_save_add_clerk);
	this->caja_buttons_add_clerk.pack_end(this->button_cancel_add_clerk);	
}

void Gui_raiz::layout_login ()
{
	std::string username = this->usuario_entry.get_text ();
	std::string password = this->password_entry.get_text ();
	
	cppdb::result query = this->session << "SELECT username, password FROM 'usuario' WHERE username=? AND password=?" << username << password << cppdb::row;
	
	if (!query.empty ())
	{
		this->remove ();
		this->add(this->caja_admin);
		this->show_all ();
	}
	
}

void Gui_raiz::layout_add_clerk ()
{
	this->remove ();
	this->add(this->caja_add_clerk);
	this->show_all ();
}

void Gui_raiz::save_add_clerk ()
{
	Gtk::MessageDialog messagedialog_save(*this,"¿DESEA ALMACENAR LOS DATOS DEL EMPLEADO?", false, Gtk::MESSAGE_QUESTION, Gtk::BUTTONS_OK_CANCEL);
	messagedialog_save.set_secondary_text ("Si los datos suministrados son correctos pulse Aceptar.");
	
	int result = messagedialog_save.run ();
	cppdb::statement sentencia;
	
	std::string contrasenia;
	std::string username;
	
	std::string type_id;
	std::string number_id;
	std::string name;
	std::string surname;
	
	std::string eps;
	std::string arl;
	std::string cargo;
	
	switch (result)
	{
		case (Gtk::RESPONSE_OK):
			std::cout << "Aceptar" << std::endl;
			
			username = this->combo_type_id.get_active_text ()+"_"+this->entry_num_id.get_text ();
			contrasenia = this->entry_contra.get_text ();
			
			type_id = this->combo_type_id.get_active_text ();
			number_id  = this->entry_num_id.get_text ();
			name = this->entry_name.get_text ();
			surname = this->entry_surname.get_text ();
			
			eps = this->entry_eps.get_text ();
			arl = this->entry_arl.get_text ();
			cargo = this->combo_appointment.get_active_text ();
			
			sentencia = this->session << "INSERT INTO usuario (username,password) VALUES(?, ?)" << username  << contrasenia << cppdb::exec;
			sentencia = this->session << "INSERT INTO basicdata (usuario_id, type_id, number_id, name, surname) VALUES (last_insert_rowid (), ?, ?, ?, ?)" << type_id << number_id << name << surname << cppdb::exec;
			sentencia = this->session << "INSERT INTO complementarydata (usuario_id, eps, arl, cargo) VALUES (last_insert_rowid (), ?, ?, ?)" << eps << arl << cargo << cppdb::exec;
			
			this->combo_type_id.set_active_text ("");
			this->entry_name.set_text ("");
			this->entry_eps.set_text ("");
			this->combo_appointment.set_active_text ("");
			this->entry_num_id.set_text ("");
			this->entry_surname.set_text ("");
			this->entry_arl.set_text ("");
			this->entry_contra.set_text ("");
			
			break;
			
		case (Gtk::RESPONSE_CANCEL):
			std::cout << "Cancelar" << std::endl;
			break;
			
		default:
			std::cout << "Nunca Pasa" << std::endl;
			break;
	}
}

void Gui_raiz::layout_rid_clerk ()
{
	this->remove ();
	this->add(this->caja_rid_clerk);
	this->show_all ();
}


void Gui_raiz::cancel_add_clerk ()
{
	this->remove ();
	this->add(this->caja_admin);
	this->show_all ();
}

void Gui_raiz::delete_clerk ()
{
	std::string username = this->combo_type_id_rid_clerk.get_active_text ()+"_"+this->entry_num_id_rid_clerk.get_text ();
	
	cppdb::statement sentencia;
	cppdb::result query;
	
	query = this->session << "SELECT name, surname FROM 'basicdata' INNER JOIN 'usuario' ON usuario.id=basicdata.usuario_id AND usuario.username=?" << username << cppdb::row;
	
	if (!query.empty ())
	{
		std::string nombre = query.get<std::string>("name")+" "+query.get<std::string>("surname");
		Gtk::MessageDialog messagedialog_delete(*this,"¿CONFIRMA QUE DESEA ELIMINAR AL EMPLEADO?", false, Gtk::MESSAGE_QUESTION, Gtk::BUTTONS_OK_CANCEL);
		messagedialog_delete.set_secondary_text (nombre+"\nSi los datos son correctos pulse Aceptar.");

		int result = messagedialog_delete.run ();		
		switch (result)
		{
			case (Gtk::RESPONSE_OK):
				std::cout << "Aceptar" << std::endl;
				sentencia = this->session << "DELETE FROM usuario WHERE username=?" << username << cppdb::exec;
				
				this->combo_type_id_rid_clerk.set_active_text ("");
				this->entry_num_id_rid_clerk.set_text ("");
				break;		
			
			case (Gtk::RESPONSE_CANCEL):
				std::cout << "Cancelar" << std::endl;
				break;
			
			default:
				std::cout << "Nunca Pasa" << std::endl;
				break;
		}
	}
	else
	{
		Gtk::MessageDialog messagedialog_delete(*this,"EL EMPLEADO NO EXISTE", false, Gtk::MESSAGE_QUESTION);
		int result = messagedialog_delete.run ();
	}
}

void Gui_raiz::cancel_rid_clerk ()
{
	this->remove ();
	this->add(this->caja_admin);
	this->show_all ();
}

void Gui_raiz::layout_report ()
{
	this->remove ();
	this->add(this->caja_report);
	this->show_all ();
}

void Gui_raiz::set_report ()
{
	//contenedor principal
	this->caja_report.set_orientation(Gtk::Orientation (Gtk::ORIENTATION_VERTICAL));
	
	//inicialización del contenedor del logo
	this->caja_encabezado_report.set_orientation(Gtk::Orientation (Gtk::ORIENTATION_HORIZONTAL));
	
	//inicializacion del contenedor tipo reporte
	this->caja_type_report.set_orientation(Gtk::Orientation (Gtk::ORIENTATION_VERTICAL));		
	
	//inicialización del contendor de botones
	this->caja_buttons_report.set_orientation(Gtk::Orientation (Gtk::ORIENTATION_HORIZONTAL));
	
	//inicializacion de imagenes
	this->logo_report.set("images/logo.png");
	this->logo_report.set_margin_bottom(25);
	
	//inicialización de los campos usuario label, entry...
	this->label_type_report.set_text ("Tipo de Informe");
	this->label_type_report.set_margin_bottom(5);
	this->label_type_report.set_alignment (Gtk::ALIGN_START);
	
	this->combo_type_report.append ("");
	this->combo_type_report.append ("General");	
	this->combo_type_report.append ("Individual");
	this->combo_type_report.set_margin_bottom(25);

	this->label_num_id_report.set_text("Numero de Identificacion");
	this->label_num_id_report.set_margin_bottom(5);
	this->label_num_id_report.set_alignment (Gtk::ALIGN_START);
	
	this->entry_num_id_report.set_text("");
	this->entry_num_id_report.set_can_focus(false);
	this->entry_num_id_report.set_margin_bottom(25);
		
	this->button_generate.set_label ("Generar Reporte");
	this->button_generate.set_border_width(25);
	
	this->button_cancel_report.set_label ("Cancelar");
	this->button_cancel_report.set_border_width(25);

	// empaquetado en la caja principal
	this->caja_report.pack_start(this->caja_encabezado_report);
	this->caja_report.pack_start(this->caja_type_report);
	this->caja_report.pack_start(this->caja_buttons_report);
	
	//empaquetado del encabezado
	this->caja_encabezado_report.pack_start(this->logo_report);
	
	//empquetado de datos
	this->caja_type_report.pack_start(this->label_type_report);
	this->caja_type_report.pack_start(this->combo_type_report);
	this->caja_type_report.pack_start(this->label_num_id_report);
	this->caja_type_report.pack_start(this->entry_num_id_report);

	// empaquetado de botones
	this->caja_buttons_report.pack_start(this->button_generate);
	this->caja_buttons_report.pack_start(this->button_cancel_report);
}

void Gui_raiz::on_combo_clerk()
{
	Glib::ustring text = combo_type_report.get_active_text();
	if(text=="Individual")
		this->entry_num_id_report.set_can_focus(true);
		
	else
		this->entry_num_id_report.set_can_focus(false);
}

void Gui_raiz::set_rid_clerk ()
{
	//contenedor principal
	this->caja_rid_clerk.set_orientation(Gtk::Orientation (Gtk::ORIENTATION_VERTICAL));
	
	//inicialización del contenedor del logo
	this->caja_encabezado_rid_clerk.set_orientation(Gtk::Orientation (Gtk::ORIENTATION_HORIZONTAL));	
	
	this->caja_blok1_rid_clerk.set_orientation(Gtk::Orientation (Gtk::ORIENTATION_VERTICAL));
	this->caja_blok1_rid_clerk.set_border_width(25);
	this->caja_blok2_rid_clerk.set_orientation(Gtk::Orientation (Gtk::ORIENTATION_VERTICAL));
	this->caja_blok2_rid_clerk.set_border_width(25);
	
	//inicialización del contendor de botones
	this->caja_buttons_rid_clerk.set_orientation(Gtk::Orientation (Gtk::ORIENTATION_HORIZONTAL));
	
	//inicializacion de imagenes
	this->logo_rid_clerk.set("images/logo.png");
	this->logo_rid_clerk.set_margin_bottom(25);
	
	//inicialización de los campos usuario label, entry...
	this->label_type_id_rid_clerk.set_text ("Tipo de Identificacion");
	this->label_type_id_rid_clerk.set_margin_bottom(5);
	this->label_type_id_rid_clerk.set_alignment (Gtk::ALIGN_START);
	
	this->combo_type_id_rid_clerk.append ("");
	this->combo_type_id_rid_clerk.append ("RC");	
	this->combo_type_id_rid_clerk.append ("CC");
	this->combo_type_id_rid_clerk.append ("CE");
	this->combo_type_id_rid_clerk.append ("NUIP");
	this->combo_type_id_rid_clerk.set_margin_bottom(25);
	
	this->button_delete_clerk.set_label ("Eliminar");
	this->button_delete_clerk.set_border_width(25);
	
	//inicialización de los campos usuario label, entry...
	this->label_num_id_rid_clerk.set_text("Numero de Identificacion");
	this->label_num_id_rid_clerk.set_margin_bottom(5);
	this->label_num_id_rid_clerk.set_alignment (Gtk::ALIGN_START);
	
	this->entry_num_id_rid_clerk.set_text("");
	this->entry_num_id_rid_clerk.set_margin_bottom(25);

	this->button_cancel_rid_clerk.set_label ("Cancelar");
	this->button_cancel_rid_clerk.set_border_width(25);	
	
	// empaquetado en la caja principal
	this->caja_rid_clerk.pack_start(this->caja_encabezado_rid_clerk);
	this->caja_rid_clerk.pack_start(this->grid_unit_rid_clerk);
	this->caja_rid_clerk.pack_start(this->caja_buttons_rid_clerk);

	//empaquetado en la caja que une las columnas
	this->grid_unit_rid_clerk.add(this->caja_blok1_rid_clerk);
	this->grid_unit_rid_clerk.add(this->caja_blok2_rid_clerk);

	//empaquetado del encabezado
	this->caja_encabezado_rid_clerk.pack_start(this->logo_rid_clerk);

	// empaquetado de datos del empleado
	this->caja_blok1_rid_clerk.pack_start(this->label_type_id_rid_clerk);
	this->caja_blok1_rid_clerk.pack_start(this->combo_type_id_rid_clerk);
	this->caja_blok2_rid_clerk.pack_start(this->label_num_id_rid_clerk);
	this->caja_blok2_rid_clerk.pack_start(this->entry_num_id_rid_clerk);

	// empaquetado de botones
	this->caja_buttons_rid_clerk.pack_start(this->button_delete_clerk);
	this->caja_buttons_rid_clerk.pack_start(this->button_cancel_rid_clerk);
}

void Gui_raiz::cancel_report ()
{
	this->remove ();
	this->add(this->caja_admin);
	this->show_all ();
}

void Gui_raiz::generar_reporte ()
{
	int horas_ord = 0;
	int horas_extras = 0;
	std::fstream reporte;
	
	if(this->combo_type_report.get_active_text () == "General")
	{
		for (std::list<marcacion>::iterator iterador_marcacion = marcaciones.begin (); iterador_marcacion != marcaciones.end (); ++iterador_marcacion)
		{
			horas_ord += iterador_marcacion->horas_ord;
			horas_extras += iterador_marcacion->horas_extras;
		}
		
		reporte.open ("reporte general.txt", std::ios::out);
		reporte << "Informe General" << std::endl;
		reporte << "Las horas ordinarias trabajadas son: " << horas_ord << std::endl;
		reporte << "Las horas extras trabajadas son: " << horas_extras << std::endl;
		reporte.close ();
		
	}
	else
	{	
		std::string username = this->entry_num_id_report.get_text ();
		
		for (std::list<usuario>::iterator iterador_usuario = usuarios.begin (); iterador_usuario != usuarios.end (); ++iterador_usuario)
		{
			if(username == iterador_usuario->username)
			{
				for (std::list<marcacion>::iterator iterador_marcacion = marcaciones.begin (); iterador_marcacion != marcaciones.end (); ++iterador_marcacion)
				{
					if (iterador_usuario->id == iterador_marcacion->usuario_id)
					{
						horas_ord += iterador_marcacion->horas_ord;
						horas_extras += iterador_marcacion->horas_extras;
					}
				}
				
				reporte.open ("reporte "+iterador_usuario->username, std::ios::out);
				reporte << "Informe de "+iterador_usuario->username.substr (3) << std::endl;
				reporte << "Las horas ordinarias trabajadas son: " << horas_ord << std::endl;
				reporte << "Las horas extras trabajadas son: " << horas_extras << std::endl;
				reporte.close ();
				
			}
		}
	}

}
