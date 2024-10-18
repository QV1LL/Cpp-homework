#include <iostream>
#include <cstring>

using namespace std;

//******************************************** Task1 ********************************************
auto replaceWordsInText(char* text, const char* targetWord, const char* replaceWord) -> char* {
	char* result = new char[strlen(text) + (strlen(replaceWord) - strlen(targetWord))];
	char* resultIterable = result;

	char* wordStart = strstr(text, targetWord);

	int i = 0;

	for (i; *resultIterable; i++, resultIterable++) {
		if (wordStart == &text[i]) {
			const char* replaceWordIterable = replaceWord;

			for (; *replaceWordIterable; replaceWordIterable++, resultIterable++)
				*resultIterable = *replaceWordIterable;

			i += strlen(targetWord);
			wordStart = strstr(&text[i], targetWord);
		}

		*resultIterable = text[i];
	}

	*(resultIterable + 1) = '\0';

	return result;
}

//******************************************** Task2 ********************************************
auto formateSentences(char* text) -> void {
	char* pLetterAfterDot = nullptr;
	bool wasSentenceEnd = true;

	char sentenceSeparators[] = ".!?";

	for (char* textChar = text; *textChar; textChar++) {
		if (wasSentenceEnd && isalpha(*textChar)) {
			if (*textChar >= 97 && *textChar <= 122) {
				*textChar -= 32;
			}

			wasSentenceEnd = false;
		}

		else if (strchr(sentenceSeparators, *textChar) != nullptr)
			wasSentenceEnd = true;
	}
}

//Not a bad realisation, but what if we get the pointer of our sentence separator and after search the first letter? This case would be much easier than O(n)
auto fastFormateSentences(char* text) -> void {
	char sentenceSeparators[] = ".!?";
	char* pLetterAfterDot = nullptr;
	char* pSeparator = nullptr;

	char* textIterator = text;

	do {
		pSeparator = nullptr;

		for (char* pSeparatorsElement = sentenceSeparators; *pSeparatorsElement; pSeparatorsElement++)
			if (strchr(textIterator, *pSeparatorsElement) != nullptr) {
				pSeparator = strchr(textIterator, *pSeparatorsElement);
				break;
			}

		if (pSeparator != nullptr)
			for (textIterator = pSeparator; *textIterator; textIterator++)
				if (isalpha(*textIterator)) {
					if ((*textIterator >= 97 && *textIterator <= 122))
						*textIterator -= 32;

					break;
				}

	} while (pSeparator);

	for (char* pCharInText = text; *pCharInText; pCharInText++)
		if (isalpha(*pCharInText)) {
			if ((*pCharInText >= 97 && *pCharInText <= 122))
				*pCharInText -= 32;

			break;
		}
}

//******************************************** Task3 ********************************************
template <class T>
auto findIndex(T* array, size_t arraySize, T value) -> int {
	for (int i = 0; i < arraySize; i++)
		if (array[i] == value)
			return i;

	return -1;
}

auto printLetterStatsInText(const char* text) -> void {
	char letters[53];
	letters[52] = '\0';
	int lettersIterator = 0;

	int lettersCountInText[52] {0};

	for (int i = 65; i <= 122; i++) {
		if (i == 91) {
			i += 5;
			continue;
		}

		letters[lettersIterator] = i;
		lettersIterator++;
	}

	for (const char* pCharInText = text; *pCharInText; pCharInText++) {
		int index = findIndex(letters, 53, *pCharInText);

		if (index != -1)
			lettersCountInText[index]++;
	}

	for (int i = 0; i < 52; i++) {
		printf("Letter %c, appears %d times\n", letters[i], lettersCountInText[i]);
	}
}

//******************************************** Task4 ********************************************
auto getCountOfDigits(const char* text) -> int {
	int countOfDigits = 0;

	for (const char* pTextElement = text; *pTextElement; pTextElement++)
		countOfDigits += (*pTextElement >= 48 && *pTextElement <= 57);

	return countOfDigits;
}

int main() {
	cout << getCountOfDigits("dadwadwa46488443dadawda    *(&^%") << endl;
	printLetterStatsInText("In modern software development, creating flexible and scalable applications requires leveraging established solutions for organizing code. One such solution is the Decorator Design Pattern. This pattern allows for dynamically extending the functionality of objects without altering their structure. In this article, we'll explore the basics of the Decorator pattern, its applications, and examples of its use.");

	return 0;
}