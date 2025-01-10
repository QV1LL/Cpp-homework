#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <vector>
#include "json.hpp"

#include "DataLoader.h"

DataLoader* DataLoader::instance = nullptr;

DataLoader::DataLoader(const std::string& folderPath)
{
	this->folderPath = folderPath;
}

DataLoader* DataLoader::getInstance(const std::string& folderPath)
{
	if (!std::filesystem::exists(folderPath))
		throw std::invalid_argument("Path doesn`t exist");

	if (DataLoader::instance == nullptr)
		instance = new DataLoader(folderPath);

	return instance;
}

std::vector<json> DataLoader::load()
{
	std::vector<json> result;

	for (const auto& entry : std::filesystem::directory_iterator(this->folderPath)) {
		std::ifstream fileStream("./" + this->folderPath + "/" + entry.path().filename().string());

		if (!fileStream.is_open())
			continue;

		json serializedObject;
		fileStream >> serializedObject;
	
		result.push_back(serializedObject);
	}

	return result;
}
