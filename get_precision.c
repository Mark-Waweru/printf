
#include "main.h"

/**
 * get_precision - Calculates the precision for printing on the console
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int preci = -1;
	int curr_j = *i + 1;

	if (format[curr_j] != '.')
		return (preci);

	preci = 0;

	for (curr_j += 1; format[curr_j] != '\0'; curr_j++)
	{
		if (is_digit(format[curr_j]))
		{
			preci *= 10;
			preci += format[curr_j] - '0';
		}
		else if (format[curr_j] == '*')
		{
			curr_j++;
			preci = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_j - 1;

	return (preci);
}
