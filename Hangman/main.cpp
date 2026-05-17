#include <iostream>
#include "Word.h"

using namespace std;

int main() {	
	Word word;

	while(word.getLives() > 0) {
		if (word.isWordGuessed()) {
			break;
		}

		word.printHangman();
		printf("\n");
		word.printWrongLetter();
		word.printWord();

		cout << "Please enter a letter to guess the word: ";
		char letter;
		cin >> letter;

		if (letter > 'A' && letter < 'Z') {
			letter = letter - 'A' + 'a';
		}

		if (word.itsLetterInWord(letter)) {
			word.moveCursorUp(7);
			continue;
		}

		if (word.getWord().find(letter) != string::npos) {
			word.setGuessedLetters(letter);
		} else {
			word.setWrongLetters(letter);
			word.removeLive();
		}

		word.moveCursorUp(7);
	}


	if (word.getLives() > 0) {
		printf("Congratulations! You guessed the word: %s\n", word.getWord().c_str());
	} else {
		printf("Game over! The word was: %s\n", word.getWord().c_str());
	}
	
	return 0;
}
