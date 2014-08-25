#ifndef MARC_UP_GUI_RAIZ_HPP
#define MARC_UP_GUI_RAIZ_HPP

#include <gtkmm/label.h>
#include <gtkmm/entry.h>
#include <gtkmm/window.h>
#include <gtkmm/image.h>
#include <gtkmm/box.h>


class Gui_raiz : public Gtk::Window
{
public:
	Gui_raiz ();
	virtual ~Gui_raiz ();

protected:
	
	Gtk::Box caja_principal;
	Gtk::Box caja_encabezado;
	Gtk::Box caja_usuarios;
	Gtk::Box caja_passwords;
	Gtk::Image logo;
	Gtk::Label titulo_app;
	Gtk::Label usuario_label;
	Gtk::Entry usuario_entry;
	Gtk::Label password_label;
	Gtk::Entry password_entry;
};

#endif //MARC-UP_GUI_RAIZ_HPP
