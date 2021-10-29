#include "Item.h"
#include <json\Vector.h>

using namespace jsonTools;

Item::Item() {
}
Item::~Item() {
	if (this->item != NULL) {
		Var* var = this->GetVar();
		if (var->GetType() == Types::INT) {
			delete (VarJSON<int>*)item;
		}
		else if (var->GetType() == Types::INT8) {
			delete (VarJSON<__int8>*)item;
		}
		else if (var->GetType() == Types::INT16) {
			delete (VarJSON<__int16>*)item;
		}
		else if (var->GetType() == Types::INT64) {
			delete (VarJSON<__int64>*)item;
		}
		else if (var->GetType() == Types::FLOAT) {
			delete (VarJSON<float>*)item;
		}
		else if (var->GetType() == Types::LONG) {
			delete (VarJSON<long>*)item;
		}
		else if (var->GetType() == Types::BOOL) {
			delete (VarJSON<bool>*)item;
		}
		else if (var->GetType() == Types::DOUBLE) {
			delete (VarJSON<double>*)item;
		}
		else if (var->GetType() == Types::STRING) {
			delete (VarJSON<std::string>*)item;
		}
	}
}
Item::Item(std::string name, int value) {
	this->Set(name, value);
}
Item::Item(std::string name, __int8 value) {
	this->Set(name, value);
}
Item::Item(std::string name, __int16 value) {
	this->Set(name, value);
}
Item::Item(std::string name, __int64 value) {
	this->Set(name, value);
}
Item::Item(std::string name, long value) {
	this->Set(name, value);
}
Item::Item(std::string name, float value) {
	this->Set(name, value);
}
Item::Item(std::string name, double value) {
	this->Set(name, value);
}
Item::Item(std::string name, std::string value) {
	this->Set(name, value);
}

Item::Item(int value) {
	this->Set("", value);
}
Item::Item(__int8 value) {
	this->Set("", value);
}
Item::Item(__int16 value) {
	this->Set("", value);
}
Item::Item(__int64 value) {
	this->Set("", value);
}
Item::Item(long value) {
	this->Set("", value);
}
Item::Item(float value) {
	this->Set("", value);
}
Item::Item(double value) {
	this->Set("", value);
}
Item::Item(std::string value) {
	this->Set("", value);
}

void Item::Set(std::string name, int value) {
	this->item = new VarJSON<int>(name, value);
}
void Item::Set(std::string name, __int8 value) {
	this->item = new VarJSON<__int8>(name, value);
}
void Item::Set(std::string name, __int16 value) {
	this->item = new VarJSON<__int16>(name, value);
}
void Item::Set(std::string name, __int64 value) {
	this->item = new VarJSON<__int64>(name, value);
}
void Item::Set(std::string name, long value) {
	this->item = new VarJSON<long>(name, value);
}
void Item::Set(std::string name, float value) {
	this->item = new VarJSON<float>(name, value);
}
void Item::Set(std::string name, double value) {
	this->item = new VarJSON<double>(name, value);
}
void Item::Set(std::string name, std::string value) {
	this->item = new VarJSON<std::string>(name, value);
}
Item* Item::SetVector() {
	this->vector = true;
	return this;
}


std::string Item::serializationName() {
	if (this->item != NULL) {
		Var* var = (Var*)this->item;
		if (var->Name().length() > 0) {
			return "\"" + var->Name() + "\": ";
		}
	}
	return "";
}

Var* Item::GetVar() {
	return this->item != NULL ? (Var*)this->item : NULL;
}

std::string Item::serializationValue() {
	Var* var = this->GetVar();
	if (var->GetType() == Types::INT) {
		return std::to_string(((VarJSON<int>*) this->item)->Value());
	}
	else if (var->GetType() == Types::INT8) {
		return std::to_string(((VarJSON<__int8>*) this->item)->Value());
	}
	else if (var->GetType() == Types::INT16) {
		return std::to_string(((VarJSON<__int16>*) this->item)->Value());
	}
	else if (var->GetType() == Types::INT64) {
		return std::to_string(((VarJSON<__int64>*) this->item)->Value());
	}
	else if (var->GetType() == Types::FLOAT) {
		return std::to_string(((VarJSON<float>*) this->item)->Value());
	}
	else if (var->GetType() == Types::LONG) {
		return std::to_string(((VarJSON<long>*) this->item)->Value());
	}
	else if (var->GetType() == Types::BOOL) {
		return ((VarJSON<bool>*) this->item)->Value() ? "true" : "false";
	}
	else if (var->GetType() == Types::DOUBLE) {
		return std::to_string(((VarJSON<double>*) this->item)->Value());
	}
	else if (var->GetType() == Types::STRING) {
		std::string value = ((VarJSON<std::string>*) this->item)->Value();
		if (this->vector) {
			return value;
		}
		else {
			return "\"" + replaceSimbols(value) + "\"";
		}
	}
	else if (var->GetType() == Types::VECTOR) {
		return ((VarJSON<Vector*>*) this->item)->Value()->Serialize();
	}
	return "";
}
std::string Item::Serialization(bool isArray) {
	return (isArray ? "" : this->serializationName()) + this->serializationValue();
}

std::string Item::replaceSimbols(std::string content) {
	std::string result = "";
	for (int i = 0; i < content.size(); i++) {
		if (content[i] == '"') {
			result += "\\";
		}
		result += content[i];
	}
	return result;
}