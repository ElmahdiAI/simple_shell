#include "shell.h"

/**
 * main - the main shell code
 * @argc: number of arguments passed
 * @argv: program arguments to be parsed
 * Prints error on Failure
 * Return: 0 on success
 */
int main(int argc __attribute__((unused)), char **argv)
{
	char **cmd = NULL;
	int i, type_cmd = 0;
	size_t n = 0;
	vars global_var = {
		NULL, NULL, NULL, NULL, 0};

	signal(SIGINT, ctrl_c_handler);
	global_var.shell_name = argv[0];
	while (1)
	{
		uninteractive();
		_print(" $GAZA$ ", STDOUT_FILENO);
		if (getline(&global_var.line, &n, stdin) == -1)
		{
			free(global_var.line);
			exit(global_var.status);
		}
		remove_newline(global_var.line);
		comment(global_var.line);
		global_var.commands = tokenizer(global_var.line, ";");

		for (i = 0; global_var.commands[i] != NULL; i++)
		{
			cmd = tokenizer(global_var.commands[i], " ");
			if (cmd[0] == NULL)
			{
				free(cmd);
				break;
			}
			type_cmd = parse_cmd(cmd[0]);

			initializer(cmd, type_cmd);
			free(cmd);
		}
		free(global_var.commands);
	}
	free(global_var.line);
	return (global_var.status);
}
