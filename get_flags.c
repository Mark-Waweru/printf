#include "main.h"

/**
<<<<<<< HEAD
 * get_flags - function to calcaclute flags
 * @format: aguments to print the fommatted strings to calaculate
 * @i: argument that that takes a  i active
 * Return: returns a flags
 */
int get_flags(const char *format, int *i)
{
	int flags = 0;
	int i, cur_k;
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};

	for (cur_k = *i + 1; format[cur_k] != '\0'; cur_k++)
	{
		for (i = 0; FLAGS_CH[i] != '\0'; i++)
			if (format[cur_k] == FLAGS_CH[i])
			{
				flags |= FLAGS_ARR[i];
				break;
			}

		if (FLAGS_CH[i] == 0)
			break;
	}

	*i = cur_k - 1;

	return (flags);
}

=======
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
>>>>>>> 674f6f738b65e24bd9e79645c3e0c569cbcf57f1
