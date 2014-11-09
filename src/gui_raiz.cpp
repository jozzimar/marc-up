#include "gui_raiz.hpp"
#include <iostream>

Gui_raiz::Gui_raiz ()
  
{

	this->button_save.signal_clicked ().connect (sigc::mem_fun (*this, &Gui_raiz::dialog_save) );
	this->button_delete.signal_clicked ().connect (sigc::mem_fun (*this, &Gui_raiz::dialog_delete) );
	this->combo_type_report.signal_changed().connect( sigc::mem_fun(*this,&Gui_raiz::on_combo_clerk) );
	
	/*this->set_login();
	this->add(this->caja_login);*/
	
	/*this->set_admin();
	this->add(this->caja_admin);*/
	
	this->set_add_clerk();
	this->add(this->caja_add_clerk);

	/*this->set_rid_clerk();
	this->add(this->caja_rid_clerk);*/

	/*this->set_report();
	this->add(this->caja_report);*/
	
	this->set_resizable(false);
	this->set_position (Gtk::WIN_POS_CENTER);
	this->set_border_width (20);
	this->set_title ("Marc Up");
	this->show_all ();
	
	//this->caja_add_clerk.hide();
}

Gui_raiz::~Gui_raiz ()
{
}

void Gui_raiz::set_login()
{
	//inicialización del contenedor principal
	this->caja_login.set_orientation(Gtk::Orientation (Gtk::ORIENTATION_VERTICAL));
	
	//inicialización del contenedor del logo
	this->caja_encabezado.set_orientation(Gtk::Orientation (Gtk::ORIENTATION_HORIZONTAL));
	
	//inicialización del contenedor campo usuario
	this->caja_usuarios.set_orientation(Gtk::Orientation (Gtk::ORIENTATION_VERTICAL));
	
	//inicialización del contenedor campo contraseña
	this->caja_passwords.set_orientation(Gtk::Orientation (Gtk::ORIENTATION_VERTICAL));
	
	//inicialización de el image con el logo
	this->logo.set("images/logo.png");
	
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
	this->caja_login.pack_start(this->caja_encabezado);
	this->caja_login.pack_start(this->caja_usuarios);	
	this->caja_login.pack_start(this->caja_passwords);
	this->caja_login.pack_start(this->caja_button);

	//empaquetado del encabezado
	this->caja_encabezado.pack_start(this->logo);

	//empaquetado de los campos usuario
	this->caja_usuarios.set_spacing (0);
	this->caja_usuarios.pack_start(this->usuario_label);
	this->caja_usuarios.pack_start(this->usuario_entry);

	//empaquetado de los campos password
	this->caja_passwords.pack_start(this->password_label);
	this->caja_passwords.pack_start(this->password_entry);
	
	this->caja_button.pack_end(this->button_in, Gtk::PACK_SHRINK);
}


