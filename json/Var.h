#pragma once
#include <typeinfo>
#include <string>

namespace jsonTools {
	class Var
	{
	protected:
		std::string name;
		bool array = true;
		int type = -1;
		void virtual defineType();
	public:
		int GetType();
		std::string virtual Name();
		void virtual SetName(std::string name);
		bool IsArray();
	};
}

