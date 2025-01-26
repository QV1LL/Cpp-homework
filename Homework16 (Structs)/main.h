#pragma once

#include <iostream>
#include <string>
#define lessonsCount 5 
#define print std::cout
#define string std::string

struct Date {
public:
	short month : 8;
	short day : 8;
	short year : 16;

	string toString() {
		string result = std::to_string(this->month) + "." +
			std::to_string(this->day) + "." +
			std::to_string(this->year);

		return result;
	}
};

template<class T>
struct Collection {
public:
	T* collection;
	int collectionSize;

	Collection(int size) {
		this->collection = new T[size];
		this->collectionSize = size;
	}


	// Here is move constructor. Homework 31 :)
	Collection(Collection&& collection)
	{
		this->collectionSize = collection.collectionSize;
		this->collection = collection.collection;

		collection.collection = nullptr;
		collection.collectionSize = 0;
	}

	auto append(T item) -> void {
		T* pOldArray = this->collection;
		T* newArray = new T[this->collectionSize + 1];

		for (int i = 0; i < this->collectionSize; i++) {
			newArray[i] = pOldArray[i];
		}

		newArray[this->collectionSize] = item;
		this->collection = newArray;

		this->collectionSize++;

		delete[] pOldArray;
	}

	auto pop() -> T {
		T* pOldArray = this->collection;
		T* newArray = new T[this->collectionSize - 1];

		for (int i = 0; i < this->collectionSize - 1; i++) {
			newArray[i] = pOldArray[i];
		}

		T popItem = pOldArray[this->collectionSize - 1];

		this->collection = newArray;
		this->collectionSize--;

		delete[] pOldArray;

		return popItem;
	}

	auto deleteById(int id) -> void {
		if ((id < 0 || id >= this->collectionSize) && this->collectionSize)
			return;

		T* pOldArray = this->collection;
		T* newArray = new T[this->collectionSize - 1];

		int j = 0;
		for (int i = 0; i < this->collectionSize - 1; i++, j++) {
			if (i == id) {
				j++;
			}

			newArray[i] = pOldArray[j];
		}

		this->collection = newArray;
		this->collectionSize--;

		delete[] pOldArray;
	}
};

struct Student {
public:

	string lastName;
	string group;

	int performance[5];
};

struct Man {
public:

	string firstName;
	string lastName;

	int age;

	Date birthDate;
};

struct StudentsGroup {
private:
	Collection<Student>* students;

public:

	StudentsGroup() {
		this->students = new Collection<Student>(0);
	}

	auto getStudentById(int id) -> Student* {
		if ((id < 0 || id >= this->students->collectionSize) && this->students->collectionSize)
			return nullptr;

		return &students->collection[id];
	}

	auto getStudents() -> Collection<Student>& {
		return *(this->students);
	}

	auto isStudentExcellent(Student& student) -> bool {
		float countOfExcellentGrade = 0;

		for (int grade : student.performance) {
			if (grade > 3)
				countOfExcellentGrade++;
		}

		return (countOfExcellentGrade / lessonsCount) > 0.75;
	}

	auto isStudentImperformance(Student& student) -> bool {
		float countOfExcellentGrade = 0;

		for (int grade : student.performance) {
			if (grade < 4)
				countOfExcellentGrade++;
		}

		return (countOfExcellentGrade / lessonsCount) > 0.5;
	}

	auto printExcellentStudents() -> void {
		Collection<int>* excellentStudentIds = new Collection<int>(0);
		
		for (int i = 0; i < this->students->collectionSize; i++) {
			if (isStudentExcellent(this->students->collection[i]))
				excellentStudentIds->append(i);
		}

		for (int i = 0; i < excellentStudentIds->collectionSize; i++) {
			print << "One of the best student: " << this->students->collection[excellentStudentIds->collection[i]].lastName << "!!!\n";
		}
	}

	auto printImperformanceStudents() -> void {
		Collection<int>* ImperformanceStudentIds = new Collection<int>(0);

		for (int i = 0; i < this->students->collectionSize; i++) {
			if (isStudentImperformance(this->students->collection[i]))
				ImperformanceStudentIds->append(i);
		}

		for (int i = 0; i < ImperformanceStudentIds->collectionSize; i++) {
			print << "One of the weakest student: " << this->students->collection[ImperformanceStudentIds->collection[i]].lastName << "!!!\n";
		}
	}

	auto printAllStudents() -> void {
		for (int i = 0; i < this->students->collectionSize; i++) {
			print << "Student: " << this->students->collection[i].lastName << "!!!\n";
		}
	}
};