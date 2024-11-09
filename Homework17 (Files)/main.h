#pragma once
#include <iostream>

//***************************************** Task1 ***************************************** 
struct FilesStatusChecker {
private:
	FilesStatusChecker();

public:
	static auto printEqualsOfTwoFiles(const std::string& file1Name, const std::string& file2Name) -> void;
};

//***************************************** Task2 ***************************************** 
struct FileStats {
private:
	std::string fileName;

public:
	FileStats(const std::string_view fileName);

	auto getCountOfSymbols() const -> int;

	auto getCountOfRows() const -> int;

	auto getCountOfVowels() const -> int;

	auto getCountOfConsonant() const -> int;

	auto getCountOfDigits() const -> int;

	auto writeStatsToFile(const std::string& fileName) const -> void;
};

//***************************************** Task3 ***************************************** 
struct CaesarEncoder {
private:
	static CaesarEncoder* instance;

	CaesarEncoder() = default;

public:
	static CaesarEncoder* getInstance();

	std::string encodeText(std::string_view text, int encodeKey);
};