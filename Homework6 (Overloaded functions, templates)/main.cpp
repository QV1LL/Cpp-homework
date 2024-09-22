#include <iostream>
#include <vector>
#include <time.h> 

using namespace std;

//****************************** Task1 ******************************

// Initialization of two dimensional matrix
template <typename T> vector<vector<T>> initMatrix(int size, T defaultValue) {
	return vector<vector<T>>(size, vector<T>(size, defaultValue));
}

//Initialization using overload
vector<vector<int>> initMatrix(int size, int defaultValue) {
	return vector<vector<int>>(size, vector<int>(size, defaultValue));;
}

vector<vector<double>> initMatrix(double size, double defaultValue) {
	return vector<vector<double>>(size, vector<double>(size, defaultValue));
}

vector<vector<char>> initMatrix(char size, char defaultValue) {
	return vector<vector<char>>(size, vector<char>(size, defaultValue));
}

//Printing matrix
template <typename T> void printMatrix(T matrix) {
	for (int i = 0; i < (int) matrix.size(); i++) {
		for (int j = 0; j < (int) matrix.size(); j++) {
			cout << " " << matrix[i][j] << " ";
		}

		cout << endl;
	}
}

//Getting min and max at the main diagonal
template <typename T> auto getMatrixMainDiagonalMin(T matrix) {
	int min = matrix[0][0];

	for (int i = 0; i < (int)matrix.size(); i++) {
		auto currentValue = matrix[i][i];
		min = (currentValue < min) ? currentValue : min;
	}

	return min;
}

template <typename T> auto getMatrixMainDiagonalMax(T matrix) {
	int max = matrix[0][0];

	for (int i = 0; i < (int)matrix.size(); i++) {
		auto currentValue = matrix[i][i];
		max = (currentValue > max) ? currentValue : max;
	}

	return max;
}

//Sort each row of matrix
template <typename T> void sortMatrixRows(T& matrix) {
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix.size(); j++) {
			for (int l = 0; l < matrix.size(); l++) {
				if (matrix[i][j] < matrix[i][l]) {
					swap(matrix[i][j], matrix[i][l]);
				}
			}
		}
	}
}

//****************************** Task2 ******************************

//Get biggest divider recursively by Euclid algorithm
int getBiggestDivider(int number1, int number2) {
	if (!number2) return number1;

	return getBiggestDivider(number2, number1 % number2);
}

//Bulls and cows
void bullsAndCows() {
	srand(time(NULL));

	int targetNumber = (rand() % 10000);

	cout << targetNumber;
}

int main() {
	bullsAndCows();

	return 0;
}