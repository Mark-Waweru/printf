#include "main.h"

/**
 * print_char - Prints a character given
 * @types: List of arguments given
 * @buffer: A Buffer array to handle print on screen
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: The Size specifier
 *
 * Return: Number of characters printed
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}

/**
 * print_string - Prints a string to the console
 * @types: List of the arguments given
 * @buffer: A Buffer array to handle print
 * @flags:  Calculates the active flags
 * @width: gets the width.
 * @precision: Precision specification
 * @size: The Size specifier
 *
 * Return: Number of chars printed
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str = va_arg(types, char *);
	int len = 0, j;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[len] != '\0')
		len++;

	if (precision >= 0 && precision < len)
		len = precision;
	if (width > len)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], len);
			for (j = width - len; j > 0; j--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (j = width - len; j > 0; j--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (width);
		}
	}

	return (write(1, str, len));
}

/**
 * print_percent - Prints a percent sign on the console screen
 * @types: List of arguments given
 * @buffer: A Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: gets the width.
 * @precision: Precision specification
 * @size: The Size specifier
 *
 * Return: Number of chars printed
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	return (write(1, "%%", 1));
}

/**
 * print_int - Print int
 * @types: List of arguments given
 * @buffer: A Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: gets the width.
 * @precision: Precision specification
 * @size: The Size specifier
 *
 * Return: Number of chars printed
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	long int m = va_arg(types, long int);
	int isNegative = 0;
	unsigned long int num;
	int j = BUFF_SIZE - 2;

	m = convert_size_number(m, size);

	if (m == 0)
		buffer[j--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)m;
	if (m < 0)
	{
		num = (unsigned long int)((-1) * m);
		isNegative = 1;
	}

	while (num > 0)
	{
		buffer[j--] = (num % 10) + '0';
		num /= 10;
	}

	j++;

	return (write_number(isNegative, j, buffer, flags, width, precision, size));
}

/**
 * print_binary - Prints an unsigned number to the console screen
 * @types: List of arguments given
 * @buffer: A Buffer array to handle print
 * @flags:  Calculates the active flags
 * @width: gets the width.
 * @precision: Precision specification
 * @size: A Size specifier
 *
 * Return: Numbers of char printed.
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int count;
	unsigned int p, q, j, sum;
	unsigned int b[32];

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	p = va_arg(types, unsigned int);
	q = 2147483648; /* (2 ^ 31) */
	b[0] = p / q;
	for (j = 1; j < 32; j++)
	{
		q /= 2;
		b[j] = (p / q) % 2;
	}
	for (j = 0, sum = 0, count = 0; j < 32; j++)
	{
		sum += b[j];
		if (sum || j == 31)
		{
			char z = '0' + b[j];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
