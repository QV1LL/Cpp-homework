#include <iostream>
#include "main.h"

#define print std::cout
#define string std::string

auto sortBySurname(Collection<Man>* men) -> void;

auto sortByName(Collection<Man>* men) -> void;

auto printMen(Collection<Man>* men) -> void;

auto findByName(Collection<Man>* men, string targetName) -> Man;

auto findBySurname(Collection<Man>* men, string targetSurname) -> Man;

auto isFirstStringBiggerByAlphabet(string text1, string text2) -> bool;

// Man tasks i did using functions and student tasks using methods in struct, please don`t get confused)));
// I thought that students can be logical involved into some group, like university or etc, but group of men sounds strange and make no sence, so i keep them in collection;
int main() {
	StudentsGroup* studentsGroup = new StudentsGroup();

	for (int i = 0; i < 6; i++) {
		studentsGroup->getStudents().append({"Vereshagin", "P32", {i, i, i, i, i}});
	}

	studentsGroup->printExcellentStudents();

	Collection<Man>* men = new Collection<Man>(0);
	
	for (int i = 0; i < 6; i++) {
		Man man{ "Sasha", "Vereshagin", 27, { 7, 23, 1997 } };

		men->append(man);
	}

	men->collection[5].firstName = "Vlad (Starii)";
	men->collection[5].lastName = "Levenec (Bog)";
	men->collection[5].age = 25;
	men->collection[5].birthDate = { 8, 9, 1999 };

	sortByName(men);
	printMen(men);

	print << findByName(men, "Vlad (Starii)").lastName;

	return 0;
}

auto isFirstStringBiggerByAlphabet(string text1, string text2) -> bool {
	if (text1 == text2)
		return false;

	for (int i = 0; i < text1.size(); i++) {
		int text1Element = text1[i];
		int text2Element = text2[i];

		if ((48 <= text1Element && text1Element <= 57) || (65 <= text1Element && text1Element <= 90))
			text1Element += 32;
		else if (97 <= text1Element && text1Element <= 122) {

		}
		else {
			text1Element += 256;
		}

		if ((48 <= text2Element && text2Element <= 57) || (65 <= text2Element && text2Element <= 90))
			text2Element += 32;
		else if (97 <= text2Element && text2Element <= 122) {

		}
		else {
			text1Element += 256;
		}

		if (text1Element < text2Element)
			return true;
		else if (text1Element > text2Element)
			return false;
	}

	return false;
}


auto printMen(Collection<Man>* men) -> void {
	for (int i = 0; i < men->collectionSize; i++) {
		print << "Man: \n";
		print << "Name: " << men->collection[i].firstName << "\n";
		print << "Surname: " << men->collection[i].lastName << "\n";
		print << "Birthdate: " << men->collection[i].birthDate.toString() << "\n";
	}
}

auto sortBySurname(Collection<Man>* men) -> void {
	for (int i = 0; i < men->collectionSize; i++) {
		for (int j = 0; j < men->collectionSize; j++) {
			Man* man1 = &(men->collection[i]);
			Man* man2 = &(men->collection[j]);

			if (isFirstStringBiggerByAlphabet(man1->lastName, man2->lastName)) {
				auto pTemp = *man1;
				*man1 = *man2;
				*man2 = pTemp;
			}
		}
	}
}

auto sortByName(Collection<Man>* men) -> void {
	for (int i = 0; i < men->collectionSize; i++) {
		for (int j = 0; j < men->collectionSize; j++) {
			Man* man1 = &(men->collection[i]);
			Man* man2 = &(men->collection[j]);

			if (isFirstStringBiggerByAlphabet(man1->firstName, man2->firstName)) {
				auto pTemp = *man1;
				*man1 = *man2;
				*man2 = pTemp;
			}
		}
	}
}

auto findByName(Collection<Man>* men, string targetName) -> Man {
	for (int i = 0; i < men->collectionSize; i++) {
		if (men->collection[i].firstName == targetName)
			return men->collection[i];
	}
}

auto findBySurname(Collection<Man>* men, string targetSurname) -> Man {
	for (int i = 0; i < men->collectionSize; i++) {
		if (men->collection[i].firstName == targetSurname)
			return men->collection[i];
	}
}