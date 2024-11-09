#include <iostream>
#include <cstdio>
#include <string>
#include <string_view>

#include "main.h"

// Task 1 is located in main.h and FileStatusChecker.cpp files;

// Task 2 is located in main.h and FileStats.cpp files;

// Task 3 is located in main.h and CaesarEncoder.cpp files;

int main() {
	//Task1 test
	std::string file1Name = "task1\\text1.txt";
	std::string file2Name = "task1\\text2.txt";

	FilesStatusChecker::printEqualsOfTwoFiles(file1Name, file2Name);


	//Task2 test
	FileStats fileStats{"task2\\text1.txt"};

	fileStats.writeStatsToFile("task2\\text1 stats.txt");


	//Task3 test
	CaesarEncoder* encoder = CaesarEncoder::getInstance();

	FILE* file;

	if (fopen_s(&file, "task3\\text.txt", "r"))
		return 1;

	std::fseek(file, 0, SEEK_END);
	long fileSize = std::ftell(file);
	std::rewind(file);

	std::string fileText(fileSize, '\0');
	std::fread(fileText.data(), 1, fileSize, file);
	fclose(file);

	fileText = encoder->encodeText(fileText, 3);

	if (fopen_s(&file, "task3\\encodedText.txt", "w"))
		return 1;

	fputs(fileText.c_str(), file);
	fclose(file);

	return 0;
}