#include "shell.h"

/**
 * list_len - ahju
 * @d: ahju
 * Return: size of list
 */
size_t list_len(const list_t *d)
{
	size_t x = 0;

	while (d)
	{
		d = d->next;
		x++;
	}
	return (x);
}

/**
 * list_to_strings - ahju
 * @head:  ahju
 * Return: ahju
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t x = list_len(head), m;
	char **strs;
	char *str;

	if (!head || !x)
		return (NULL);
	strs = malloc(sizeof(char *) * (x + 1));
	if (!strs)
		return (NULL);
	for (x = 0; node; node = node->next, x++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (m = 0; m < x; m++)
				free(strs[m]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[x] = str;
	}
	strs[x] = NULL;
	return (strs);
}


/**
 * print_list - ahju
 * @h: ahju
 * Return:ahju
 */
size_t print_list(const list_t *h)
{
	size_t t = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		t++;
	}
	return (t);
}

/**
 * node_starts_with - ahju
 * @node: ahju
 * @prefix: ahju
 * @d: ahju
 * Return: ahju
 */
list_t *node_starts_with(list_t *node, char *prefix, char d)
{
	char *q = NULL;

	while (node)
	{
		q = starts_with(node->str, prefix);
		if (q && ((d == -1) || (*q == d)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - ahju
 * @head: ahju
 * @node: ahju
 * Return: ahju
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t x = 0;

	while (head)
	{
		if (head == node)
			return (x);
		head = head->next;
		x++;
	}
	return (-1);
}
