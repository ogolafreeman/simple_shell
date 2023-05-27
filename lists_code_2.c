#include "shell.h"

/**
 * list_len - ahju
 * @h: ahju
 * Return: ahju
 */
size_t list_len(const list_t *h)
{
	size_t i = 0;

	/*while loop*/
	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * list_to_strings - ahju
 * @head: ahju
 * Return: ahju
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t i = list_len(head), j;
	char **strs;
	char *str;

	/*if statement*/
	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	/*if statement*/
	if (!strs)
		return (NULL);
	/*for loop*/
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		/*if statement*/
		if (!str)
		{
			/*for loop*/
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}


/**
 * print_list - ahju
 * @h: ahju
 * Return: ahju
 */
size_t print_list(const list_t *h)
{
	size_t i = 0;

	/*while loop*/
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}while (h);
	return (i);
}

/**
 * node_starts_with - ahju
 * @node: ahju
 * @prefix: ahju
 * @c: ahju
 * Return: ahju
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *p = NULL;
	
	/*do while loop*/
	{
		p = starts_with(node->str, prefix);
		/*if statement*/
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	} while (node);
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
	size_t i = 0;

	/*do while loop*/
	do{
		/*if statements*/
		if (head == node)
			return (i);
		/*points to the next null*/
		head = head->next;
		i++;
	} while (head);
	return (-1);
}
