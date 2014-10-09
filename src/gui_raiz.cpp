#include "gui_raiz.hpp"
#include <iostream>

Gui_raiz::Gui_raiz ()
  
{
	
	/*this->set_login();
	this->add(this->caja_login);*/
	
	/*this->set_admin();
	this->add(this->caja_admin);*/
	
	this->set_add_clerk();
	this->add(this->caja_add_clerk);
	
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
	this->button_add_clerk.set_label("ADD CLERK");
	this->button_add_clerk.set_border_width(10);
	this->button_rid_clerk.set_label("RID CLERK");
	this->button_rid_clerk.set_border_width(10);
	
	this->button_generate_report.set_label("GENERATE REPORT");
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
	
	this->label_rh.set_text("Rh");
	this->label_rh.set_alignment (Gtk::ALIGN_START);
	this->entry_rh.set_text("");
	this->entry_rh.set_margin_bottom(25);
	
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
	this->entry_arl.set_margin_bottom(90);
	
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
	
	this->caja_blok1.pack_start(this->label_rh);
	this->caja_blok1.pack_start(this->entry_rh);
	
	//empaquetado del bloque 2
	this->caja_blok2.pack_start(this->label_num_id);
	this->caja_blok2.pack_start(this->entry_num_id);
	
	this->caja_blok2.pack_start(this->label_surname);
	this->caja_blok2.pack_start(this->entry_surname);
	
	this->caja_blok2.pack_start(this->label_arl);
	this->caja_blok2.pack_start(this->entry_arl);
	
	// empaquetado de botones
	this->caja_buttons.pack_start(this->button_save);
	this->caja_buttons.pack_end(this->button_cancel);
	
}

void Gui_raiz::set_dialog_save()
{
	this->messagedialog_save("DESEA ALMACENAR DATOS DEL EMPLEADO?", false /*use_markup*/, Gtk::MESSAGE_QUESTION,Gtk::BUTTONS_OK_CANCEL);
	this->messagedialog_save.set_secondary_text("Si esta seguro de la información suministrada presione OK.");
	
	 int result_clicked = messagedialog.run();

	switch(result_clicked){
		case(Gtk::RESPONSE_OK):
			{
			std::cout << "OK clicked." << std::endl;
      		break;
		}
    		case(Gtk::RESPONSE_CANCEL):
			{
			std::cout << "Cancel clicked." << std::endl;
         	break;
    		}
		default:
    			{
      			std::cout << "Unexpected button clicked." << std::endl;
      		break;
    		}
	}
}


