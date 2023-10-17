#include "main.h"
/**
 * handle_print - function that prints arguments based on it type
 * @fmt: arguments that Formats string in which it will print
 * @list: arguments where a lsit of arguments is printed
 * @ind:  argument ind.
 * @buffer: argument buffer array to handle print.
 * @flags: Calculates active flags
 * @width:  argumet get width.
 * @precision: argument precision needs
 * @size:  argument size specification
 * Return:  returns 1 or 2;
 */
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int j, notknowLen = 0, prntedChar = -1;
	fmt_t fmt_types[] = {
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'c', print_char}, {'s', print_string}, {'%', print_percent}
	};
	for (j = 0; fmt_types[j].fmt != '\0'; j++)
		if (fmt[*ind] == fmt_types[j].fmt)
			return (fmt_types[j].fn(list, buffer, flags, width, precision, size));

	if (fmt_types[j].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		notknowLen += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			notknowLen += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		notknowLen += write(1, &fmt[*ind], 1);
		return (notknowLen);
	}
	return (prntedChar);
}

