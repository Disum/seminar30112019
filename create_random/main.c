#include <stdio.h>
#include <stdlib.h>
#define DEFAULT_LENGTH 128
#define FIRST_SYMBOL 97
#define LAST_SYMBOL 122

int main(int argc, const char *argv[])
{
	int i, j, n, length;
	FILE *output;
	char buffer[DEFAULT_LENGTH];

	if( (argc!=3) || (sscanf(argv[1], "%d", &n)!=1) || (n<=0) )
	{
		fprintf(stderr, "Usage: %s size_of_array name_for_file_with_array\t(size_of_array>0)\n", argv[0]);
		return 1;
	}

	if( !(output = fopen(argv[2], "w")) )
	{
		fprintf(stderr, "Can not open %s\n", argv[2]);
		return 2;
	}

	for( i = 0; i<n; i++ )
	{
		length = 2 + (rand() % (DEFAULT_LENGTH - 1));

		for( j = 0; j<(length - 2); j++ )
			buffer[j] = FIRST_SYMBOL + (rand() % (LAST_SYMBOL - FIRST_SYMBOL + 1));

		buffer[length - 2] = '\n';
		buffer[length - 1] = '\0';

		fprintf(output, "%s", buffer);
	}

	return 0;
}
