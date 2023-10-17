#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - This is the Printf function
 * @format: The format specifier
 *
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	char buffer[BUFF_SIZE];
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	int j, printing_chars = 0, printing = 0;

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (j = 0; format && format[j] != '\0'; j++)
	{
		if (format[j] != '%')
		{
			buffer[buff_ind++] = format[j];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printing_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &j);
			width = get_width(format, &j, list);
			precision = get_precision(format, &j, list);
			size = get_size(format, &j);
			++j;
			printing = handle_print(format, &j, list, buffer,
				flags, width, precision, size);
			if (printing == -1)
				return (-1);
			printing_chars += printing;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printing_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if does exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 *
 * Return: void
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
