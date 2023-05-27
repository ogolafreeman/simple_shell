#include "shell.h"

/**
 * is_chain - ahju
 * @info: ahju
 * @buf: ahju
 * @p: ahju
 * Return: ahju
 */
int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t j = *p;

	/*if statement*/
	if (buf[j] == '|' && buf[j + 1] == '|')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_OR;
	}
	/*else if statement*/
	else if (buf[j] == '&' && buf[j + 1] == '&')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_AND;
	}
	/*else if statement*/
	else if (buf[j] == ';')
	{
		buf[j] = 0;
		info->cmd_buf_type = CMD_CHAIN;
	}
	/*els statement*/
	else
		return (0);
	*p = j;
	return (1);
}

/**
 * check_chain - ahju
 * @info: ahju
 * @buf: ahju
 * @p: ahju
 * @i: ahju
 * @len: ahju
 * Return: ahju
 */
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	/*if statements*/
	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}

	/*if syatement*/
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}

	*p = j;
}

/**
 * replace_alias - ahju
 * @info: ahju
 * Return: ahju
 */
int replace_alias(info_t *info)
{
	int i;
	list_t *node;
	char *p;

	/*for loop*/
	for (i = 0; i < 10; i++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = _strchr(node->str, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}

/**
 * replace_vars - ahju
 * @info: ahju
 * Return: ahju
 */
int replace_vars(info_t *info)
{
	int i = 0;
	list_t *node;

	/*for loop*/
	for (i = 0; info->argv[i]; i++)
	{
		/*if statement*/
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;

		/*if statement*/
		if (!_strcmp(info->argv[i], "$?"))
		{
			replace_string(&(info->argv[i]),
				_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		/*if statement*/
		if (!_strcmp(info->argv[i], "$$"))
		{
			replace_string(&(info->argv[i]),
				_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[i][1], '=');
		/*if statement*/
		if (node)
		{
			replace_string(&(info->argv[i]),
				_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[i], _strdup(""));

	}
	return (0);
}

/**
 * replace_string - ahju
 * @old: ahju
 * @new: ahju
 * Return: ahju
 */
int replace_string(char **old, char *new)
{
	/*frees old memory*/
	free(*old);
	/*if statement*/
	*old = new;
	return (1);
}
