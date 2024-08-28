#include "shell.h"

/**
 * cmp_env_name - compares env variables names
 * with the name passed.
 * @nenv: name of the environment variable
 * @name: name passed
 *
 * Return: 0 if are not equal. Another value if they are.
 */
int cmp_env_name(const char *nenv, const char *name)
{
	int i;

	for (i = 0; nenv[i] != '='; i++)
	{
		if (nenv[i] != name[i])
		{
			return (0);
		}
	}

	return (i + 1);
}

/**
 * _getenv - get an environment variable
 * @name: name of the environment variable
 * @_env: environment variable
 *
 * Return: value of the environment variable if is found.
 * In other case, returns NULL.
 */
char *_getenv(const char *name, char **_env)
{
	char *ptr_env;
	int i, move;

	/* Initialize ptr_env value */
	ptr_env = NULL;
	move = 0;
	/* Compare all environment variables */
	/* environ is declared in the header file */
	for (i = 0; _env[i]; i++)
	{
		/* If name and env are equal */
		move = cmp_env_name(_env[i], name);
		if (move)
		{
			ptr_env = _env[i];
			break;
		}
	}

	return (ptr_env + move);
}

/**
 * _environ - prints the evironment variables
 *
 * @datash: data relevant.
 * Return: 1 on success.
 */
int _environ(list_shell *datash)
{
	int i, j;

	for (i = 0; datash->_env[i]; i++)
	{

		for (j = 0; datash->_env[i][j]; j++)
			;

		write(STDOUT_FILENO, datash->_env[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	datash->status = 0;

	return (1);
}
