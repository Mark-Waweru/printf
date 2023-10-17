#include "main.h"

void print_buffer(char buffer[], int *buff_ind);
/**
 * print_buffer - function to print the buffer
 * @buffer: arguments to shows the arrays
 * @buff_ind:  arguments to show index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}




/**
 * _printf - function to show %,c, s
 * @format: the strings taged inside the format string
 * Return: the printed chaeracters.
 */
int _printf(const char *format, ...)
{
	int j;
    int printer_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
    int  printer = 0;
    va_list list;
	char buffer[BUFFER_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (j = 0; format && format[j] != '\0'; j++)
	{
		if (format[j] != '%')
		{
			buffer[buff_ind++] = format[j];
			if (buff_ind == BUFFER_SIZE)
			{
				print_buffer(buffer, &buff_ind);
				printer_chars++;
			}
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &j);
			width = get_width(format, &j, list);
			precision = get_precision(format, &j, list);
			size = get_size(format, &j);
			++j;
			printer = handle_print(format, &j, list, buffer,
				flags, width, precision, size);
			if (printer == -1)
				return (-1);
			printer_chars += printer;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printer_chars);
}


