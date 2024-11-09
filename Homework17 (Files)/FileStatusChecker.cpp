#include "main.h"

auto isCStringsEquals(const char* text1, const char* text2) -> bool {
	const char* text1Iterator = text1;
	const char* text2Iterator = text2;

	for (; *text1Iterator != '\0' || *text2Iterator != '\0'; text1Iterator++, text2Iterator++)
		if (*text1Iterator != *text2Iterator)
			return false;

	if (*text1Iterator != '\0' || *text2Iterator != '\0')
		return false;

	return true;
}

auto FilesStatusChecker::printEqualsOfTwoFiles(const std::string& file1Name, const std::string& file2Name) -> void {
	FILE* file1;
	FILE* file2;

	fopen_s(&file1, file1Name.c_str(), "r");
	fopen_s(&file2, file2Name.c_str(), "r");

	if (file1 == nullptr || file2 == nullptr) {
		std::cerr << "One of files is not found";
		return;
	}

	bool isFilesTextsEquals = true;
	const int bufferSize = 512;

	char file1Buffer[bufferSize];
	char file2Buffer[bufferSize];

	while (fgets(file1Buffer, bufferSize, file1)) {
		if (fgets(file2Buffer, bufferSize, file2)) {
			if (!isCStringsEquals(file1Buffer, file2Buffer)) {
				printf("Non equals rows from files: \n File1: %s\n File2: %s\n", file1Buffer, file2Buffer);
				isFilesTextsEquals = false;
			}
		}
		else
			printf("Remaind from file1: %s", file1Buffer);
	}

	while (fgets(file1Buffer, bufferSize, file1)) {
		printf("Remaind from file1: %s", file1Buffer);
	}

	while (fgets(file2Buffer, bufferSize, file2)) {
		printf("Remaind from file2: %s", file2Buffer);
	}

	if (isFilesTextsEquals)
		std::cout << "Files are equals!";
}