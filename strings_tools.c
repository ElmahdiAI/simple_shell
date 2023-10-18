#include "shell.h"

/**
 *_strcmp - compare two strings
 *@str1: first string to be compared
 *@str2: second string to be compared
 *
 * Return: difference of the two strings
 */
int _strcmp(char *str1, char *str2)
{
	int i = 0;

	while (str1[i] != '\0')
	{
		if (str1[i] != str2[i])
			break;
		i++;
	}
	return (str1[i] - str2[i]);
}

/**
 *_strcat - concatenates two strings
 *@dest: string to be concatenated to
 *@src:  string to concatenate
 * Return: address of the new string
 */
char *_strcat(char *dest, char *src)
{
	char *new_str =  NULL;
	int len_dest = _strlen(dest);
	int len_src = _strlen(src);

	new_str = malloc(sizeof(*new_str) * (len_dest + len_src + 1));
	_strcpy(dest, new_str);
	_strcpy(src, new_str + len_dest);
	new_str[len_dest + len_src] = '\0';
	return (new_str);
}

/**
 *_strspn - gets the length of a prefix substring
 *@str1: string to be searched
 *@str2: string to be used
 *Return: number of bytes in the initial segment of 5 which are part of accept
 */
int _strspn(char *str1, char *str2)
{
	int i = 0;
	int match = 0;

	while (str1[i] != '\0')
	{
		if (_strchr(str2, str1[i]) == NULL)
			break;
		match++;
		i++;
	}
	return (match);
}

/**
 *_strcspn - computes segment of str1 which consists of characters not in str2
 *@str1: string to be searched
 *@str2: string to be used
 *Return: index at which a char in str1 exists in str2
 */
int _strcspn(char *str1, char *str2)
{
	int len = 0, i;

	for (i = 0; str1[i] != '\0'; i++)
	{
		if (_strchr(str2, str1[i]) != NULL)
			break;
		len++;
	}
	return (len);
}

/**
 *_strchr - locates a char in a string
 *@str: string to be searched
 *@char: char to be checked
 *Return: pointer to the first occurence of c in s
 */
char *_strchr(char *str, char char)
{
	int i = 0;

	for (; str[i] != char && str[i] != '\0'; i++)
		;
	if (str[i] == char)
		return (str + i);
	else
		return (NULL);
}
