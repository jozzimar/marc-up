#ifndef MARC-UP_GUI_RAIZ_HPP
#define MARC-UP_GUI_RAIZ_HPP

#include <gtkmm/button.h>
#include <gtkmm/frame.h>
#include <gtkmm/window.h>

class Gui_raiz : public Gtk::Window
{
public:
	Gui_raiz ();
	virtual ~Gui_raiz ();

protected:
	//signal handlers:
	void on_button_clicked ();
	Gtk::Frame m_frame;
	Gtk::Button m_button;
};

#endif //MARC-UP_GUI_RAIZ_HPP