void Gui_raiz::set_admin()
{
	//inicialización del contenedor principal
	this->caja_admin.set_orientation(Gtk::Orientation (Gtk::ORIENTATION_VERTICAL));
	
	//inicialización del contenedor del logo
	this->caja_encabezado.set_orientation(Gtk::Orientation (Gtk::ORIENTATION_HORIZONTAL));
	
	//inicializacion de contenedor imagenes y botones
	this->caja_button.set_orientation(Gtk::Orientation (Gtk::ORIENTATION_HORIZONTAL));
	this->caja_images.set_orientation(Gtk::Orientation (Gtk::ORIENTATION_HORIZONTAL));
	
	//inicializacion de imagenes
	this->logo.set("images/logo.png");
	this->logo.set_margin_bottom(25);
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
	this->caja_admin.pack_start(this->caja_encabezado);
	this->caja_admin.pack_start(this->caja_images);
	this->caja_admin.pack_start(this->caja_button);
	
	//empaquetado del encabezado
	this->caja_encabezado.pack_start(this->logo);

	//empaquetado de los button
	this->caja_button.set_spacing (0);
	this->caja_button.pack_start(this->button_add_clerk);
	this->caja_button.pack_start(this->button_rid_clerk);
	this->caja_button.pack_start(this->button_generate_report);
	
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
	this->caja_encabezado.set_orientation(Gtk::Orientation (Gtk::ORIENTATION_HORIZONTAL));
	
	// inicializacion de contenedor columnas
	this->caja_blok1.set_orientation(Gtk::Orientation (Gtk::ORIENTATION_VERTICAL));
	this->caja_blok1.set_border_width(25);
	this->caja_blok2.set_orientation(Gtk::Orientation (Gtk::ORIENTATION_VERTICAL));
	this->caja_blok2.set_border_width(25);
	this->caja_buttons.set_orientation (Gtk::Orientation(Gtk::ORIENTATION_HORIZONTAL));
	
	//inicializacion de imagenes
	this->logo.set("images/logo.png");
	this->logo.set_margin_bottom(25);
	
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
	
	this->button_save.set_label ("Save");
	this->button_save.set_border_width(25);
	
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

	this->label_area.set_text("Area");
	//this->label_area.set_margin_bottom(5);
	this->label_area.set_alignment (Gtk::ALIGN_START);
	this->combo_area.set_margin_bottom(25);
	this->combo_area.append("");
	this->combo_area.append("P.E. Aguachica");	
	
	
	this->button_cancel.set_label ("Cancel");
	this->button_cancel.set_border_width(25);

	// empaquetado en la caja principal
	this->caja_add_clerk.pack_start(this->caja_encabezado);
	this->caja_add_clerk.pack_start(this->grid_unit);
	this->caja_add_clerk.pack_start(this->caja_buttons);
	
	//empaquetado en la caja que une las columnas
	this->grid_unit.add(this->caja_blok1);
	this->grid_unit.add(this->caja_blok2);
	
	//empaquetado del encabezado
	this->caja_encabezado.pack_start(this->logo);
	
	//empaquetado del bloque 1
	this->caja_blok1.pack_start(this->label_type_id);
	this->caja_blok1.pack_start(this->combo_type_id);
	
	this->caja_blok1.pack_start(this->label_name);
	this->caja_blok1.pack_start(this->entry_name);
	
	this->caja_blok1.pack_start(this->label_eps);
	this->caja_blok1.pack_start(this->entry_eps);
	
	this->caja_blok1.pack_start(this->label_appointment);
	this->caja_blok1.pack_start(this->combo_appointment);
	
	//empaquetado del bloque 2
	this->caja_blok2.pack_start(this->label_num_id);
	this->caja_blok2.pack_start(this->entry_num_id);
	
	this->caja_blok2.pack_start(this->label_surname);
	this->caja_blok2.pack_start(this->entry_surname);
	
	this->caja_blok2.pack_start(this->label_arl);
	this->caja_blok2.pack_start(this->entry_arl);

	this->caja_blok2.pack_start(this->label_area);
	this->caja_blok2.pack_start(this->combo_area);
	
	// empaquetado de botones
	this->caja_buttons.pack_start(this->button_save);
	this->caja_buttons.pack_end(this->button_cancel);
	
}

void Gui_raiz::dialog_save ()
{
	Gtk::MessageDialog messagedialog_save(*this,"¿DESEA ALMACENAR LOS DATOS DEL EMPLEADO?", false, Gtk::MESSAGE_QUESTION, Gtk::BUTTONS_OK_CANCEL);
	messagedialog_save.set_secondary_text ("Si los datos suministrados son correctos pulse Aceptar.");
	
	int result = messagedialog_save.run ();
	
	switch (result)
	{
		case (Gtk::RESPONSE_OK):
			std::cout << "Aceptar" << std::endl;
			break;		
			
		case (Gtk::RESPONSE_CANCEL):
			std::cout << "Cancelar" << std::endl;
			break;
			
		default:
			std::cout << "Nunca Pasa" << std::endl;
			break;
	}
}

void Gui_raiz::set_report ()
{
	//contenedor principal
	this->caja_report.set_orientation(Gtk::Orientation (Gtk::ORIENTATION_VERTICAL));
	
	//inicialización del contenedor del logo
	this->caja_encabezado.set_orientation(Gtk::Orientation (Gtk::ORIENTATION_HORIZONTAL));
	
	//inicializacion del contenedor tipo reporte
	this->caja_type_report.set_orientation(Gtk::Orientation (Gtk::ORIENTATION_VERTICAL));		
	
	//inicialización del contendor de botones
	this->caja_buttons.set_orientation(Gtk::Orientation (Gtk::ORIENTATION_HORIZONTAL));
	
	//inicializacion de imagenes
	this->logo.set("images/logo.png");
	this->logo.set_margin_bottom(25);
	
	//inicialización de los campos usuario label, entry...
	this->label_type_report.set_text ("Tipo de Informe");
	this->label_type_report.set_margin_bottom(5);
	this->label_type_report.set_alignment (Gtk::ALIGN_START);
	this->combo_type_report.append ("");
	this->combo_type_report.append ("General");	
	this->combo_type_report.append ("Individual");
	this->combo_type_report.set_margin_bottom(25);

	this->label_num_id.set_text("Numero de Identificacion");
	this->label_num_id.set_margin_bottom(5);
	this->label_num_id.set_alignment (Gtk::ALIGN_START);
	this->entry_num_id.set_text("");
	this->entry_num_id.set_can_focus(false);
	this->entry_num_id.set_margin_bottom(25);
		
	this->button_generate.set_label ("Generar Reporte");
	this->button_generate.set_border_width(25);
	
	this->button_cancel.set_label ("Cancelar");
	this->button_cancel.set_border_width(25);

	// empaquetado en la caja principal
	this->caja_report.pack_start(this->caja_encabezado);
	this->caja_report.pack_start(this->caja_type_report);
	this->caja_report.pack_start(this->caja_buttons);
	
	//empaquetado del encabezado
	this->caja_encabezado.pack_start(this->logo);
	
	//empquetado de datos
	this->caja_type_report.pack_start(this->label_type_report);
	this->caja_type_report.pack_start(this->combo_type_report);
	this->caja_type_report.pack_start(this->label_num_id);
	this->caja_type_report.pack_start(this->entry_num_id);

	// empaquetado de botones
	this->caja_buttons.pack_start(this->button_generate);
	this->caja_buttons.pack_start(this->button_cancel);
}

