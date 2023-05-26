#include "shell.h"

/**
 * bfree - ahju
 * @pointer: ahju
 *
 * Return: ahju
 */
int bfree(void **pointer)
{
	if (pointer && *pointer)
	{
		free(*pointer);
		*pointer = NULL;
		return (1);
	}
	return (0);
}
