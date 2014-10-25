#include "marcacion.hpp"
#include <gtkmm/application.h>

int main ( int argc, char *argv[] )
{
  
  // todo listo para trabajar
  Glib::RefPtr<Gtk::Application> app = Gtk::Application::create (argc, argv, "org.gtkmm.example");
	
	Marcacion gui_marcacion;
	
	return app->run ( gui_marcacion );
}
