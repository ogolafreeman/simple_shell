#include "shell.h"

/**
 * _eputchar - writes the character c to stderr
 * @a: The character to print
 *
 * Return: On success 1. -1 is returned,
 * and errno is set appropriately.
 */
int _eputchar(char a)
{
	static int j;
	static char buf[WRITE_BUF_SIZE];

	if (a == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
		write(2, buf, j);
		a = 0;
	}
	if (a != BUF_FLUSH)
		buf[j++] = a;
	return (1);
}

/**
 * _putfd - writes the character c to given fd
 * @a: The character to print
 * @fd: The filedescriptor to write to
 *
 * Return: On success 1.
 * -1 is returned, and errno is set appropriately.
 */
int _putfd(char a, int fd)
{
	static int j;
	static char buf[WRITE_BUF_SIZE];

	if (a == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
		write(fd, buf, j);
		i = 0;
	}
	if (a != BUF_FLUSH)
		buf[j++] = a;
	return (1);
}

/**
 *_eputs - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
	int j = 0;

	if (!str)
		return;
	while (str[j] != '\0')
	{
		_eputchar(str[j]);
		j++;
	}
}

/**
 *_putsfd - prints an input string
 * @str: the string to be printed
 * @fd: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _putsfd(char *str, int fd)
{
	int j = 0;

	if (!str)
		return (0);
	while (*str)
	{
		j += _putfd(*str++, fd);
	}
	return (j);
}
