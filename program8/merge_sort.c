#include "merge_sort.h"
void merge(char **a, char **b, char **c, int n, int m, int (*p)(const char *, const char *));
void swap(char ***a, char ***b);

/* Предполагается, что n>0, по указателю a расположен массив из n элементов, по указателю b выделена память для n элеметов.
 * Сортировка Неймана.
 * */
void merge_sort(char **a, char **b, int n, int (*p)(const char *, const char *))
{
	int i, size, num;
	char **a_begin = a;

	for( size = 1; size<n; size *= 2 )// Размер группы
	{
		for( num = 1; (num + 1)*size<=n; num += 2 )// Номер группы
		{
			merge(a + (num - 1)*size, a + num*size, b + (num - 1)*size, size, size, p);
		}

		if( (num*size + 1)<=n )
		{
			merge(a + (num - 1)*size, a + num*size, b + (num - 1)*size, size, n - num*size, p);
		} else
		{
			for( i = (num - 1)*size; i<n; i++ )
				b[i] = a[i];
		}

		swap(&a, &b);
	}

	if( a!=a_begin )
	{
		for( i = 0; i<n; i++ )
			a_begin[i] = a[i];
	}
}

/* Предполагается, что n>0, m>0 и по указателю a записан неубывающий массив длины n, по указателю b неубывающий массив из m элементов,
 * по указателю c выделена память для (n + m) элементов. 
 * Ф-ия строит неубывающий массив слиянием a и b.
 * */
void merge(char **a, char **b, char **c, int n, int m, int (*p)(const char *, const char *))
{
	int i = 0, j = 0, k;

	for( k = 0; (i<n) && (j<m); k++ )
	{
		if( p(b[j], a[i])>0 )
		{
			c[k] = a[i];
			i++;
		} else
		{
			c[k] = b[j];
			j++;
		}
	}

	for( ; i<n; k++, i++ )
		c[k] = a[i];

	for( ; j<m; k++, j++)
		c[k] = b[j];
}

void swap(char ***a, char ***b)
{
	char **buffer;

	buffer = *a;
	*a = *b;
	*b = buffer;
}
