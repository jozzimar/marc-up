#include "users.hpp"

users::users()
{
  
}

users::users (unsigned int id, std::string type_user, std::string password_user, std::string type_id, std::string number_id, std::string name, std::string surname, std::string eps, std::string arl, std::string cargo, std::string contra)
{
	this->id=id;
	this->type_user = type_user;
	this->password_user = password_user;
	this->type_id = type_id;
	this->number_id = number_id;
	this->name = name;
	this->surname = surname;
	this->eps = eps;
	this->arl = arl;
	this->cargo = cargo;
	this->contra = contra;
  
}
	
users::~users ()
{

}


