#include "shell.h"

/**
 * **strtow - ahju
 * @str: ahju
 * @d: ahju
 * Return: ahju
 */

char **strtow(char *str, char *d)
{
	int i, j, k, m, numwords = 0;
	char **s;

	/*if statement*/
	if (str == NULL || str[0] == 0)
		return (NULL);
	/*if statement*/
	if (!d)
		d = " ";
	/*if statement*/
	for (i = 0; str[i] != '\0'; i++)
		if (!is_delim(str[i], d) && (is_delim(str[i + 1], d) || !str[i + 1]))
			numwords++;
	/*if statement*/
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	/*for loop*/
	for (i = 0, j = 0; j < numwords; j++)
	{
		/*while loop*/
		while (is_delim(str[i], d))
			i++;
		k = 0;
		while (!is_delim(str[i + k], d) && str[i + k])
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}

/**
 * **strtow2 - ahju
 * @str: ahju
 * @d: ahju
 * Return: ahju
 */
char **strtow2(char *str, char d)
{
	int i, j, k, m, numwords = 0;
	char **s;

	/*if statement*/
	if (str == NULL || str[0] == 0)
		return (NULL);
	/*if statement*/
	for (i = 0; str[i] != '\0'; i++)
		if ((str[i] != d && str[i + 1] == d) ||
		    (str[i] != d && !str[i + 1]) || str[i + 1] == d)
			numwords++;
	/*if statement*/
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	/*if statement*/
	for (i = 0, j = 0; j < numwords; j++)
	{
		/*if statement*/
		while (str[i] == d && str[i] != d)
			i++;
		k = 0;
		/*if statement*/
		while (str[i + k] != d && str[i + k] && str[i + k] != d)
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		/*if statement*/
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}
