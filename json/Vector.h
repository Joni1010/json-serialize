#pragma once
#include <list>
#include <string>
#include "Item.h"
#include "UList.h"

namespace jsonTools {
	class Vector
	{
	private:
		UList<Item*>* collection;
		bool checkDouble(Item* jsonItem);
	public:
		Vector();
		~Vector();
		void Add(Item* jsonItem, bool addAny = true);
		Item* Get(Item* jsonItem);
		Item* Get(std::string nameVar);
		std::string Serialize();
		int Count();
		void Clear();
	};
}

