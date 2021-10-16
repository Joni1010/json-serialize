```
using namespace std;

#include <iostream>
#include "json/Vector.h"

int main()
{
	jsonTools::Vector Json0;
	Json0.Add(new jsonTools::Item("v1", "111"));
	Json0.Add(new jsonTools::Item("v2", "222"));
	Json0.Add(new jsonTools::Item("v3", "333"));
	Json0.Add(new jsonTools::Item("v4", 555));
	Json0.Add(new jsonTools::Item("v5", 666));
	Json0.Add(new jsonTools::Item("v6", 77.77));
	Json0.Add(new jsonTools::Item("v6", 88.88));

	jsonTools::Vector Json1;
	Json1.Add(new jsonTools::Item("v1", "111"));
	Json1.Add(new jsonTools::Item("v2", "222"));

	jsonTools::Vector Json2;
	Json2.Add(new jsonTools::Item("g1", &Json0));
	Json2.Add(new jsonTools::Item("g2", &Json1));
	Json2.Add(new jsonTools::Item("g3", 222));

	jsonTools::Vector Json3;
	Json3.Add(new jsonTools::Item(&Json0));
	Json3.Add(new jsonTools::Item(&Json1));
	Json3.Add(new jsonTools::Item(222));

	std::cout << Json0.Serialize() << " \n\n";
	std::cout << Json1.Serialize() << " \n\n";
	std::cout << Json2.Serialize() << " \n\n";
	std::cout << Json3.Serialize() << " \n\n";

	Json0.Clear();
	Json1.Clear();
	Json2.Clear();
	Json3.Clear();
}

```

out
```
{ "v1": "111", "v2": "222", "v3": "333", "v4": 555, "v5": 666, "v6": 77.770000 }


{ "v1": "111", "v2": "222" }

{ "g1": { "v1": "111", "v2": "222", "v3": "333", "v4": 555, "v5": 666, "v6": 77.770000 }, "g2": { "v1": "111", "v2": "222" }, "g3": 222 }

[ { "v1": "111", "v2": "222", "v3": "333", "v4": 555, "v5": 666, "v6": 77.770000 }, { "v1": "111", "v2": "222" }, 222 ]
```