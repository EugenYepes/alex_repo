#include <stdio.h>
#include <string.h>

// int main(){
// 	int numbers[] = {1, 5, 20};
// 	int a = 0;


// 	printf("%p\n", numbers);
// 	printf("%p\n", &a);
// 	* (&a + 1) = 8;
// 	* (&a + 2) = 8;
// 	* (&a + 3) = 8;
// 	for (int i = 0; i < 3; i++) {
// 		printf("[%d] %d\n", i, numbers[i]);
// 	}
// }

// int main () {
// 	char password[8];

// 	printf("Please enter your password to access: ");
// 	scanf("%s", password);

// 	printf("%s\n", password);

// 	char* password_address = password;
// 	*password_address = 'a';
// 	*(password_address + 1) = 'd';
// 	*(password_address + 2) = 'm';
// 	*(password_address + 3) = 'i';
// 	*(password_address + 4) = 'n';
// 	*(password_address + 5) = '\0';

// 	if (strcmp(password, "admin") == 0) {
// 		printf("its admin\n");
// 	}
// }

int main() {
	int access_guaranteed = 0;
	char password[8];

	printf("Please enter your password to access: ");
	scanf("%7s", password);


	printf("access: %d\n", access_guaranteed);
	if (strcmp(password, "admin") == 0) {
		access_guaranteed = 1;
	}


	printf("access: %d\n", access_guaranteed);

	if (access_guaranteed == 1) {
		printf("i ve access to the system");
	}

}
