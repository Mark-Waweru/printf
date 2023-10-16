#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
/**
 * _strncpy - copies a string
 * @dest: The destination of copy
 * @src: The source of the character to be copied
 * @n: The number of bytes to copy
 *
 * Return: pointer dest
 */
char *_strncpy(char *dest, const char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}

	for (; i < n; i++)
	{
		dest[i] = '\0';
	}

	return (dest);
}

/**
 * _printf - functions to print %s,%c, % format speciers
 * @format: is a character string
 * Return: returns an integer
 */
int _printf(const char *format, ...)
{
	char character;
	char buffer[BUFFER_SIZE];
	int buffer_index = 0;
	int charCount = 0;
	int len;
	int i;
	const char *string;
	va_list args;

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				character = va_arg(args, int);
				buffer[buffer_index++] = character;
				charCount++;
			}
			else if (format[i] == 's')
			{
				string = va_arg(args, const char *);
				len = strlen(string);
				_strncpy(buffer + buffer_index, string, BUFFER_SIZE - buffer_index);
				buffer_index += len < BUFFER_SIZE - buffer_index ?
				len : BUFFER_SIZE - buffer_index;
				charCount += len;
			}
			else if (format[i] == '%')
			{
				buffer[buffer_index++] = '%';
				charCount++;
			}
			if (buffer_index >= BUFFER_SIZE - 1)
			{
				buffer[BUFFER_SIZE - 1] = '\0';
				write(STDOUT_FILENO, buffer, buffer_index);
				buffer_index = 0;
			}
		}
	}
	buffer[buffer_index] = '\0';
	write(STDOUT_FILENO, buffer, buffer_index);
	va_end(args);
	return (charCount);
}
