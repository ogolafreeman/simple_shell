#include "shell.h"

/**
 * **strtow - the function that splits a string into words.
 * @str: an input string
 * @d: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtow(char *str, char *d)
{
	int x, j, l, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (x = 0; str[x] != '\0'; x++)
		if (!is_delim(str[x], d) && (is_delim(str[x + 1], d) || !str[x + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (x = 0, j = 0; j < numwords; j++)
	{
		while (is_delim(str[x], d))
			x++;
		l = 0;
		while (!is_delim(str[x + l], d) && str[x + l])
			l++;
		s[j] = malloc((l + 1) * sizeof(char));
		if (!s[j])
		{
			for (l = 0; l < j; l++)
				free(s[l]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < l; m++)
			s[j][m] = str[x++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}

/**
 * **strtow2 - the function does splits a string into words
 * @str: an input string
 * @d: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char d)
{
	int x, j, l, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (x = 0; str[x] != '\0'; x++)
		if ((str[x] != d && str[x + 1] == d) ||
		    (str[x] != d && !str[x + 1]) || str[x + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (x = 0, j = 0; j < numwords; j++)
	{
		while (str[x] == d && str[x] != d)
			x++;
		l = 0;
		while (str[x + l] != d && str[x + l] && str[x + l] != d)
			l++;
		s[j] = malloc((l + 1) * sizeof(char));
		if (!s[j])
		{
			for (l = 0; l < j; l++)
				free(s[l]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < l; m++)
			s[j][m] = str[x++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}

