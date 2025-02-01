#pragma once

class TextStatisticService
{
private:

	std::unique_ptr<std::map<std::string, size_t>> wordsAppearance;

	std::shared_ptr<std::vector<std::string>> parseWords(const std::string& text) const;

public:

	TextStatisticService() { this->wordsAppearance = std::make_unique<std::map<std::string, size_t>>(); }

	void setTextStatistic(const std::string& text);
	std::map<std::string, size_t> getStatistic() const;
	std::string getMostAppearedWord() const;

	void setTextStatisticFromFile(const std::string& filePath);
	void saveStatisticToFile(const std::string& filePath) const;

	void reset() { this->wordsAppearance->clear(); }
};

