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

	if (!(isatty(STDIN_FILENO)))
	{
		while (getline(&line, &n, stdin) != -1)
		{
			remove_newline(line);
			remove_comment(line);
			commands = tokenizer(line, ";");
			for (i = 0; commands[i] != NULL; i++)
			{
				cmd = tokenizer(commands[i], " ");
				if (cmd[0] == NULL)
				{
					free(cmd);
					break;
				}
				type_cmd = parse_command(cmd[0]);
				initializer(cmd, type_cmd);
				free(cmd);
			}
			free(commands);
		}
		free(line);
		exit(status);
	}
}
