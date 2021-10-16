#include "Vector.h"

using namespace jsonTools;


Vector::Vector() {
	this->collection = new std::list<Item*>();
}


Vector::~Vector() {
	this->Clear();
	delete this->collection;
}

void Vector::Clear() {
	this->collection->clear();
}


void Vector::Add(Item* jsonItem) {
	if (!this->checkDouble(jsonItem) || jsonItem->GetVar()->IsArray()) {
		this->collection->push_front(jsonItem);
	}
}

bool Vector::checkDouble(Item* jsonItem) {
	auto val = this->Get(jsonItem);
	if (val != NULL) {
		return true;
	}
	return false;
}

Item* Vector::Get(Item* jsonItem) {
	for (std::list<Item*>::iterator i = this->collection->begin(); i != this->collection->end(); ++i) {
		auto val = i._Ptr->_Myval;
		if (val != NULL && val->GetVar()->Name() == jsonItem->GetVar()->Name()) {
			return val;
		}
	}
}
Item* Vector::Get(std::string nameVar) {
	for (std::list<Item*>::iterator i = this->collection->begin(); i != this->collection->end(); ++i) {
		auto val = i._Ptr->_Myval;
		if (val->GetVar()->Name() == nameVar) {
			return val;
		}
	}
}

std::string Vector::Serialize() {
	bool isArray = false;
	std::string result = "";
	for (std::list<Item*>::iterator i = this->collection->begin(); i != this->collection->end(); ++i) {
		auto val = i._Ptr->_Myval;
		if (val->GetVar()->IsArray()) {
			isArray = true;
		}
	}
	for (std::list<Item*>::iterator i = this->collection->begin(); i != this->collection->end(); ++i) {
		auto val = i._Ptr->_Myval;
		if (result != "") {
			result = val->Serialization(isArray) + ", " + result;
		}
		else {
			result = val->Serialization(isArray);
		}
	}
	if (isArray) {
		return "[ " + result + " ]";
	} 
	return "{ " + result + " }";
}