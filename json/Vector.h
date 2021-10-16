#pragma once
#include <list>
#include "Item.h"
namespace jsonTools {
	class Vector
	{
	private:
		std::list<Item*>* collection;
		bool checkDouble(Item* jsonItem);
	public:
		Vector();
		~Vector();
		void Add(Item* jsonItem);
		Item* Get(Item* jsonItem);
		Item* Get(std::string nameVar);
		std::string Serialize();
		void Clear();
	};
}

