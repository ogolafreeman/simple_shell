#include "shell.h"

/**
 * _myenv - the function prints the current environment
 * @info: Used to maintain constant function prototype.
 * Return: Always 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - gets the value of an environ variable
 * @info: Structure containing potential arguments. Used to maintain
 * @name: env var name
 *
 * Return: the value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *q;

	while (node)
	{
		q = starts_with(node->str, name);
		if (q && *q)
			return (q);
		node = node->next;
	}
	return (NULL);
}

/**
 * populate_env_list - the function populates env linked list
 * @info: its used to maintain constant function prototype.
 * Return: Always 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}

/**
 * _mysetenv - Initialize a new environment variable.
 * @info: its used to maintain constant function prototype.
 *  Return: Always 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect argument inputs\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Removes an environment variable
 * @info: its used to maintain constant function prototype.
 *  Return: Always 0
 */
int _myunsetenv(info_t *info)
{
	int k;

	if (info->argc == 1)
	{
		_eputs("Limited arguements entered.\n");
		return (1);
	}
	for (k = 1; k <= info->argc; k++)
		_unsetenv(info, info->argv[k]);

	return (0);
}
