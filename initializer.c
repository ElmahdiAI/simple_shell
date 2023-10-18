#include "shell.h"

/**
 * initializer - starts executing everything
 * @current_cmd: try to check current token
 * @type_cmd: parse token
 *
 * Return: void function
 */

void initializer(char **current_cmd, int type_cmd)
{
	pid_t PID;

	if (type_cmd == EXTERNAL_CMD || type_cmd == PATH_CMD)
	{
		PID = fork();
		if (PID == 0)
			execute_cmd(current_cmd, type_cmd);
		else
		{
			waitpid(PID, &status, 0);
			status >>= 8;
		}
	}
	else
		execute_cmd(current_cmd, type_cmd);
}
