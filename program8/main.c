#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "../array/array.h"
#include "merge_sort.h"

int main(int argc, const char *argv[])
{
	int n, result_read;
	char **a, **b;
	clock_t time_begin;

	if( (argc!=3) || (sscanf(argv[1], "%d", &n)!=1) || (n<=0) )
	{
		fprintf(stderr, "Usage: %s size_of_array file_with_array\t\t(size_of_array>0)\n", argv[0]);
		return 1;
	}

	if( !(a = (char **)malloc(n*sizeof(char *))) )
	{
		fprintf(stderr, "Can not allocate memory!\n");
		return 2;
	}
	if( !(b = (char **)malloc(n*sizeof(char *))) )
	{
		fprintf(stderr, "Can not allocate memory!\n");
		free(a);
		return 2;
	}
	// Память выделена

	result_read = read_array(argv[2], a, n);
	if( result_read>0 )
	{
		fprintf(stderr, "Can not read element from %s or allocate memory for them\n", argv[2]);
		free_array(a, result_read - 1);
		free(b);
		return 2;
	}
	if( result_read<0 )
	{
		switch( result_read )
		{
		case -1:
			fprintf(stderr, "Can not open file %s\n", argv[2]);
			break;
		default:
			fprintf(stderr, "Unknown error %d in file %s\n", result_read, argv[2]);
		}

		free_array(a, n);
		free(b);
		return 3;
	}
	// Массив считан

	printf("Array a[]:\n");
	print_array(a, n);

	time_begin = clock();
	merge_sort(a, b, n, &strcmp);
	printf("Time: %.2lf seconds\nArray a[]:\n", (double)( clock() - time_begin )/CLOCKS_PER_SEC);
	print_array(a, n);

	free_array(a, n);
	free(b);
	return 0;
}
