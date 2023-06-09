#include "shell.h"

/**
 **_memset -ahju
 *@s: ahju
 *@b: ahju
 *@n: ahju
 *Return: ahju
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	/*for loop*/
	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * ffree - ahju
 * @pp: ahju
 */
void ffree(char **pp)
{
	char **a = pp;

	/*if statement*/
	if (!pp)
		/*breaks if pointer is null*/
		return;
	/*while loop*/
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc - ahju
 * @ptr: ahju
 * @old_size: ahju
 * @new_size: ahju
 * Return: ahju
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	/*if statement*/
	if (!ptr)
		return (malloc(new_size));
	/*if statement*/
	if (!new_size)
		return (free(ptr), NULL);
	/*if statement*/
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	/*if statement*/
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	/*while loop*/
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
