#include "shell.h"

/**
 * interactive - the function returns true if shell is interactive mode
 * @info: struct address
 *
 * Return: 1 when interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 *_isalpha - the function checks for alphabetic character
 *@alph: The character to input
 *Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalpha(int alph)
{
	if ((alph >= 'a' && alph <= 'z') || (alph >= 'A' && alph <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - this function converts a string to an integer
 *@t: string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *t)
{
	int j, sign = 1, flags = 0, outp;
	unsigned int rslt = 0;

	for (i = 0;  t[j] != '\0' && flags != 2; i++)
	{
		if (t[j] == '-')
			sign *= -1;

		if (t[j] >= '0' && t[j] <= '9')
		{
			flags = 1;
			rslt *= 10;
			rslt += (t[j] - '0');
		}
		else if (flags == 1)
			flags = 2;
	}

	if (sign == -1)
		outp = -rslt;
	else
		outp = rslt;

	return (outp);
}
/**
 * is_delim - checks if character is a delimeter
 * @d: the char to check
 * @delims: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char d, char *delims)
{
	while (*delims)
		if (*delims++ == d)
			return (1);
	return (0);
}
