#include "gui_raiz.hpp"
#include <gtkmm/application.h>

int main ( int argc, char *argv[] )
{
  
  // todo listo para trabajar
  Glib::RefPtr<Gtk::Application> app = Gtk::Application::create (argc, argv, "org.gtkmm.example");
	
	Gui_raiz gui;
	
	return app->run ( gui );
}
