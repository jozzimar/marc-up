#include "gui_raiz.hpp"
#include <iostream>

Gui_raiz::Gui_raiz ()
{
	this->m_frame.set_label ("Usuario");
	this->m_frame.set_label_align (Gtk::ALIGN_START);
	this->m_frame.set_shadow_type (Gtk::SHADOW_ETCHED_IN);
	
	this->m_button.set_label ("Click me");
	
	//sets the borde width of the window
	this->set_border_width ( 10 );

	//when the button receives the "clicked" signal it will call the on_button_clicked () method defined bellow
	this->m_button.signal_clicked ().connect (sigc::mem_fun ( *this, &Gui_raiz::on_button_clicked ) );

	//pack the button into the window
	this->m_frame.add ( this->m_button );

	this->set_default_size (200,200);
	this->set_title ("Media Commerce_Marc-up");
	this->add (this->m_frame);
	this->show_all_children ();
}

Gui_raiz::~Gui_raiz ()
{
}

void Gui_raiz::on_button_clicked ()
{
	std::cout << "Hola mundo!" << std::endl;
}
