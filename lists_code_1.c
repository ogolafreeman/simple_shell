#include "shell.h"

/**
 * add_node - ahju
 * @head: ahju
 * @str: ahju
 * @num: ahju
 * Return: ahju
 */
list_t *add_node(list_t **head, const char *str, int num)
{
	list_t *new_head;

	/*if statement*/
	if (!head)
		return (NULL);
	new_head = malloc(sizeof(list_t));
	/*if statement*/
	if (!new_head)
		return (NULL);
	_memset((void *)new_head, 0, sizeof(list_t));
	new_head->num = num;
	/*if statement*/
	if (str)
	{
		new_head->str = _strdup(str);
		/*if statement*/
		if (!new_head->str)
		{
			free(new_head);
			return (NULL);
		}
	}
	/*points to the next null*/
	new_head->next = *head;
	*head = new_head;
	return (new_head);
}

/**
 * add_node_end - ahju
 * @head: ahju
 * @str: ahju
 * @num: ahju
 * Return: ahju
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
	list_t *new_node, *node;

	/*if statement*/
	if (!head)
		return (NULL);

	node = *head;
	/*allocates memory*/
	new_node = malloc(sizeof(list_t));
	/*if statement*/
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->num = num;
	/*if statement*/
	if (str)
	{
		new_node->str = _strdup(str);
		/*if statement*/
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	/*if statement*/
	if (node)
	{
		/*while loop*/
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*head = new_node;
	return (new_node);
}

/**
 * print_list_str - ahju
 * @h: ahju
 * Return: ahju
 */
size_t print_list_str(const list_t *h)
{
	size_t i = 0;

	/*if statement*/
	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	/*returns i*/
	return (i);
}

/**
 * delete_node_at_index - ahju
 * @head: ahju
 * @index: ahju
 * Return: ahju
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *node, *prev_node;
	unsigned int i = 0;

	/*if statement*/
	if (!head || !*head)
		return (0);

	/*if statement*/
	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	/*if statement*/
	while (node)
	{
		/*if statement*/
		if (i == index)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		i++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * free_list - ahju
 * @head_ptr: ahju
 * Return: ahju
 */
void free_list(list_t **head_ptr)
{
	list_t *node, *next_node, *head;

	/*if statement*/
	if (!head_ptr || !*head_ptr)
		return;
	head = *head_ptr;
	node = head;
	/*if statement*/
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*head_ptr = NULL;
}
