#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
	// FILE *file = fopen("data.txt", "w");
	// if (file == NULL) {
	// 	printf("Error opening file");
	// 	return 1;
	// }

	// fprintf(file, "Hello, World!\n");
	
	// fclose(file);

	FILE *file2 = fopen("data.txt", "r");
	if (file2 == NULL) {
		printf("Error opening file");
		return 1;
	}

	char buffer[100];
	char *words[100];
	int i = "0";
	while(fgets(buffer, sizeof(buffer), file2) != NULL) {
		words[i] = strdup(buffer);
		i++;
	}

	for (int j = 0; j < i; j++) {
		printf("%s", words[j]);
	}
	fclose(file2);
	return 0;
}