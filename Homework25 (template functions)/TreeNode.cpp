#include <iostream>
#include <algorithm>

#include "TreeNode.h"

template<class T>
T TreeNode<T>::getMax() const {
	if (this->leftNode == nullptr && this->rightNode == nullptr)
		return this->value;

	if (this->leftNode == nullptr) {
		T rightNodeMax = this->rightNode->getMax();
		return (this->value > rightNodeMax) ? this->value : rightNodeMax;
	}
	if (this->rightNode == nullptr) {
		T leftNodeMax = this->leftNode->getMax();
		return (this->value > leftNodeMax) ? this->value : leftNodeMax;
	}

	T leftNodeMax = this->leftNode->getMax();
	T rightNodeMax = this->rightNode->getMax();

	leftNodeMax = (leftNodeMax > this->value) ? leftNodeMax : value;

	return (leftNodeMax > rightNodeMax) ? leftNodeMax : rightNodeMax;
}

template<class T>
T TreeNode<T>::getMin() const {
	if (this->leftNode == nullptr && this->rightNode == nullptr)
		return this->value;

	if (this->leftNode == nullptr) {
		T rightNodeMin = this->rightNode->getMin();
		return (this->value < rightNodeMin) ? this->value : rightNodeMin;
	}
	if (this->rightNode == nullptr) {
		T leftNodeMin = this->leftNode->getMin();
		return (this->value < leftNodeMin) ? this->value : leftNodeMin;
	}

	T leftNodeMin = this->leftNode->getMin();
	T rightNodeMin = this->rightNode->getMin();

	leftNodeMin = (leftNodeMin < this->value) ? leftNodeMin : value;

	return (leftNodeMin < rightNodeMin) ? leftNodeMin : rightNodeMin;
}

template<class T>
std::vector<T> TreeNode<T>::getSortedVector(std::vector<T> values) const {
	values.push_back(this->value);

	if (this->rightNode == nullptr && this->leftNode == nullptr)
		return std::vector<T>(values);

	std::vector<T> rightNodeVector;
	std::vector<T> leftNodeVector;

	if (this->rightNode != nullptr) rightNodeVector = this->rightNode->getSortedVector();

	if (this->leftNode != nullptr) leftNodeVector = this->leftNode->getSortedVector();

	values.insert(values.begin(), leftNodeVector.begin(), leftNodeVector.end());
	values.insert(values.begin(), rightNodeVector.begin(), rightNodeVector.end());
	std::sort(values.begin(), values.end());

	return values;
}

template<class T>
const TreeNode<T>* TreeNode<T>::find(T value) const
{
	if (this->value == value) return this;

	const TreeNode<T>* pTargetNode = nullptr;

	if (this->leftNode != nullptr) pTargetNode = this->leftNode->find(value);
	if (pTargetNode != nullptr) return pTargetNode;
	if (this->rightNode != nullptr) pTargetNode = this->rightNode->find(value);

	return pTargetNode;
}


template class TreeNode<int>;
template class TreeNode<float>;
template class TreeNode<double>;