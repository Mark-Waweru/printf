#include "main.h"
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

/**
 * int_to_str - converts integer variables to string
 * @buffer: The string character to store the integer converted
 * @number: The integer to be converted
 *
 * Return: The result
 */
int int_to_str(char *buffer, int number)
{
	return (snprintf(buffer, BUFFER_SIZE, "%d", number));
}

/**
 * _printf - Prints integers format specifiers
 * @format: The format specifier
 *
 * Return: The output in the stdout
 */
int _printf(const char *format, ...)
{
	int written;
	char buffer[BUFFER_SIZE];
	int buffer_index = 0;
	int charCount = 0;
	int number;
	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%' && (*(format + 1) == 'd' || *(format + 1) == 'i'))
		{
			number = va_arg(args, int);
			written = int_to_str(buffer + buffer_index, number);
			buffer_index += (written < BUFFER_SIZE - buffer_index) ?
			written : (BUFFER_SIZE - buffer_index);
			charCount += written;
			format += 2;
		}
		else
		{
			buffer[buffer_index++] = *format;
			charCount++;
			format++;
		}

		if (buffer_index >= BUFFER_SIZE - 1)
		{
			buffer[BUFFER_SIZE - 1] = '\0';
			write(STDOUT_FILENO, buffer, buffer_index);
			buffer_index = 0;
		}
	}
	buffer[buffer_index] = '\0';
	write(STDOUT_FILENO, buffer, buffer_index);
	va_end(args);
	return (charCount);
}
