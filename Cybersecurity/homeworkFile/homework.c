#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char password[16];
    printf("give a password\n");
    scanf("%s", password);
    int passwordLenght = strlen(password);
    printf("pass length %i\n", passwordLenght);

    char data[100];
    printf("give a data\n");
    scanf("%s", data);
    int dataLenght = strlen(data);
    printf("data length %i\n", dataLenght);
    
    
    for(int i = 0; i < dataLenght; i++){
        printf("pass char %c\n", password[i % passwordLenght]);
        printf("data char %c\n", data[i]);
        data[i] ^= password[i % passwordLenght];

        printf("encrypted data %d\n", data[i]);
    }

    printf("encrypt data: %s", data);
    
}