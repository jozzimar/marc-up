#include "gui_raiz.hpp"
#include <iostream>

Gui_raiz::Gui_raiz ()
  
{
	//inicialización del contenedor principal
	this->caja_principal.set_orientation(Gtk::Orientation (Gtk::ORIENTATION_VERTICAL));
	//inicialización del contenedor del logo
	this->caja_encabezado.set_orientation(Gtk::Orientation (Gtk::ORIENTATION_HORIZONTAL));
	//inicialización del contenedor campo usuario
	this->caja_usuarios.set_orientation(Gtk::Orientation (Gtk::ORIENTATION_VERTICAL));
	//inicialización del contenedor campo contraseña
	this->caja_passwords.set_orientation(Gtk::Orientation (Gtk::ORIENTATION_VERTICAL));
	//inicialización de el image con el logo
	this->logo.set("logo.png");
	
	//inicialización de los campos usuario label y entry
	this->usuario_label.set_text ("Usuario");
	this->usuario_label.set_alignment (Gtk::ALIGN_START);
	this->usuario_entry.set_text("");
	this->password_entry.set_visibility (false);
	this->password_label.set_text("Contraseña");
	this->password_label.set_alignment (Gtk::ALIGN_START);
	this->password_entry.set_text("");
	
	//empaquetado del contenedor principal	
	this->caja_principal.pack_start(caja_encabezado);
	this->caja_principal.pack_start(caja_usuarios);	
	this->caja_principal.pack_start(caja_passwords);

	//empaquetado del encabezado
	this->caja_encabezado.pack_start(logo);

	//empaquetado de los campos usuario
	this->caja_usuarios.pack_start(this->usuario_label);
	this->caja_usuarios.pack_start(this->usuario_entry);

	//empaquetado de los campos password
	this->caja_passwords.pack_start(this->password_label);
	this->caja_passwords.pack_start(this->password_entry);

	//inicialización de la ventana principal
	this->add(caja_principal);
	this->set_default_size (300,300);
	this->set_position (Gtk::WIN_POS_CENTER);
	this->set_border_width (20);
	this->set_title ("Marc Up");
	this->show_all ();
}

Gui_raiz::~Gui_raiz ()
{
}


