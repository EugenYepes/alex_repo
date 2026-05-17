#include "Word.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

Word::Word() {
	srand(time(NULL));
	FILE *file = fopen("words.txt", "r");
	if (file == NULL) {
		printf("Error opening file\n");
	} else {
		char buffer[100];
		char *words[3000]; // Amount of words in the file.
		int i = 0;
		while(fgets(buffer, sizeof(buffer), file) != NULL) {
			buffer[strcspn(buffer, "\r\n")] = 0; // Remove newline character from the file.
			words[i] = strdup(buffer);
			i++;
		}
		fclose(file);

		if (i > 0) {
			int random_index = rand() % i;
			this->word = words[random_index];

			// Free the allocated memory for the array
			for (int j = 0; j < i; j++) {
				free(words[j]);
			}
		}
	}

	memset(guessed_letters, '\0', sizeof(guessed_letters));
	memset(wrong_letters, '\0', sizeof(wrong_letters));
	lives = 6;
}

bool Word::isWordGuessed() {
	int length = this->getWord().length();
	for (int i = 0; i < length; i++) {
		if (!itsLetterInWord(this->getWord()[i])) {
			return false;
		}
	}
	return true;
}

bool Word::itsLetterInWord(char letter) {
	return this->guessed_letters[letter - 'a'] != '\0';
}

void Word::printHangman() {
	if (this->lives >= 1) printf(" O\n");
	else printf("  \n");

	if (this->lives >= 4) printf("/|\\\n");
	else if (this->lives >= 3) printf("/| \n");
	else if (this->lives >= 2) printf(" | \n");
	else printf("   \n");
	

	if (this->lives >= 6) printf("/ \\\n");
	else if (this->lives >= 5) printf("/  \n");
	else printf("   \n");
}

void Word::printWord() {
	int length = this->getWord().length();
	for (int i = 0; i < length; i++) {
		if (this->itsLetterInWord(this->getWord()[i])) {
			printf("%c ", this->getWord()[i]);
		} else {
			printf("_ ");
		}
	}
	printf("\n");
}

void Word::moveCursorUp(int lineas) {
    printf("\033[%dA", lineas);
}

void Word::printWrongLetter() {
	printf("Wrong letters: ");
	for (int i = 0; i < 26; i++) {
		if (this->wrong_letters[i] != '\0') {
			printf("%c ", this->wrong_letters[i]);
		}
	}
	printf("\n");
}