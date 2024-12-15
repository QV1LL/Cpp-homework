#pragma once

#include <vector>

template <class T>
class TreeNode
{
private:

	TreeNode* rightNode;
	TreeNode* leftNode;

	T value;

public:

	TreeNode(T value, TreeNode* rightNode = nullptr, TreeNode* leftNode = nullptr)
		: rightNode(rightNode), leftNode(leftNode), value(value)
	{

	}

	T getMax() const;
	T getMin() const;
	std::vector<T> getSortedVector(std::vector<T> values = std::vector<T>()) const;
	const TreeNode<T>* find(T value) const;
};

