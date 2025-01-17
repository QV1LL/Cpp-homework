#include <iostream>

#include "NullObjectMethodInvokeException.h"
#include "LinkedList.h"

template<class Type>
LinkedList<Type>::LinkedList()
{
	this->first = nullptr;
	this->last = nullptr;
}

template<class Type>
void LinkedList<Type>::addFirst(Type nodeValue)
{
	LinkedListNode<Type>* node = new LinkedListNode<Type>(nodeValue);

	if (this->last == nullptr)
		this->first = this->last = node;

	else
	{
		LinkedListNode<Type>* second = this->first;
		this->first = node;
		second->setPrevious(this->first);
		this->first->setNext(second);
	}
}

template<class Type>
void LinkedList<Type>::addLast(Type nodeValue)
{
	LinkedListNode<Type>* node = new LinkedListNode<Type>(nodeValue);

	if (this->first == nullptr)
		this->first = this->last = node;

	else
	{
		LinkedListNode<Type>* semiLast = this->last;
		this->last = node;
		semiLast->setNext(this->last);
		this->last->setPrevious(semiLast);
	}
}

template<class Type>
void LinkedList<Type>::deleteNode(LinkedListNode<Type>* node)
{
	if (this->first == nullptr)
		throw NullObjectMethodInvokeException("List is empty");

	bool isNodeInList = false;

	for (auto iterator : *this)
	{
		if (iterator == node)
		{
			isNodeInList = true;
			break;
		}
	}

	if (!isNodeInList) throw std::out_of_range("Paramether node isn`t member of list");

	node->getPrevious()->setNext(node->getNext());
	node->getNext()->setPrevious(node->getPrevious());
}

template<class Type>
LinkedListNode<Type>* LinkedList<Type>::getFirst()
{
	if (this->first == nullptr)
		throw NullObjectMethodInvokeException("List is empty");

	return this->first;
}

template<class Type>
LinkedListNode<Type>* LinkedList<Type>::getLast()
{
	if (this->last == nullptr)
		throw NullObjectMethodInvokeException("List is empty");

	return this->last;
}

template<class Type>
LinkedList<Type>::~LinkedList()
{
	LinkedListNode<Type>* iterableNode = this->first;

	while (iterableNode != nullptr)
	{
		auto nodeToDelete = iterableNode;
		iterableNode = iterableNode->getNext();
		delete nodeToDelete;
	}
}

template<class Type>
LinkedListIterator<Type>& LinkedListIterator<Type>::operator++()
{
	if (current) current = current->getNext();

	return *this;
}

template<class Type>
LinkedListIterator<Type> LinkedListIterator<Type>::operator++(int)
{
	auto temp = *this;
	++(*this);
	return temp;
}

template class LinkedList<double>;
template class LinkedList<float>;
template class LinkedList<long>;
template class LinkedList<int>;
template class LinkedList<short>;
template class LinkedList<std::string>;
template class LinkedList<const char*>;