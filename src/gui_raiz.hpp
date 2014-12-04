#ifndef MARC_UP_GUI_RAIZ_HPP
#define MARC_UP_GUI_RAIZ_HPP

#include <gtkmm/label.h>
#include <gtkmm/entry.h>
#include <gtkmm/window.h>
#include <gtkmm/image.h>
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/comboboxtext.h>
#include <gtkmm/messagedialog.h>
#include <gtkmm/grid.h>
#include <cppdb/frontend.h>


class Gui_raiz : public Gtk::Window
{
public:
	Gui_raiz ();
	virtual ~Gui_raiz ();
	
	void set_login ();
	void set_admin ();
	void set_add_clerk ();
	void layout_login ();
	void layout_add_clerk ();
	void save_add_clerk();
	void cancel_add_clerk ();
	void layout_rid_clerk ();
	void delete_clerk ();
	void cancel_rid_clerk ();
	void set_rid_clerk ();
	void layout_report ();
	void cancel_report ();
	void set_report ();
	void on_combo_clerk ();
	void generar_reporte ();
	
	void guardar_usuario();
	void eliminar_usuario();
	
protected:
	//gui login
  
	Gtk::Box caja_login;
	Gtk::Box caja_encabezado_login;
	Gtk::Box caja_usuarios;
	Gtk::Box caja_passwords;
	Gtk::Box caja_button_login;
	Gtk::Image logo_login;
	Gtk::Label usuario_label;
	Gtk::Entry usuario_entry;
	Gtk::Label password_label;
	Gtk::Entry password_entry;
	Gtk::Button button_in;
	
	//gui admin
	Gtk::Image logo_admin;
	Gtk::Box caja_images, caja_admin, caja_encabezado_admin, caja_button_admin;
	Gtk::Button button_add_clerk, button_rid_clerk, button_generate_report;
	Gtk::Image add_clerk, rid_clerk, report;
	
	//gui agregar empleado
	
	Gtk::Image logo_add_clerk;
	Gtk::Box caja_add_clerk, caja_blok1_add_clerk, caja_blok2_add_clerk, caja_buttons_add_clerk, caja_encabezado_add_clerk;
	Gtk::Grid grid_unit_add_clerk;
	Gtk::Button button_cancel_add_clerk, button_save_add_clerk;
	Gtk::Label label_type_id, label_num_id, label_name, label_surname, label_eps, label_arl, label_appointment, label_area;
	Gtk::Entry entry_num_id, entry_name, entry_surname, entry_eps, entry_arl,entry_contra; 
	Gtk::ComboBoxText combo_type_id, combo_appointment; 

	//gui eliminar empleado
	
	Gtk::Image logo_rid_clerk;
	Gtk::Box caja_rid_clerk, caja_encabezado_rid_clerk, caja_blok1_rid_clerk, caja_blok2_rid_clerk, caja_buttons_rid_clerk;
	Gtk::Grid grid_unit_rid_clerk;
	Gtk::Button button_delete_clerk, button_cancel_rid_clerk;	
	Gtk::Label label_num_id_rid_clerk, label_type_id_rid_clerk;
	Gtk::Entry entry_num_id_rid_clerk;
	Gtk::ComboBoxText combo_type_id_rid_clerk;
	
	//gui informes

	Gtk::Image logo_report;
	Gtk::Box caja_report, caja_type_report, caja_encabezado_report, caja_buttons_report;
	Gtk::Button button_generate, button_cancel_report;
	Gtk::Label label_type_report, label_num_id_report;
	Gtk::ComboBoxText combo_type_report;	
	Gtk::Entry entry_num_id_report;
	
	cppdb::session session;
	
};

#endif //MARC-UP_GUI_RAIZ_HPP
