#include "shell.h"

/**
 **_memset - ahju
 *@t: ahju
 *@bc:ahju
 *@nx: ahju
 *Return: ahju
 */
char *_memset(char *t, char bc, unsigned int nx)
{
	unsigned int x;

	for (x = 0; x < nx; x++)
		t[x] = bc;
	return (t);
}

/**
 * ffree - ahju
 * @pq: ahju
 */
void ffree(char **pq)
{
	char **b = pq;

	if (!pq)
		return;
	while (*pq)
		free(*pq++);
	free(b);
}

/**
 * _realloc - ahju
 * @pointer: ahju
 * @old_size: ahju
 * @new_size: ahju
 *
 * Return: ahju
 */
void *_realloc(void *pointer, unsigned int old_size, unsigned int new_size)
{
	char *q;

	if (!pointer)
		return (malloc(new_size));
	if (!new_size)
		return (free(pointer), NULL);
	if (new_size == old_size)
		return (pointer);

	q = malloc(new_size);
	if (!q)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		q[old_size] = ((char *)pointer)[old_size];
	free(pointer);
	return (q);
}
