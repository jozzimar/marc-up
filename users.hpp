#include <iostream>
#include <string>
#include <fstream>


#ifndef INCLUDE_ACCESO_HPP
#define INCLUDE_ACCESO_HPP

class users
{
protected:
  
	std::string typeuser;
	std::string passuser;
	std::string id;
	std::string num_id;
	std::string name;
	std::string surname;
	std::string eps;
	std::string arl;
	unsigned short age;
	std::string rh;
	
public:
	users ();
	users (std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, unsigned short, std::string);
	~users ();
	
	void set_typeuser (std::string);
	std::string get_typeuser ();
	
	void set_passuser (std::string);
	std::string get_passuser ();
	
	void set_id (std::string);
	std::string get_id ();
	
	void set_num_id (std::string);
	std::string get_num_id ();
	
	void set_name (std::string);
	std::string get_name ();
	
	void set_surname (std::string);
	std::string get_surname ();
	
	void set_eps (std::string);
	std::string get_eps ();
	
	void set_arl (std::string);
	std::string get_arl ();
	
	void set_age (unsigned short);
	unsigned short get_age ();
	
	void set_rh (std::string);
	std::string get_rh ();
	
};

#endif
