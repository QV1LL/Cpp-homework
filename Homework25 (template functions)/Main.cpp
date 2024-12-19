#include <iostream>

#include "TreeNode.h"

template<class T>
T getMax(T* array, size_t size) {
	T max = *array;

	for (T* nextValue = array; nextValue != (array + size); nextValue++)
		if (*nextValue > max) max = *nextValue;

	return max;
}

template<class T>
T getMin(T* array, size_t size) {
	T min = *array;

	for (T* nextValue = array; nextValue != (array + size); nextValue++)
		if (*nextValue < min) min = *nextValue;

	return min;
}

template<class T>
void sort(T* array, size_t size) {
	for (T* pFirstIterator = array; pFirstIterator != (array + size); pFirstIterator++)
		for (T* pSecondIterator = pFirstIterator; pSecondIterator != (array + size); pSecondIterator++)
			if (*pFirstIterator > *pSecondIterator)
				std::swap(*pFirstIterator, *pSecondIterator);
}

template<class T>
int binarySearch(T* array, int low, int high, T target) {
	if (low > high) return -1;

	int middle = low + (high - low) / 2;

	if (array[middle] == target) return middle;

	if (target < array[middle]) return binarySearch(array, low, middle - 1, target);
	return binarySearch(array, middle + 1, high, target);
	
}

template<class T>
void setElement(T* array, int index, T value) { 
	if (index < 0 && array == nullptr) throw std::invalid_argument("Invalid argument");

	array[index] = value; 
}

// Same task but with TreeNodes, thats what i talked at lesson) 0_0
void testTrees() {
	TreeNode<int> treeNode1{ 8 };
	TreeNode<int> treeNode2{ 9 };
	TreeNode<int> treeNode3{ 10 };
	TreeNode<int> treeNode4{ 8, &treeNode2, &treeNode3 };
	TreeNode<int> treeNode{ 7, &treeNode1, &treeNode4 };

	std::cout << "Min value: " << '\n';
	std::cout << treeNode.getMin() << '\n';

	std::cout << "Vector of tree values: " << '\n';
	std::vector<int> treeValues = treeNode.getSortedVector();

	for (int value : treeValues)
		std::cout << value << " ";

	auto findedNode = treeNode.find(10);
	std::cout << '\n' << (findedNode == &treeNode3);

	std::cout << '\n' << "Max value: " << '\n';
	std::cout << treeNode.getMax() << '\n';
}

int main() {
	int numbers[] = {
		1, 5, 8, 5, 6, 8
	};

	sort(numbers, 6);
	setElement(numbers, 5, 10);

	for (int i = 0; i < 6; i++) std::cout << numbers[i] << "\n";

	std::cout << "\n";

	std::cout << binarySearch(numbers, 0, 6, 5) << "\n\n\n";


	testTrees();

	return 0;
}