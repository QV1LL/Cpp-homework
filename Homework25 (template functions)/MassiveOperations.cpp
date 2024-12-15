template<class T>
T getMax(T* array, size_t size) {
	T max;
	
	for (T* nextValue = array; nextValue != (array + size); nextValue++)
		if (*nextValue > max) max = *nextValue;

	return max;
}

template<class T>
T getMin(T* array, size_t size) {
	T min;

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
T binatySearch(T* array, size_t size);

template<class T>
void setElement(T* array, size_t size, int index, T value);