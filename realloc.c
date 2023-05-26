#include "shell.h"

/**
 **_memset - the function fills memory with a constant byte
 *@t: the pointer to the memory area
 *@bc: the byte to fill *s with
 *@nx: the amount of bytes to be filled
 *Return: (s) a pointer to the memory area s
 */
char *_memset(char *t, char bc, unsigned int nx)
{
	unsigned int x;

	for (x = 0; x < nx; x++)
		t[x] = bc;
	return (t);
}

/**
 * ffree - the function releases a string of strings
 * @pq: string of strings
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
 * _realloc - the function that reallocates a block of memory
 * @pointer: A pointer to previous malloc'ated block
 * @old_size: A byte size of previous block
 * @new_size: A byte size of new block
 *
 * Return: Always pointer to da ol'block nameen.
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
