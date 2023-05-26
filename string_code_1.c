#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *s)
{
	int x = 0;

	if (!s)
		return (0);

	while (*s++)
		x++;
	return (x);
}

/**
 * _strcmp - this function performs lexicogarphic
 * comparison of two strangs.
 * @s_1: the first strang
 * @s_2: the second strang
 *
 * Return: negative if s_1 < s_2,
 * positive if s_1 > s_2, zero if s_1 == s_2
 */
int _strcmp(char *s_1, char *s_2)
{
	while (*s_1 && *s_2)
	{
		if (*s_1 != *s_2)
			return (*s_1 - *s_2);
		s_1++;
		s_2++;
	}
	if (*s_1 == *s_2)
		return (0);
	else
		return (*s_1 < *s_2 ? -1 : 1);
}

/**
 * starts_with - the function checks if needle starts with haystack
 * @haystack: the string to search
 * @needle: the substring to find
 *
 * Return: address of next char of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *rat = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (rat);
}
