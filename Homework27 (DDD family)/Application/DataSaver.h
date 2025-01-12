#pragma once

using json = nlohmann::json;

class DataSaver
{
private:

	static DataSaver* instance;
	std::string folderPath;

	DataSaver(const std::string& folderPath);

public:

	static DataSaver* getInstance(const std::string& folderPath);

	void deleteOldSavings() const;
	void save(const ISerializable& serializableObject, uint16_t savingCount);
};

