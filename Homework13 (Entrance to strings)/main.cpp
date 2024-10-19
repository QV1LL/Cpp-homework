#include <iostream>
#include <string_view>

using namespace std;

//***************************************** Task1 *****************************************
auto replaceWordInText(string& text, string_view targetWord, string_view replaceWord) -> void {
	while (true) {
		int startOfTargetWord = text.find(targetWord);

		if (startOfTargetWord < 0)
			break;

		text.replace(startOfTargetWord, targetWord.size(), replaceWord);
	}
}

//***************************************** Task2 *****************************************
auto formateSentences(string& text) -> void {
	char sentenceSeparators[] = ".!?";
	bool letterToUpper = true;

	for (int i = 0; i < text.size(); i++) {
		if (letterToUpper) {
			if (isalpha(text[i])) {
				if ((text[i] >= 97 && text[i] <= 122))
					text[i] -= 32;

				letterToUpper = false;
			}
		}
		else {
			for (char sentenceSeparator : sentenceSeparators) {
				int separatorIndex = text.substr(i, text.size() - i).find(sentenceSeparator);

				if (separatorIndex >= 0) {
					i += separatorIndex;
					letterToUpper = true;

					break;
				}
			}
		}
	}
}

//***************************************** Task3 *****************************************
template <class T>
auto findIndex(T* array, size_t arraySize, T value) -> int {
	for (int i = 0; i < arraySize; i++)
		if (array[i] == value)
			return i;

	return -1;
}

auto printLetterStatsInText(string_view text) -> void {
	char letters[53];
	letters[52] = '\0';
	int lettersIterator = 0;

	int lettersCountInText[52]{ 0 };

	for (int i = 65; i <= 122; i++) {
		if (i == 91) {
			i += 5;
			continue;
		}

		letters[lettersIterator] = i;
		lettersIterator++;
	}

	for (char textElement : text) {
		int index = findIndex(letters, 53, textElement);

		if (index != -1)
			lettersCountInText[index]++;
	}

	for (int i = 0; i < 52; i++) {
		printf("Letter %c, appears %d times\n", letters[i], lettersCountInText[i]);
	}
}

//***************************************** Task4 *****************************************
auto getCountOfDigits(string_view text) -> int {
	int count = 0;

	for (char symbol : text) count += (symbol >= 48 && symbol <= 57);

	return count;
}

int main() {
	string text = "walking through the park, I noticed the leaves had started to change color. despite the cool breeze, people were out enjoying the day. sitting on a bench, an elderly man fed the birds while reading a book. although it was late afternoon, the sun still shone brightly, casting long shadows on the ground. under a nearby tree, children laughed and played, their voices echoing through the air. feeling a sense of peace, I continued my walk, grateful for the simple beauty of the moment.";
	replaceWordInText(text, "the", "eht");
	formateSentences(text);
	printLetterStatsInText(text);

	cout << text;

	string textWithDigits = "dadwad4a64648643wd1939a3d4awd1945wa";

	cout << getCountOfDigits(textWithDigits);

	return 0;
}