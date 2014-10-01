#include "dataBase.hpp"
#include "users.hpp"

std::vector<std::string> registro;

std::list<users> user;

void new_regist()
{
	if (users.size () == 0)
	{	load_dates (); }
	
	users new_user;

	std::cout << "Ingrese el número de cédula:" << std::endl;
	
	new_user.set_num_id ();
	
	if (verificar_cedula (nueva_persona.get_cc ()) == 0)
	{
		std::cout << "Ingrese el nombre completo:" << std::endl;
		nueva_persona.set_nombre ();
		
		std::cout << "Ingrese la edad:" << std::endl;
		nueva_persona.set_edad ();
		
		personas.push_back (nueva_persona);
		
		guardar_datos ();
	}
	else
	{
		std::cout << "Hay un usuario registrado con ese número de cédula" << std::endl;
	}
}