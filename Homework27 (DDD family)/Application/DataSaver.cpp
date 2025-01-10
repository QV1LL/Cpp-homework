#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <vector>
#include "json.hpp"

#include "Serializable.h"
#include "DataSaver.h"

DataSaver* DataSaver::instance = nullptr;

DataSaver::DataSaver(const std::string& folderPath)
{
	this->folderPath = folderPath;
}

DataSaver* DataSaver::getInstance(const std::string& folderPath)
{
	if (!std::filesystem::exists(folderPath))
		std::filesystem::create_directory(folderPath);

	if (DataSaver::instance == nullptr)
		instance = new DataSaver(folderPath);

	return instance;
}

void DataSaver::deleteOldSavings() const
{
	for (const auto& entry : std::filesystem::directory_iterator(this->folderPath))
		std::filesystem::remove(entry.path());
}

void DataSaver::save(const Serializable& serializableObject, uint16_t savingId)
{
	std::fstream file(folderPath + "/saving" + std::to_string(savingId) + ".json", std::ios::out);
	file << serializableObject.serialize();
}
