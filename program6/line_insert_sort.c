#include "line_insert_sort.h"

/* Предполагается, что n>0, и по указателю a расположен массив из n элементов.
 * Сортировка линейной вставкой.
 * */
void line_insert_sort(char **a, int n, int (*p)(const char *, const char *))
{
	int i, j, position;
	char *buffer;

	for( i = 1; i<n; i++ )
	{
		// Поиск позиции для a[i] среди a[0] ... a[i - 1]
		for( position = 0; position<i; position++ )
		{
			if( p(a[position],a[i])>0 )
				break;
		}

		// Перестановка a[i] на нужную позицию
		buffer = a[i];
		for( j = i; j>position; j--)
		{
			a[j] = a[j - 1];
		}
		a[position] = buffer;
	}
}

