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
			word = words[random_index];

			// Free the allocated memory for the array
			for (int j = 0; j < i; j++) {
				free(words[j]);
			}
		}
	}
}
