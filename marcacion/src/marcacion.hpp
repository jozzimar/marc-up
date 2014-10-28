#ifndef MARC_UP_MARCACION_HPP
#define MARC_UP_MARCACION_HPP

#include <gtkmm/label.h>
#include <gtkmm/entry.h>
#include <gtkmm/window.h>
#include <gtkmm/image.h>
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/comboboxtext.h>
#include <gtkmm/messagedialog.h>
#include <gtkmm/grid.h>


class Marcacion : public Gtk::Window
{
public:
	Marcacion ();
	virtual ~Marcacion ();
private:
  
  	//virtual bool on_key_press_event(GdkEventKey* event);
  	//bool entryKeypress(GdkEventKey* event);
  	
  	void set_mark_clerk();
	
		
protected:
	  
	Gtk::Box caja_program;
	Gtk::Box caja_image;
	Gtk::Box caja_type_and_users;
	Gtk::Image logo;
	Gtk::Label label_type_marker;
	Gtk::ComboBoxText combo_type_marker;
	Gtk::Label label_id_clerk;
	Gtk::Entry entry_id_clerk;
	Gtk::Label label_code_clerk;
	Gtk::Entry entry_code_clerk;
	Gtk::Button button_register;
	
};

#endif //MARC-UP_MARCACION_HPP
