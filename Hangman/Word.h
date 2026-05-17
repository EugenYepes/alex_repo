#include <iostream>
#include <string>

class Word {
private:
	std::string word;
	char guessed_letters[26];
	char wrong_letters[26];
	int lives;

public:
	Word();

	bool isWordGuessed();

	bool itsLetterInWord(char letter);

	// printing functions
	void printHangman();

	void printWord();

	void moveCursorUp(int lineas);

	void printWrongLetter();

	// getters and setters
	std::string getWord() {
		return word;
	}

	char* getGuessedLetters() {
		return guessed_letters;
	}

	void setGuessedLetters(char letter) {
		guessed_letters[letter - 'a'] = letter;
	}

	char* getWrongLetters() {
		return wrong_letters;
	}

	void setWrongLetters(char letter) {
		wrong_letters[letter - 'a'] = letter;
	}

	int getLives() {
		return lives;
	}

	void removeLive() {
		lives--;
	}
};
