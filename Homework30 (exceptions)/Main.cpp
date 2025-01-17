#include <iostream>

#include "LinkedList.h"

int main()
{
	LinkedList<int> list;
	list.addLast(52);
	list.addLast(1);
	list.addLast(1);
	list.addLast(1);
	list.addFirst(10);

	for (auto iterableNode : list)
		std::cout << iterableNode->getValue() << '\n';

	std::cout << '\n';

	auto node = list.getFirst()->getNext();

	list.deleteNode(node);

	for (auto iterableNode : list)
		std::cout << iterableNode->getValue() << '\n';

	return 0;
}