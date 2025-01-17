#pragma once

template<class Type>
class LinkedListNode
{
private:

	Type value;

	LinkedListNode<Type>* next;
	LinkedListNode<Type>* previous;

public:

	LinkedListNode(const Type& value, LinkedListNode<Type>* next = nullptr, LinkedListNode<Type>* previous = nullptr);

	Type getValue() const { return this->value; }

	void setNext(LinkedListNode<Type>* next);
	LinkedListNode<Type>* getNext() const { return this->next; }
	
	void setPrevious(LinkedListNode<Type>* previous);
	LinkedListNode<Type>* getPrevious() const { return this->previous; }

	~LinkedListNode();
};