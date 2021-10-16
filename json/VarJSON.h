#pragma once
#include <string>
#include "Types.h"
#include "Var.h"

namespace jsonTools {
	template<typename T>
	class VarJSON : public Var
	{
	private:
		T value;
		void virtual defineType();
	public:
		VarJSON();
		VarJSON(std::string name, T value);
		~VarJSON();
		void SetValue(T value);
		T Value();
	};


	template<typename T>
	VarJSON<T>::VarJSON() {
		this->defineType();
	}

	template<typename T>
	VarJSON<T>::VarJSON(std::string name, T value) {
		this->defineType();
		this->SetName(name);
		this->SetValue(value);
	}

	template<typename T>
	void VarJSON<T>::defineType() {
		if (typeid(T) == typeid(int)) {
			this->type = Types::INT;
		}
		else if (typeid(T) == typeid(__int8)) {
			this->type = Types::INT8;
		}
		else if (typeid(T) == typeid(__int16)) {
			this->type = Types::INT16;
		}
		else if (typeid(T) == typeid(__int64)) {
			this->type = Types::INT64;
		}
		else if (typeid(T) == typeid(float)) {
			this->type = Types::FLOAT;
		}
		else if (typeid(T) == typeid(double)) {
			this->type = Types::DOUBLE;
		}
		else if (typeid(T) == typeid(std::string)) {
			this->type = Types::STRING;
		}
		else if (typeid(T) == typeid(bool)) {
			this->type = Types::BOOL;
		}
		else if (typeid(T) == typeid(long)) {
			this->type = Types::LONG;
		}
		else {
			this->type = Types::VECTOR;
		}
	}

	template<typename T>
	VarJSON<T>::~VarJSON() {

	}

	template<typename T>
	void  VarJSON<T>::SetValue(T value) {
		this->value = value;
	}

	template<typename T>
	T  VarJSON<T>::Value() {
		return this->value;
	}
}