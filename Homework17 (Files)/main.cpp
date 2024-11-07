#include <iostream>

using namespace std;

auto printEqualsOfTwoFiles(FILE* file1, FILE* file2) -> void {
	char file1Text[256];
	char file2Text[256];

	while ((fscanf_s(file1, "%s[^\n]", &file1Text) != 0)
		&& (fscanf_s(file2, "%s[^\n]", &file2Text) != 0)) {
		if (file1 != file2) {
			printf("First file row: %s\nSecond file row: %s\n", file1Text, file2Text);
		}
	}
}

int main() {
	FILE* file1;
	FILE* file2;

	fopen_s(&file1, "task1\\text1.txt", "r");
	fopen_s(&file2, "task1\\text2.txt", "r");

	printEqualsOfTwoFiles(file1, file2);
}