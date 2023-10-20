#include "shell.h"

/**
 *env - prints the current_environnement
 *@tokenized_cmd: command entered
 *Return: Nothing
 */
void env(char **tokenized_cmd __attribute__((unused)))
{
	int i;
	vars global_var = {
		NULL, NULL, NULL, NULL, 0};

	for (i = 0; global_var.environ[i] != NULL; i++)
	{
		_print(global_var.environ[i], STDOUT_FILENO);
		_print("\n", STDOUT_FILENO);
	}
}

/**
 * quit - exits the shell
 * @tokenized_cmd: command entered
 * Return: Nothing
 */
void quit(char **tokenized_cmd)
{
	int num_token = 0, arg;
	vars global_var = {
		NULL, NULL, NULL, NULL, 0};

	for (; tokenized_cmd[num_token] != NULL; num_token++)
		;
	if (num_token == 1)
	{
		free(tokenized_cmd);
		free(global_var.line);
		free(global_var.commands);
		exit(global_var.status);
	}
	else if (num_token == 2)
	{
		arg = _atoi(tokenized_cmd[1]);
		if (arg == -1)
		{
			_print(global_var.shell_name, STDERR_FILENO);
			_print(": 1: exit: Illegal number: ", STDERR_FILENO);
			_print(tokenized_cmd[1], STDERR_FILENO);
			_print("\n", STDERR_FILENO);
			global_var.status = 2;
		}
		else
		{
			free(global_var.line);
			free(tokenized_cmd);
			free(global_var.commands);
			exit(arg);
		}
	}
	else
		_print("$: exit doesn't take more than one argument\n", STDERR_FILENO);
}
