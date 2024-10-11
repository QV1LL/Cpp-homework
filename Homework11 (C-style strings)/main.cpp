#include <iostream>
#include <functional>

using namespace std;

//*************************** Task1 ***************************
auto deleteCharById(char* str, const int& index) -> void {
	if (index >= 0) {
		int i = 0;

		for (char* pStr = str; *pStr; pStr++, i++) {
			if (i >= index) {
				char* pNextCharInStr = pStr + 1;

				*pStr = *pNextCharInStr;
			}
		}
	}
}

//*************************** Task2 ***************************
auto deleteCharsInStr(char* str, const char& symbol) -> void {
	if (!symbol) return;
	
	bool formmatedString = true;
	short offSet = 0;

	for (char* pStr = str; *pStr; pStr++) {
		if (*pStr == symbol) {
			offSet = 1;
			formmatedString = false;
		}

		char* pNextCharInStr = pStr + offSet;

		*pStr = *pNextCharInStr;
	}

	if (!formmatedString) deleteCharsInStr(str, symbol);
}

//*************************** Task3 ***************************
auto replaceCharById(char* str, const int& index, const char& symbol) -> void {
	if (index >= 0 && symbol) {
		int i = 0;

		for (char* pStr = str; *pStr; pStr++, i++) {
			if (i == index) {
				*pStr = symbol;
			}
		}
	}
}

//*************************** Task4 ***************************
auto replaceDotsByExclamation(char* str) -> void {
	for (char* pStr = str; *pStr; pStr++) 
		if (*pStr == '.')
			*pStr = '!';
}

//*************************** Task5 ***************************
auto getCountOfEntry(char* str, const char& symbol) -> int {
	int count = 0;
	
	for (char* pStr = str; *pStr; pStr++)
		if (*pStr == symbol) count++;

	return count;
}

//*************************** Task6 ***************************
auto printStatsOfString(char* str) -> void {
	int countOfDigits = 0;
	int countOfLetters = 0;
	int countOfSymbols = 0;
	
	for (char* pStr = str; *pStr; pStr++) {
		if (*pStr >= 48 && *pStr <= 57)
			countOfDigits++;
		else if ((*pStr >= 65 && *pStr <= 90) || (*pStr >= 97 && *pStr <= 122))
			countOfLetters++;
		else
			countOfSymbols++;
	}

	cout << "Count of digits: " << countOfDigits << endl;
	cout << "Count of letters: " << countOfLetters << endl;
	cout << "Count of symbols: " << countOfSymbols << endl;
}

int main() {
	char str[] = "Hello world.";

	deleteCharById(str, 0);
	deleteCharsInStr(str, 'o');
	replaceCharById(str, 0, '1');
	replaceDotsByExclamation(str);
	printStatsOfString(str);

	cout << str;

	return 0;
}