#include "main.h"

/**
 * get_width - function that calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @j: arguments to be printed
 * @list: arguments in a list form.
 *
 * Return: returns int width.
 */
int get_width(const char *format, int *j, va_list list)
{
	int cur_k;
	int width = 0;

	for (cur_k = *j + 1; format[cur_k] != '\0'; cur_k++)
	{
		if (is_digit(format[cur_k]))
		{
			width *= 10;
			width += format[cur_k] - '0';
		}
		else if (format[cur_k] == '*')
		{
			cur_k++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*j = cur_k - 1;

	return (width);
}

