#include "shell.h"

/**
 * exit_shell - exits the shell
 *
 * @datash: data relevant (status and args)
 * Return: 0 on success.
 */
int exit_shell(list_shell *datash)
{
	unsigned int istatus;
	int is_digit;
	int str_len;
	int big;

	if (datash->args[1] != NULL)
	{
		istatus = _atoi(datash->args[1]);
		is_digit = _isdigit(datash->args[1]);
		str_len = _strlen(datash->args[1]);
		big = istatus > (unsigned int)INT_MAX;
		if (!is_digit || str_len > 10 || big)
		{
			get_error(datash, 2);
			datash->status = 2;
			return (1);
		}
		datash->status = (istatus % 256);
	}
	return (0);
}
