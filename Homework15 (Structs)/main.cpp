#include <iostream>
#include "library.h"
#include <time.h>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

static const char alphanum[] =
"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

auto getRandomString(int stringLength) -> string
{
	string result;

	for (int i = 0; i < stringLength; i++)
		result += alphanum[rand() % stringLength];

	return result;
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

int main () {
	srand(time(0));

	Library* library = new Library();

	for (int i = 0; i < library->getBooksCount(); i++) {
		Book* book = library->getBook(i);

		book->setStatements(getRandomString(8), getRandomString(8), getRandomString(8));
	}

	library->sortBooksByTitle();

	library->printBooks();

	return 0;
}