<<<<<<< HEAD
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
=======

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
>>>>>>> 674f6f738b65e24bd9e79645c3e0c569cbcf57f1
			break;
		}
		else
			break;
	}

<<<<<<< HEAD
	*i = cur_k - 1;

	return (precision);
}

=======
	*i = curr_j - 1;

	return (preci);
}
>>>>>>> 674f6f738b65e24bd9e79645c3e0c569cbcf57f1
