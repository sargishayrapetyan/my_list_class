#include <iostream>

#include "List.h"

int main()
{
	List<int> b;
	if (b.isEmpty()) {
		std::cout << "Empty list\n";
	}

	b.push_front(10);
	b.push_back(116);	
	b.push_back(4);
	b.push_back(5);	
	std::cout << b.size() << std::endl;
    b.find(11);
	b.print();
	return 0;
}

