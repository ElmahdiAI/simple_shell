#include "shell.h"

/**
 *_strtok_r - tokenizes a string
 *@str: string to be tokenized
 *@delim: delimiter to be used to tokenize the string
 *@next: pointer to be used to keep track of the next token
 *Return: The next available token
 */
char *_strtok_r(char *str, char *delim, char **next)
{
	char *end;

	if (str == NULL)
		str = *next;
	if (*str == '\0')
	{
		*next = str;
		return (NULL);
	}
	str += _strspn(str, delim);
	if (*str == '\0')
	{
		*next = str;
		return (NULL);
	}
	end = str + _strcspn(str, delim);
	if (*end == '\0')
	{
		*next = end;
		return (str);
	}
	*end = '\0';
	*next = end + 1;
	return (str);
}

/**
 * _atoi - changes a string to an integer
 * @str: the string to be changed
 *
 * Return: the converted int
 */
int _atoi(char *str)
{
	unsigned int n = 0;

	do {
		if (*str == '-')
			return (-1);
		else if ((*str < '0' || *str > '9') && *str != '\0')
			return (-1);
		else if (*str >= '0'  && *str <= '9')
			n = (n * 10) + (*str - '0');
		else if (n > 0)
			break;
	} while (*str++);
	return (n);
}

/**
 * comment - ignores everything after a '#' char
 * @str: input to be used
 * Return: Nothing
 */
void comment(char *str)
{
	int i = 0;

	if (str[i] == '#')
		str[i] = '\0';
	while (str[i] != '\0')
	{
		if (str[i] == '#' && str[i - 1] == ' ')
			break;
		i++;
	}
	str[i] = '\0';
}

/**
 *_strcpy - copies a string to another buffer
 *@src: source to copy from
 *@dest: destination to copy to
 * Return: Nothing
 */
void _strcpy(char *src, char *dest)
{
	int i = 0;

	for (; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
}

/**
 *_strlen - counts string length
 *@str: string to be counted
 * Return: length of the string
 */
int _strlen(char *str)
{
	int len = 0;

	if (str == NULL)
		return (len);
	for (; str[len] != '\0'; len++)
		;
	return (len);
}
