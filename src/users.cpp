#include "users.hpp"

users::users()
{
  
}

users::users (std::string typeuser, std::string passuser, std::string id, std::string num_id, std::string name, std::string surname, std::string eps, std::string arl, unsigned short age, std::string rh)
{
	
	this->typeuser = typeuser;
	this->passuser = passuser;
	this->id = id;
	this->num_id = num_id;
	this->name = name;
	this->surname = surname;
	this->eps = eps;
	this->arl = arl;
	this->age = age;
	this->rh = rh;
  
}
	
users::~users ()
{

}

void users::set_typeuser()
{
	std::cin >> this->typeuser;
	std::cin.get (); 
}

void users::set_typeuser (std::string typeuser)
{
	this->typeuser = typeuser;
}

std::string  users::get_typeuser ()
{
	return this->typeuser;
}

void users::set_passuser()
{
	std::cin >> this->passuser;
	std::cin.get();
}

void users::set_passuser (std::string passuser)
{
	this->passuser = passuser;
}

std::string  users::get_passuser ()
{
	return this->passuser;
}

void users::set_id();
{
	std::cin >> this->id;
	std::cin.get();
}

void users::set_id (std::string id)
{
	this->id = id;
}

std::string  users::get_id ()
{
	return this->id;
}

void users::set_num_id()
{
	std::cin >> this->num_id;
	std::cin.get();
}

void users::set_num_id (std::string num_id)
{
	this->num_id = num_id;
}

std::string  users::get_num_id ()
{
	return this->num_id;
}

void users::set_name()
{
	std::getline(std::cin, this->name);
}

void users::set_name (std::string name)
{
	this->name = name;
}

std::string  users::get_name ()
{
	return this->name;
}

void users::set_surname();
{
	std::getline(std::cin, this->surname);
}

void users::set_surname (std::string surname)
{
	this->surname = surname;
}

std::string  users::get_surname ()
{
	return this->surname;
}

void users::set_eps()
{
	std::cin >> this->eps;
	std::cin.get();
}

void users::set_eps (std::string eps)
{
	this->eps = eps;
}

std::string  users::get_eps ()
{
	return this->eps;
}

void users::set_arl()
{
	std::cin >> this->arl;
	std::cin.get();
}

void users::set_arl (std::string arl)
{
	this->arl = arl;
}

std::string  users::get_arl ()
{
	return this->arl;
}

void users::set_age()
{
	std::cin >> this->age;
	std::cin.get();
}

void users::set_age (unsigned short age)
{
	this->age = age;
}

unsigned short users::get_age ()
{
	return this->age;
}

void users::set_rh()
{
	std::cin >> this->rh;
	std::cin.get();
}

void users::set_rh (std::string rh)
{
	this->rh = rh;
}

std::string users::get_rh ()
{
	return this->rh;
}