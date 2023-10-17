#include "main.h"

/**
 * get_flags - Calculates the active flags
 * @format: Formatted string in which to print the arguments
 * @i: taking a parameter.
 *
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
	int n, curr_j;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_j = *i + 1; format[curr_j] != '\0'; curr_j++)
	{
		for (n = 0; FLAGS_CH[n] != '\0'; n++)
			if (format[curr_j] == FLAGS_CH[n])
			{
				flags |= FLAGS_ARR[n];
				break;
			}
			if (FLAGS_CH[n] == 0)
			break;
	}

	*i = curr_j - 1;

	return (flags);
}
