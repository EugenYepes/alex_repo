#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *dest_image, *origin_image;

	int option;
	char message[256];

	char ch;

	printf("Enter 1 to hide a message, enter 2 to read a message\n");
	scanf("%d", &option);

	if (option == 1) // hide message
	{
		origin_image = fopen("face.bmp", "rb");
		if (origin_image == NULL)
		{
			printf("Cannot open the image");
			return 1;
		}

		dest_image = fopen("result.bmp", "wb");
		if (dest_image == NULL)
		{
			printf("Cannot open the image");
			return 1;
		}

		printf("Enter the secrete message\n");
		scanf("%s", message);

		while ((ch = fgetc(origin_image)) != EOF)
		{
			fputc(ch, dest_image);
		}

		fseek(dest_image, 0, SEEK_END);
		fprintf(dest_image, "###%s###", message);

		fclose(dest_image);
		fclose(origin_image);

		printf("finish");
	}
	else // read hide message
	{
		origin_image = fopen("result.bmp", "wb");
		if (origin_image == NULL)
		{
			printf("Cannot open the image");
			return 1;
		}

		fseek(origin_image, -256, SEEK_END);
		char buffer[256];

		fread(buffer, 1, 256, origin_image);
		char *startMessage = strstr(buffer, "###");

		if (startMessage != NULL)
		{
			startMessage += 3;
			char *endMessage = strstr(startMessage, "###");
			if (endMessage != NULL)
			{
				*endMessage = '\0';
				printf("The message its %s\n", endMessage);
			}
			else
			{
				printf("Error endMessage null");
			}
		}
		else
		{
			printf("Error startMessage null");
		}
	}

	return 0;
}