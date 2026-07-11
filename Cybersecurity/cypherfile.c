#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *originFile;
    FILE *destFile;

    char originPath[50];
    char destPath[50];
    char ch;
    char pass[20];

    printf("Gimme the name of the file: ");
    scanf("%49s", originPath);
    printf("Gimme the name of the file destination: ");
    scanf("%49s", destPath);

    printf("Enter your pass: ");
    scanf("%s", pass);
    int passLength = strlen(pass);

    originFile = fopen(originPath, "rb");
    if (originFile == NULL) {
        printf("cannot open the origin file");
        return -1;
    }

    destFile = fopen(destPath, "wb");
    if (destFile == NULL) {
        printf("cannot open the dest file");
        return -1;
    }
    
    int i = 0;
    while ((ch = fgetc(originFile)) != EOF) {
        char ch_cypher = ch ^ pass[i % passLength];
        fputc(ch_cypher, destFile);
        i++;
    }

    fclose(originFile);
    fclose(destFile);
    return 0;
}