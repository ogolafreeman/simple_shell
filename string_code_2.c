#include "shell.h"

/**
 * _strcpy -ahju
 * @dest: ahju
 * @src: ahju
 * Return: ahju
 */
char *_strcpy(char *dest, char *src)
{
	int x = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[x])
	{
		dest[x] = src[x];
		x++;
	}
	dest[x] = 0;
	return (dest);
}

/**
 * _strdup - ahju
 * @str: ahju
 * Return: ahju
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *rat;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	rat = malloc(sizeof(char) * (length + 1));
	if (!rat)
		return (NULL);
	for (length++; length--;)
		rat[length] = *--str;
	return (rat);
}

/**
 *_puts - ahju
 *@str: ahju
 * Return: ahju
 */
void _puts(char *str)
{
	int x = 0;

	if (!str)
		return;
	while (str[x] != '\0')
	{
		_putchar(str[x]);
		x++;
	}
}

/**
 * _putchar - ahju
 * @c: ahju
 * Return: ahju
 */
int _putchar(char c)
{
	static int x;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || x >= WRITE_BUF_SIZE)
	{
		write(1, buf, x);
		x = 0;
	}
	if (c != BUF_FLUSH)
		buf[x++] = c;
	return (1);
}
