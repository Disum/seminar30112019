#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#define DEFAULT_LENGTH 1000

/* Предполагается, что n>0 и по указателю array выделена память для n элементов.
 * Ф-ия возвращает:
 * -2, если не удалось прочитать элемент;
 * -1, если не удалось открыть файл;
 * 0, в случае успешного завершения;
 * k>0, если удалось выделить память для k строк, но не для (k + 1)'ой строки.
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

		array[i] = (char *)malloc((j + 1)*sizeof(char));
		if( !array[i] )
		{
			fclose(input);
			return i;
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
