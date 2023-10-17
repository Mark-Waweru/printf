#include "main.h"

/**
 * get_precision - fuction that calculates the presion
 * @format: arguments that prints the formatted string
 * @i: arguments where a list of string to be printed
 * @list: arguments where a lsit of arguments is printed
 *
 * Return: returns int precision
 */
int get_precision(const char *format, int *i, va_list list)
{
	int precision = -1;
	int cur_k = *i + 1;

	if (format[cur_k] != '.')
		return (precision);

	precision = 0;

	for (cur_k += 1; format[cur_k] != '\0'; cur_k++)
	{
		if (is_digit(format[cur_k]))
		{
			precision *= 10;
			precision += format[cur_k] - '0';
		}
		else if (format[cur_k] == '*')
		{
			cur_k++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = cur_k - 1;

	return (precision);
}

