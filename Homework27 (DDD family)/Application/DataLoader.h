#pragma once

using json = nlohmann::json;

class DataLoader
{
private:

	static DataLoader* instance;
	std::string folderPath;

	DataLoader(const std::string& folderPath);

public:

	static DataLoader* getInstance(const std::string& folderPath);

	std::vector<json> load();
};

