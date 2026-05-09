#include <iostream>
#include <string>

class Word {
private:
	std::string word;
	char guessed_letters[26];
	char wrong_letters[26];

public:
	Word();

	std::string getWord() {
		return word;
	}
};
