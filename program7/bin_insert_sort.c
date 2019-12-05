#include "bin_insert_sort.h"
int binary_search(char **a, int n, char *x, int (*p)(const char *, const char *));
void shift_right(char **array, int n);

/* Предполагается, что n>0, и по указателю a расположен массив из n элементов.
 * Сортировка двоичной вставкой.
 * */
void bin_insert_sort(char **a, int n, int (*p)(const char *, const char *))
{
	int i, new_position;

	for( i = 1; i<n; i++ )
	{
		new_position = binary_search(a, i, a[i], p);
		shift_right(a + new_position, i - new_position + 1);
	}
}

/* Предполагается, что n>0 и по указателю a расположен неубывающий массив из n элементов.
 * Ф-ия возвращает i: a[i]<=x<=a[i + 1].
 * */
int binary_search(char **a, int n, char *x, int (*p)(const char *, const char *))
{
	int left = 0, right = n, middle;

	while( left<right )
	{
		middle = (int)( (left + right)/2 );

		if( p(x, a[middle])>0 )
			left = middle + 1;
		else
			right = middle;
	}

	return left;
}

/* Предполагается, что n>0, и по указателю array расположен массив из n элементов.
 * Сдвиг вправо на один элемент.
 * */
void shift_right(char **array, int n)
{
	int i;
	char *buffer;

	buffer = array[n - 1];
	for( i = n - 1; i>0; i-- )
	{
		array[i] = array[i - 1];
	}
	array[0] = buffer;
}
