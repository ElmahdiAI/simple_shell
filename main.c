#include "shell.h"
char **commands = NULL;
char *line = NULL;
char *shell_name = NULL;
int status = 0;
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

	signal(SIGINT, ctrl_c_handler);
	shell_name = argv[0];
	while (1)
	{
		uninteractive();
		_print(" $GAZA$ ", STDOUT_FILENO);
		if (getline(&line, &n, stdin) == -1)
		{
			free(line);
			exit(status);
		}
		remove_newline(line);
		comment(line);
		commands = tokenizer(line, ";");

		for (i = 0; commands[i] != NULL; i++)
		{
			cmd = tokenizer(commands[i], " ");
			if (cmd[0] == NULL)
			{
				free(cmd);
				break;
			}
			type_cmd = parse_cmd(cmd[0]);

			initializer(cmd, type_cmd);
			free(cmd);
		}
		free(commands);
	}
	free(line);
	return (status);
}
