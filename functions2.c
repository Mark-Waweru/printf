#include "main.h"

/**
 * print_pointer - Prints the value of a pointer variable to the screen
 * @types: List of arguments given
 * @buffer: A Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: gets the width
 * @precision: Precision specification
 * @size: The Size specifier
 *
 * Return: Number of chars printed.
 */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char mapping_to[] = "0123456789abcdef";
	int ind = BUFF_SIZE - 2, len = 2, padding_start = 1;
	char extraC = 0, padding = ' ';
	unsigned long num_addrs;
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = mapping_to[num_addrs % 16];
		num_addrs /= 16;
		len++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padding = '0';
	if (flags & F_PLUS)
		extraC = '+', len++;
	else if (flags & F_SPACE)
		extraC = ' ', len++;

	ind++;

	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (write_pointer(buffer, ind, len,
		width, flags, padding, extraC, padding_start));
}

/**
 * print_non_printable - Prints ascii codes in hexa of non printable chars
 * @types: List of arguments given
 * @buffer: A Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: gets the width
 * @precision: Precision specification
 * @size: The Size specifier
 *
 * Return: Number of chars printed
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str = va_arg(types, char *);
	int j = 0, off_set = 0;

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[j] != '\0')
	{
		if (is_printable(str[j]))
			buffer[j + off_set] = str[j];
		else
			off_set += append_hexa_code(str[j], buffer, j + off_set);

		j++;
	}

	buffer[j + off_set] = '\0';

	return (write(1, buffer, j + off_set));
}

/**
 * print_reverse - Prints reverse string to the console screen
 * @types: List of arguments given
 * @buffer: A Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: gets the width
 * @precision: Precision specification
 * @size: A Size specifier
 *
 * Return: Numbers of chars printed
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int j, count = 0;
	char *str;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (j = 0; str[j]; j++)
		;

	for (j = j - 1; j >= 0; j--)
	{
		char z = str[j];

		write(1, &z, 1);
		count++;
	}
	return (count);
}

/**
 * print_rot13string - Print a string in rot13.
 * @types: List of arguments
 * @buffer: A Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: gets the width
 * @precision: Precision specification
 * @size: A Size specifier
 *
 * Return: Numbers of chars printed
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int m, n;
	char y;
	char *str;
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (m = 0; str[m]; m++)
	{
		for (n = 0; in[n]; n++)
		{
			if (in[n] == str[m])
			{
				y = out[n];

				write(1, &y, 1);
				count++;
				break;
			}
		}
		if (!in[n])
		{
			y = str[m];
			write(1, &y, 1);
			count++;
		}
	}
	return (count);
}
