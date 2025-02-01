#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>

#include "TextStatisticService.h"

std::shared_ptr<std::vector<std::string>> TextStatisticService::parseWords(const std::string& text) const {
    std::istringstream stream{ text };
    auto words = std::make_shared<std::vector<std::string>>();

    std::copy_if(std::istream_iterator<std::string>(stream),
        std::istream_iterator<std::string>(),
        std::back_inserter(*words),
        [](std::string_view word) { return !word.empty(); });

    return words;
}

void TextStatisticService::setTextStatistic(const std::string& text)
{
	this->reset();

    std::shared_ptr<std::vector<std::string>> words = this->parseWords(text);

    if (words)
        for (const std::string& word : *words)
            (*this->wordsAppearance)[word]++;
}

void TextStatisticService::setTextStatisticFromFile(const std::string& filePath)
{
    std::ifstream file(filePath);

    if (!file)
        throw std::runtime_error("Error opening file: " + filePath);

    std::stringstream buffer;
    buffer << file.rdbuf();

    this->setTextStatistic(buffer.str());
}

std::string TextStatisticService::getMostAppearedWord() const
{
    std::string result;
    int maxValue = 0;

    for (const auto& [key, value] : this->getStatistic())
        if (value > maxValue)
        {
            result = key;
            maxValue = value;
        }

    return result;
}

void TextStatisticService::saveStatisticToFile(const std::string& filePath) const
{
    std::ofstream file(filePath);
    
    if (!file) {
        throw std::runtime_error("Error opening file: " + filePath);
    }
    
    for (const auto& [key, value] : this->getStatistic())
        file << "Word: " + key + ", appearence: " + std::to_string(value) + "\n";

    file.close(); 
}

std::map<std::string, size_t> TextStatisticService::getStatistic() const
{
	return *this->wordsAppearance.get();
}
