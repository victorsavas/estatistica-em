#include <read_file.h>

#include <string.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	switch (argc)
	{
		// No file provided
		case 1:
			printf("Error: no file provided. Try \"./calculator help\".\n");
			return 1;

		case 2:
			// Help command
			if (!memcmp(argv[1], "help", 5))
			{
				printf("To use this program type: \"./calculator [file containing the list of numbers]\",\n");
				break;
			}

			read_raw_data(argv[1]);

			break;

		// More than one argument
		default:
			printf("Error: too many arguments provided. Try \"./calculator help\".\n");
			return 1;
	}

	free_sample_data();

	return 0;
}