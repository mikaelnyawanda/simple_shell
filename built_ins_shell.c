#include "shell.h"

/**
 * get_builtin - builtin that pais the command in the arg
 * @cmd: command
 * Return: function pointer of the builtin command
 */
int (*get_builtin(char *cmd))(list_shell *)
{
	builtin_st built[] = {
		{ "env", _environ },
		{ "exit", exit_shell },
		{ "setenv", _setenv },
		{ "unsetenv", _unsetenv },
		{ "cd", cd_shell },
		{ "help", get_help },
		{ NULL, NULL }
	};
	int i;

	for (i = 0; built[i].name; i++)
	{
		if (_strcmp(built[i].name, cmd) == 0)
			break;
	}

	return (built[i].f);
}
