#include "shell.h"

/**
 * _erratoi - ahju
 * @s: ahju
 * Return: ahju
 */
int _erratoi(char *s)
{
	int i = 0, unsigned long int result = 0;

	if (*s == '+')
		s++;
	/*for loop*/
	for (;  s[i] != '\0'; i++)
	{
		/*if atatement*/
		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result += (s[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		/*if statement*/
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - ahju
 * @info: ahju
 * @estr: ahju
 * Return:ahju
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - ahju
 * @input: ahju
 * @fd: ahju
 * Return: ahju
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	/*if statement*/
	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	/*if statement*/
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	/*if statement*/
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_number - ahju
 * @num: number
 * @base: base
 * @flags: ahju
 * Return: string
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	/*if statement*/
	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - ahju
 * @buf: ahju
 * Return: Always 0;
 */
void remove_comments(char *buf)
{
	int i;

	/*for loop*/
	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
}
