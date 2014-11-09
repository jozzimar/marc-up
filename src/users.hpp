#include <iostream>
#include <string>
#include <fstream>


#ifndef INCLUDE_USERS_HPP
#define INCLUDE_USERS_HPP

class users
{
public:
  
	std::string type_user;
	std::string password_user;
	
	std::string type_id;
	std::string number_id;
	std::string name;
	std::string surname;
	std::string eps;
	std::string arl;
	std::string cargo;
	std::string area;
		
	users ();
	
	users (std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string);
	
	~users ();
	
};

#endif
