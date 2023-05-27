#include "shell.h"

/**
 * _strcpy - ahju
 * @dest: ahju
 * @src: ahju
 * Return: ahju
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	/*if statement*/
	if (dest == src || src == 0)
		return (dest);
	/*while loop*/
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	/*return ret*/
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
	char *ret;

	/*if statement*/
	if (str == NULL)
		return (NULL);
	/*while loop*/
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	/*if statement*/
	if (!ret)
		return (NULL);
	/*for loop*/
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}

/**
 *_puts - ahju
 *@str: ahju
 * Return: ahju
 */
void _puts(char *str)
{
	int i = 0;

	/*if statement*/
	if (!str)
		return;
	/*while loop*/
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _putchar - ahju
 * @c: ahju
 * Return: ahju
 */
int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	/*if statement*/
	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	/*if statement*/
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