void Gui_raiz::on_combo_clerk()
{
	Glib::ustring text = combo_type_report.get_active_text();
	if(text=="Individual")
		this->entry_num_id.set_can_focus(true);
		
		else
			this->entry_num_id.set_can_focus(false);
}



void Gui_raiz::dialog_delete ()
{
	Gtk::MessageDialog messagedialog_delete(*this,"¿CONFIRMA QUE DESEA ELIMINAR AL EMPLEADO?", false, Gtk::MESSAGE_QUESTION, Gtk::BUTTONS_OK_CANCEL);
	messagedialog_delete.set_secondary_text ("Si los datos son correctos pulse Aceptar.");
	
	int result = messagedialog_delete.run ();
	
	switch (result)
	{
		case (Gtk::RESPONSE_OK):
			std::cout << "Aceptar" << std::endl;
			break;		
			
		case (Gtk::RESPONSE_CANCEL):
			std::cout << "Cancelar" << std::endl;
			break;
			
		default:
			std::cout << "Nunca Pasa" << std::endl;
			break;
	}
}

void Gui_raiz::set_rid_clerk ()
{
	//contenedor principal
	this->caja_rid_clerk.set_orientation(Gtk::Orientation (Gtk::ORIENTATION_VERTICAL));
	
	//inicialización del contenedor del logo
	this->caja_encabezado.set_orientation(Gtk::Orientation (Gtk::ORIENTATION_HORIZONTAL));	
	
	this->caja_blok1.set_orientation(Gtk::Orientation (Gtk::ORIENTATION_VERTICAL));
	this->caja_blok1.set_border_width(25);
	this->caja_blok2.set_orientation(Gtk::Orientation (Gtk::ORIENTATION_VERTICAL));
	this->caja_blok2.set_border_width(25);
	
	//inicialización del contendor de botones
	this->caja_buttons.set_orientation(Gtk::Orientation (Gtk::ORIENTATION_HORIZONTAL));
	
	//inicializacion de imagenes
	this->logo.set("images/logo.png");
	this->logo.set_margin_bottom(25);
	
	//inicialización de los campos usuario label, entry...
	this->label_type_id.set_text ("Tipo de Identificacion");
	this->label_type_id.set_margin_bottom(5);
	this->label_type_id.set_alignment (Gtk::ALIGN_START);
	this->combo_type_id.append ("");
	this->combo_type_id.append ("RC");	
	this->combo_type_id.append ("CC");
	this->combo_type_id.append ("CE");
	this->combo_type_id.append ("NUIP");
	this->combo_type_id.set_margin_bottom(25);
	
	this->button_delete.set_label ("Eliminar");
	this->button_delete.set_border_width(25);
	
	//inicialización de los campos usuario label, entry...
	this->label_num_id.set_text("Numero de Identificacion");
	this->label_num_id.set_margin_bottom(5);
	this->label_num_id.set_alignment (Gtk::ALIGN_START);
	this->entry_num_id.set_text("");
	this->entry_num_id.set_margin_bottom(25);

	this->button_cancel.set_label ("Cancelar");
	this->button_cancel.set_border_width(25);	
	
	// empaquetado en la caja principal
	this->caja_rid_clerk.pack_start(this->caja_encabezado);
	this->caja_rid_clerk.pack_start(this->grid_unit);
	this->caja_rid_clerk.pack_start(this->caja_buttons);

	//empaquetado en la caja que une las columnas
	this->grid_unit.add(this->caja_blok1);
	this->grid_unit.add(this->caja_blok2);

	//empaquetado del encabezado
	this->caja_encabezado.pack_start(this->logo);

	// empaquetado de datos del empleado
	this->caja_blok1.pack_start(this->label_type_id);
	this->caja_blok1.pack_start(this->combo_type_id);

	this->caja_blok2.pack_start(this->label_num_id);
	this->caja_blok2.pack_start(this->entry_num_id);

	// empaquetado de botones
	this->caja_buttons.pack_start(this->button_delete);
	this->caja_buttons.pack_start(this->button_cancel);
}
