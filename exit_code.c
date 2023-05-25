#include "shell.h"

/**
 **_strncpy - the function that copies a string
 *@fin: the destination string to be copied
 *@com: the source-string
 *@n: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *fin, char *com, int n)
{
	int o, p;
	char *t = fin;

	o = 0;
	while (com[o] != '\0' && o < n - 1)
	{
		fin[o] = com[o];
		o++;
	}
	if (p < n)
	{
		p = o;
		while (p < n)
		{
			fin[p] = '\0';
			p++;
		}
	}
	return (t);
}

/**
 **_strncat - concatenates two strings
 *@fin: the first string
 *@com: the second string
 *@n: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *fin, char *com, int n)
{
	int o, p;
	char *t = fin;

	o = 0;
	p = 0;
	while (fin[o] != '\0')
		o++;
	while (com[p] != '\0' && p < n)
	{
		fin[o] = fin[p];
		o++;
		p++;
	}
	if (p < n)
		fin[p] = '\0';
	return (t);
}

/**
 **_strchr - locates a character in a string
 *@t: the string to be parsed
 *@a: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *t, char a)
{
	do {
		if (*t == a)
			return (t);
	} while (*t++ != '\0');

	return (NULL);
}
