#include "main.h"

/**
 * get_size - function to Cal size to cast the argument
 * @format: arguments that Formats string in which it will print
 * @i: arguments that show the listing of strings
 *
 * Return: returns int of the precision
 */
int get_size(const char *format, int *i)
{
	int cur_k = *i + 1;
	int siz = 0;

	if (format[cur_k] == 'l')
		siz = S_LONG;
	else if (format[cur_k] == 'h')
		siz = S_SHORT;

	if (siz == 0)
		*i = cur_k - 1;
	else
		*i = cur_k;

	return (siz);
}
