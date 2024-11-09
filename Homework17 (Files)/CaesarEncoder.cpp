#include "main.h"

CaesarEncoder* CaesarEncoder::instance = nullptr;

auto CaesarEncoder::getInstance() -> CaesarEncoder* {
	if (CaesarEncoder::instance == nullptr)
		CaesarEncoder::instance = new CaesarEncoder();

	return CaesarEncoder::instance;
}

auto CaesarEncoder::encodeText(std::string_view text, int encodeKey) -> std::string {
	std::string result(text);

	for (char& symbol : result) {
		if (symbol >= 'A' && symbol <= 'Z')
			symbol = 'A' + (symbol - 'A' + encodeKey) % 26;

		else if (symbol >= 'a' && symbol <= 'z')
			symbol = 'a' + (symbol - 'a' + encodeKey) % 26;
	}

	return result;
}