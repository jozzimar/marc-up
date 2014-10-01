#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <boost/algorithm/string.hpp>

#ifndef INCLUDE_DATABASE_HPP
#define INCLUDE_DATABASE_HPP


void new_regist ();
void remove_regist ();
void edit_regist ();
void search_regist ();
void print_regist ();
void load_dates ();
void save_dates ();
int verify_document (std::string);

#endif