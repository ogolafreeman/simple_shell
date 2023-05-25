#include "shell.h"

/**
 * bfree - ahju
 * @ptr: ahju
 *
 * Return: ahju
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
