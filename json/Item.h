#pragma once
#include <typeinfo>
#include <string>
#include "VarJSON.h"
#include "Types.h"

namespace jsonTools {
	class Item
	{
	private:
		void* item;
		std::string serializationValue();
		std::string serializationName();
		std::string replaceSimbols(std::string);
		bool vector = false;
	public:
		Item();
		~Item();
		Item(std::string name, int value);
		Item(std::string name, __int8 value);
		Item(std::string name, __int16 value);
		Item(std::string name, __int64 value);
		Item(std::string name, long value);
		Item(std::string name, float value);
		Item(std::string name, double value);
		Item(std::string name, std::string value);
		Item(std::string name, std::string value, bool vector);

		Item(int value);
		Item(__int8 value);
		Item(__int16 value);
		Item(__int64 value);
		Item(long value);
		Item(float value);
		Item(double value);
		Item(std::string value);


		void Set(std::string name, int value);
		void Set(std::string name, __int8 value);
		void Set(std::string name, __int16 value);
		void Set(std::string name, __int64 value);
		void Set(std::string name, long value);
		void Set(std::string name, float value);
		void Set(std::string name, double value);
		void Set(std::string name, std::string value);
		void Set(std::string name, std::string value, bool vector);

		Var* GetVar();
		std::string Serialization(bool isArray = false);
		
	};
}

