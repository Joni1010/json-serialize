#include "Var.h"

using namespace jsonTools;


void Var::defineType() {

}

int Var::GetType() {
	return this->type;
}

void Var::SetName(std::string name) {
	this->array = name.length() == 0 ? true : false;
	this->name = name;
}

std::string Var::Name() {
	return this->name;
}

bool Var::IsArray() {
	return this->array;
}