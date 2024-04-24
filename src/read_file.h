#pragma once

#include <stdio.h>
#include <stdlib.h>

// Raw number data

extern size_t sample_size;	// Size of the sample.
extern double *sample_array;		// Sample numbers.

void read_raw_data(const char *filename);

void free_sample_data(void);