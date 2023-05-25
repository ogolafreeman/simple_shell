#include "shell.h"

/**
 * _unsetenv - The function remove an environment variable
 * @info: Used to maintain constant function prototype.
 *  Return: Always 1 on delete, 0 otherwise
 * @varb: the string env var property
 */
int _unsetenv(info_t *info, char *varb)
{
	list_t *node = info->env;
	size_t x = 0;
	char *q;

	if (!node || !varb)
		return (0);

	while (node)
	{
		q = starts_with(node->str, varb);
		if (p && *q == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), x);
			x = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		x++;
	}
	return (info->env_changed);
}

/**
 * get_environ - returns the string array copy of our environ
 * @info: its used to maintain constant function prototype.
 * Return: Always 0
 */
char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
 * _setenv - Initialize a new environment variable.
 * @info: Its used to maintain constant function prototype.
 * @varb: the string env var property
 * @values: the string env var value
 *  Return: Always 0
 */
int _setenv(info_t *info, char *varb, char *values)
{
	char *buf = NULL;
	list_t *node;
	char *q;

	if (!varb || !values)
		return (0);

	buf = malloc(_strlen(varb) + _strlen(values) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, values);
	node = info->env;
	while (node)
	{
		p = starts_with(node->str, varb);
		if (q && *q == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}
