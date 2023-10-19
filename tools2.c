#include "shell.h"

/**
 * tokenizer - tokenizes input and stores it into an array
 *@str: input to be parsed
 *@delim: delimiter to be used, needs to be one character string
 *Return: array of tokens
 */
char **tokenizer(char *str, char *delim)
{
	int num_delim = 0;
	char **av = NULL;
	char *token = NULL;
	char *save_ptr = NULL;

	token = _strtok_r(str, delim, &save_ptr);
	while (token != NULL)
	{
		av = _realloc(av, sizeof(*av) * num_delim, sizeof(*av) * (num_delim + 1));
		av[num_delim] = token;
		token = _strtok_r(NULL, delim, &save_ptr);
		num_delim++;
	}
	av = _realloc(av, sizeof(*av) * num_delim, sizeof(*av) * (num_delim + 1));
	av[num_delim] = NULL;
	return (av);
}

/**
 *_print - prints a string to stdout
 *@str: string to be printed
 *@stream: stream to print out to
 *
 *Return: nothing
 */
void _print(char *str, int stream)
{
	int i = 0;

	for (; str[i] != '\0'; i++)
		write(stream, &str[i], 1);
}

/**
 *remove_newline - removes new line from a string
 *@str: string to be used
 *Return: void
 */

void remove_newline(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			break;
		i++;
	}
	str[i] = '\0';
}

/**
 * _realloc - reallocates a memory block
 * @ptr: pointer to the memory previously allocated with a call to malloc
 * @old_size: size of ptr
 * @new_size: size of the new memory to be allocated
 * Return: pointer to the address of the new memory block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *temp;
	unsigned int i;

	if (ptr == NULL)
	{
		temp = malloc(new_size);
		return (temp);
	}
	else if (new_size == old_size)
		return (ptr);
	else if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	else
	{
		temp = malloc(new_size);
		if (temp != NULL)
		{
			for (i = 0; i < min(old_size, new_size); i++)
				*((char *)temp + i) = *((char *)ptr + i);
			free(ptr);
			return (temp);
		}
		else
			return (NULL);
	}
}

/**
 * ctrl_c_handler - handles the signal raised by CTRL-C
 * @ctrl: signal number
 * Return: void
 */
void ctrl_c_handler(int ctrl)
{
	if (ctrl == SIGINT)
		print("\n($) ", STDIN_FILENO);
}
