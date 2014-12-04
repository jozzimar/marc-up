#ifndef MARC_UP_MARCACION_HPP
#define MARC_UP_MARCACION_HPP

#include <gtkmm.h>
#include <iostream>
#include <ctime>
#include <cppdb/frontend.h>

class Marcacion : public Gtk::Window
{
public:
	Marcacion ();
	~Marcacion ();
private:
  

  	bool key_enter (GdkEventKey* event);
  	void set_mark_clerk ();
  	bool reset_label_marcacion (int);
			
protected:

	Gtk::Box caja_program;
	Gtk::Box caja_image;
	Gtk::Box caja_type_and_users;
	Gtk::Image logo;
	Gtk::Label label_marker_register;
	Gtk::Label label_id_clerk;
	Gtk::Entry entry_id_clerk;
	
	cppdb::session session;
	std::string username;
	std::string password;
};

#endif //MARC-UP_MARCACION_HPP
