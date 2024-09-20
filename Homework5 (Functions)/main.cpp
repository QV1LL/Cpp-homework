#include <iostream>
#include <map>
#include <string>

using namespace std;

// Get number to pow
float getNumberToPow(int number, int pow) {
	if (!pow) return 1;

	return (pow < 0) ?
		1 / (number * getNumberToPow(number, (pow * -1) - 1)) :
		number * getNumberToPow(number, pow - 1);
}

// Get sum in range
int getSumInRange(int start, int end) {
	if (!(end - start + 1)) return 0;

	return start + getSumInRange(start + 1, end);
}

// Loop implementation:
/* 
int getSumInRange(int start, int end) {
	int result = 0;

	for (int i = start; i <= end; i++) result += i;

	return result;
}
*/

// Is number perfect
bool isNumberPerfect(int number) {
	int dividersSum = 0;

	for (int i = 1; i <= number / 2; i++) dividersSum += (number % i == 0) ? i : 0;

	return dividersSum == number;
}

// Print card
void printCard(string suit) {
	map<string, string> cards = {
		{"Diamonds", "*********\n*   *   *\n*  ***  *\n*   *   *\n*********"},
		{"Clubs", "*********\n*   *   *\n*  ***  *\n*       *\n*********"},
		{"Hearts", "*********\n*  ***  *\n*  ***  *\n*   *   *\n*********"},
		{"Spades", "*********\n*   *   *\n*  ***  *\n*  ***  *\n*********"}
	};

	if (cards.find(suit) == cards.end()) {
		cout << "Incorrect suit of card!";
	}
	else {
		cout << cards[suit];
	}
}

// Is lucky number
bool isLuckyNumber(int number) {
	string stringNumber = to_string(number);

	int leftSum = 0;
	int rightSum = 0;

	for (int i = 0; i < stringNumber.size(); i++) {
		if (stringNumber.size() - 1 >= i * 2) leftSum += (int)stringNumber[i] - 48;
		else rightSum += (int)stringNumber[i] - 48;
	}

	return (leftSum == rightSum);
}

int main() {
	return 0;
}