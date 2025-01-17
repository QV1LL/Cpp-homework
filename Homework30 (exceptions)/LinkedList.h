#pragma once

#include "LinkedListNode.h"

template<class Type>
class LinkedListIterator {
private:
	LinkedListNode<Type>* current;

public:
	explicit LinkedListIterator(LinkedListNode<Type>* node) : current(node) {}

	LinkedListNode<Type>* operator*() const { return current; }

	LinkedListIterator& operator++();
	LinkedListIterator operator++(int);
	bool operator==(const LinkedListIterator& other) const { return current == other.current; }
	bool operator!=(const LinkedListIterator& other) const { return current != other.current; }
};


template<class Type>
class LinkedList
{

private:

	LinkedListNode<Type>* first;
	LinkedListNode<Type>* last;

public:

	LinkedList();

	void addFirst(Type nodeValue);
	void addLast(Type nodeValue);
	void deleteNode(LinkedListNode<Type>* node);

	LinkedListNode<Type>* getFirst();
	LinkedListNode<Type>* getLast();

    LinkedListIterator<Type> begin() const { return LinkedListIterator<Type>(this->first); }
    LinkedListIterator<Type> end() const { return LinkedListIterator<Type>(nullptr); }

	~LinkedList();
};