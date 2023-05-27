#include "shell.h"

/**
 * _strlen - ahju
 * @s: ahju
 * Return: ahju
 */
int _strlen(char *s)
{
	int i = 0;

	/*returns 0 if pointer is null*/
	if (!s)
		return (0);

	/*while loop*/
	while (*s++)
		i++;
	return (i);
}

/**
 * _strcmp - ahju
 * @s1: ahju
 * @s2: ahju
 * Return: ahju
 */
int _strcmp(char *s1, char *s2)
{
	/*while loop*/
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	/*if statement*/
	if (*s1 == *s2)
		return (0);
	/*els statement*/
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - ahju
 * @haystack: ahju
 * @needle: ahju
 * Return: ahju
 */
char *starts_with(const char *haystack, const char *needle)
{
	/*while statement*/
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
	char *ret = dest;

	/*while loop*/
	while (*dest)
		dest++;
	/*while loop*/
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	/*return ret*/
	return (ret);
}
