#include "shell.h"

/**
 * uninteractive - handles uninteractive mode
 * Return: Nothing
 */
void uninteractive(void)
{
	char **cmd = NULL;
	int i, type_cmd = 0;
	size_t n = 0;
	vars global_var = {
		NULL, NULL, NULL, NULL, 0};

	if (!(isatty(STDIN_FILENO)))
	{
		while (getline(&global_var.line, &n, stdin) != -1)
		{
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
		exit(global_var.status);
	}
}
