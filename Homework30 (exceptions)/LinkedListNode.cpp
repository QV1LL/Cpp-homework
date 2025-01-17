#include <iostream>

#include "LinkedListNode.h"

template<class Type>
LinkedListNode<Type>::LinkedListNode(const Type& value, LinkedListNode<Type>* next, LinkedListNode<Type>* previous)
{
	this->value = value;

	this->next = next;
	this->previous = previous;
}

template<class Type>
void LinkedListNode<Type>::setNext(LinkedListNode<Type>* next)
{
	if (next == nullptr)
		throw std::invalid_argument("Cannot assign empty node to next");

	this->next = next;
}

template<class Type>
void LinkedListNode<Type>::setPrevious(LinkedListNode<Type>* previous)
{
	if (previous == nullptr)
		throw std::invalid_argument("Cannot assign empty node to previous");

	this->previous = previous;
}

template<class Type>
LinkedListNode<Type>::~LinkedListNode()
{
	this->next = nullptr;
	this->previous = nullptr;
}

template class LinkedListNode<double>;
template class LinkedListNode<float>;
template class LinkedListNode<long>;
template class LinkedListNode<int>;
template class LinkedListNode<short>;
template class LinkedListNode<std::string>;
template class LinkedListNode<const char*>;