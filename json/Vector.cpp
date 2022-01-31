#include "Vector.h"

using namespace jsonTools;


Vector::Vector() {
	this->collection = new UList<Item*>();
}


Vector::~Vector() {
	this->Clear();
	delete this->collection;
}

void Vector::Clear() {
	auto item = collection->GetFirst();
	while (item != NULL) {
		auto elem = item->Item();
		if (elem != NULL) {
			delete elem;
		}
		item = item->Next();
	}
	this->collection->Clear();
}


int Vector::Count() {
	if (this->collection != NULL) {
		return this->collection->Count();
	}
	return 0;
}

void Vector::Add(std::string name, Vector* vector) {
	if (vector != NULL) {
		this->collection->Add((new Item(name, vector->Serialize(), true)));
	}
}

void Vector::Add(Item* jsonItem, bool addAny) {
	if (addAny || !this->checkDouble(jsonItem) || jsonItem->GetVar()->IsArray()) {
		this->collection->Add(jsonItem);
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
	auto item = collection->GetFirst();
	while (item != NULL) {
		if (item->Item() != NULL && jsonItem->GetVar()->Name().length() > 0 && 
			item->Item()->GetVar()->Name() == jsonItem->GetVar()->Name()) {
			return item->Item();
		}
		item = item->Next();
	}
	return NULL;
}
Item* Vector::Get(std::string nameVar) {
	auto item = collection->GetFirst();
	while (item != NULL) {
		if (item->Item()->GetVar()->Name() == nameVar) {
			return item->Item();
		}
		item = item->Next();
	}
	return NULL;
}

std::string Vector::Serialize() {
	bool isArray = false;
	std::string result = "";
	if (collection->Count() == 0) {
		return result;
	}
	auto item = collection->GetFirst();
	while (item != NULL) {
		if (item->Item()->GetVar()->IsArray()) {
			isArray = true;
		}
		item = item->Next();
	}
	item = collection->GetFirst();
	while (item != NULL) {
		if (!result.empty()) {
			result = item->Item()->Serialization(isArray) + ", " + result;
		}
		else {
			result = item->Item()->Serialization(isArray);
		}
		item = item->Next();
	}
	if (isArray) {
		return "[ " + result + " ]";
	}
	delete item;
	return "{ " + result + " }";
}