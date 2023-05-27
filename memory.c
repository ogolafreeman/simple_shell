#include "shell.h"

/**
 * bfree - ahju
 * @ptr: ahju
 * Return: ahju
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		/*frees first pointer*/
		free(*ptr);
		*ptr = NULL;
		/*returns 1 if pointer is null*/
		return (1);
	}
	return (0);
}
