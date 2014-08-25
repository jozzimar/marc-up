#include "gui_raiz.hpp"
#include <iostream>

Gui_raiz::Gui_raiz ()
  
{
	this->caja_principal.set_orientation(Gtk::Orientation (Gtk::ORIENTATION_VERTICAL));
	this->caja_encabezado.set_orientation(Gtk::Orientation (Gtk::ORIENTATION_HORIZONTAL));
	this->caja_usuarios.set_orientation(Gtk::Orientation (Gtk::ORIENTATION_VERTICAL));
	this->caja_passwords.set_orientation(Gtk::Orientation (Gtk::ORIENTATION_VERTICAL));
	this->logo.set("media_commerce.png");
	this->titulo_app.set_text ("Media Commerce\nMarc-Up");
	this->usuario_label.set_text ("Usuario");
	this->usuario_entry.set_text("");
	this->password_label.set_text("Contraseña");
	this->password_entry.set_text("");
	
	this->add(caja_principal);
	this->caja_principal.pack_start(caja_encabezado);
	this->caja_principal.pack_start(caja_usuarios);	
	this->caja_principal.pack_start(caja_passwords);
	this->caja_encabezado.pack_start(logo);
	this->caja_encabezado.pack_start(titulo_app);
	this->caja_usuarios.pack_start(this->usuario_label);
	this->caja_usuarios.pack_start(this->usuario_entry);
	this->caja_passwords.pack_start(this->password_label);
	this->caja_passwords.pack_start(this->password_entry);	
	//sets the borde width of the window
	this->set_border_width ( 10 );

	this->set_default_size (600,400);
	this->set_title ("Media Commerce_Marc-up");
	this->show_all_children ();
}

Gui_raiz::~Gui_raiz ()
{
}


