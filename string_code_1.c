#include "shell.h"

/**
 * _strlen - ahju
 * @s: ahju
 * Return: ahju
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
 * _strcmp - ahju
 * @s_1: ahju
 * @s_2: ahju
 * Return: ahju
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
 * starts_with - ahju
 * @haystack: ahju
 * @needle: ahju
 *
 * Return: ahju
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - ahju
 * @dest: ahju
 * @src: ahju
 * Return: ahju
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
