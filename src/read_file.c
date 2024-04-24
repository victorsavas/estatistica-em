#include <read_file.h>

#include <stdio.h>
#include <ctype.h>

#define STARTING_SIZE 7

size_t sample_size = 0;
double *sample_array = NULL;

void read_raw_data(const char* filename)
{
	FILE* raw_data = fopen(filename, "r");

	if (raw_data == NULL)
	{
		printf("Error: invalid filename.\n");
		exit(1);
	}

	size_t sample_array_size = STARTING_SIZE;

	sample_size = 0;
	sample_array = malloc(STARTING_SIZE * sizeof(double));

	double *number = sample_array;

	while (fscanf(raw_data, "%lf", number++) > 0)
	{
		sample_size++;

		if (sample_size >= sample_array_size)
		{
			double* reallocated_array = realloc(sample_array, ((sample_array_size * 2) + 1) * sizeof(double));

			if (reallocated_array == NULL)
			{
				printf("Error: unable to reallocate array.\n");
				free(sample_array);
				exit(1);
			}

			sample_array_size = (sample_array_size * 2) + 1;

			sample_array = reallocated_array;

			number = sample_array + sample_size;

		}

	}

	fclose(raw_data);

	printf("\b\b \n");

	if (sample_size == 0)
	{
		printf("Error: the provided file has got no numbers.\n");
		exit(1);
	}

	double* reallocated_array = realloc(sample_array, sample_size * sizeof(double));

	if (reallocated_array == NULL)
	{
		free(sample_array);
		printf("Error: failed memory allocation at read_raw_data() (after closing the file).\n");
		exit(1);
	}

	sample_array = reallocated_array;
}

void free_sample_data(void)
{
	if (sample_array != NULL)
	{
		free(sample_array);
		
		sample_array = NULL;
		sample_size = 0;

	}
}