#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#define DEFAULT_LENGTH 1000

/* Предполагается, что n>0 и по указателю array выделена память для n элементов.
 * Ф-ия возвращает:
 * -2, если не удалось прочитать элемент;
 * -1, если не удалось открыть файл;
 * 0, в случае успешного завершения;
 * (i + 1)>0, если удалось выделить память и считать (i - 1) строк, i'ую удалось считать, но выделить память для нее не удалось.
 * */
int read_array(const char *name, char **array, int n)
{
	FILE *input;
	int i, j, k;
	char buffer[DEFAULT_LENGTH];

	if( !(input = fopen(name, "r")) )
		return -1;

	for( i = 0; i<n; i++ )
	{
		if( !fgets(buffer, DEFAULT_LENGTH, input) )
		{
			fclose(input);
			return -2;
		}

		for( j = 0; buffer[j]; j++ )
		{
			if( buffer[j]=='\n' )
			{
				buffer[j] = '\0';
				break;
			}
		}

		if( !(array[i] = (char *)malloc((j + 1)*sizeof(char))) )
		{
			fclose(input);
			return i + 1;
		}

		for( k = 0; k<(j + 1); k++ )
		{
			array[i][k] = buffer[k];
		}
	}

	fclose(input);
	return 0;
}

/* Предполагается, что n>0 и по указателю array выделена память для n элементов.
 * */
void print_array(char **array, int n)
{
	int i;

	if( n>20 )
		n = 20;

	for( i = 0; i<n; i++ )
		printf("Array[%d]=%.20s\n", i, array[i]);
}

void free_array(char **array, int n)
{
	int i;

	for( i = 0; i<n; i++ )
		free(array[i]);

	free(array);
}
