#include "main.h"

const std::string vowels = "aeioyuAEIOYU";

const char* statsPrefix[]{
		"Count of symbols: ",
		"Count of rows: ",
		"Count of vowels: ",
		"Count of consonant: ",
		"Count of digits: ",
};

const int statsPrefixCount = 5;

FileStats::FileStats(const std::string_view fileName) {
	this->fileName = fileName;
}

auto FileStats::getCountOfSymbols() const -> int {
	FILE* file;
	
	if (fopen_s(&file, this->fileName.c_str(), "r"))
		return 0;

	int countOfSymbols = 0;

	while (getc(file) + 1) countOfSymbols++;

	fclose(file);

	return countOfSymbols;
}

auto FileStats::getCountOfRows() const -> int {
	FILE* file;

	if (fopen_s(&file, this->fileName.c_str(), "r"))
		return 0;

	int countOfSymbols = 0;

	const int bufferSize = 512;
	char buffer[bufferSize];

	while (fgets(buffer, bufferSize, file)) countOfSymbols++;

	fclose(file);

	return countOfSymbols;
}

auto FileStats::getCountOfVowels() const -> int {
	FILE* file;

	if (fopen_s(&file, this->fileName.c_str(), "r"))
		return 0;

	int countOfSymbols = 0;
	char currentSymbol;

	while ((currentSymbol = (char)getc(file)) + 1) {
		if (vowels.find(currentSymbol) != -1)
			countOfSymbols++;
	}

	fclose(file);

	return countOfSymbols;
}

auto FileStats::getCountOfConsonant() const -> int {
	FILE* file;

	if (fopen_s(&file, this->fileName.c_str(), "r"))
		return 0;

	int countOfSymbols = 0;
	char currentSymbol;

	while ((currentSymbol = (char)getc(file)) + 1) {
		if (vowels.find(currentSymbol) == -1)
			countOfSymbols++;
	}

	fclose(file);

	return countOfSymbols;
}

auto FileStats::getCountOfDigits() const -> int {
	FILE* file;

	if (fopen_s(&file, this->fileName.c_str(), "r"))
		return 0;

	int countOfSymbols = 0;
	char currentSymbol;

	while ((currentSymbol = (char)getc(file)) + 1) {
		if (currentSymbol >= 48 && currentSymbol <= 57)
			countOfSymbols++;
	}

	fclose(file);

	return countOfSymbols;
}

auto FileStats::writeStatsToFile(const std::string& fileName) const -> void {
	FILE* file;

	if (fopen_s(&file, fileName.c_str(), "w"))
		return;

	const int statsResult[]{
		this->getCountOfSymbols(),
		this->getCountOfRows(),
		this->getCountOfVowels(),
		this->getCountOfConsonant(),
		this->getCountOfDigits(),
	};

	for (int i = 0; i < statsPrefixCount; i++) {
		char statResult[512];

		_itoa_s(statsResult[i], statResult, 512, 10);

		if (fputs(statsPrefix[i], file) == -1)
			std::cerr << "File opened failed!";

		if (fputs(statResult, file) == -1)
			std::cerr << "File opened failed!";

		if (fputs("\n", file) == -1)
			std::cerr << "File opened failed!";
	}
	
	fclose(file);
}