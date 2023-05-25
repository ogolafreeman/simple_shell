#include "shell.h"

/**
 * _getline - function gets the next line of input from STDIN
 * @info: parameter struct
 * @pointer: address of pointer to buffer, preallocated or NULL
 * @length: size of preallocated ptr buffer if not NULL
 *
 * Return: s
 */
int _getline(info_t *info, char **pointer, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t x, len;
	size_t l;
	ssize_t u = 0, s = 0;
	char *q = NULL, *new_p = NULL, *c;

	q = *ptr;
	if (q && length)
		s = *length;
	if (x == len)
		x = len = 0;

	u = read_buf(info, buf, &len);
	if (u == -1 || (u == 0 && len == 0))
		return (-1);

	c = _strchr(buf + x, '\n');
	l = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = _realloc(q, s, s ? s + l : l + 1);
	if (!new_p)
		return (q ? free(q), -1 : -1);

	if (s)
		_strncat(new_p, buf + x, l - x);
	else
		_strncpy(new_p, buf + x, l - x + 1);

	s += l - x;
	x = l;
	p = new_p;

	if (length)
		*length = s;
	*pointer = q;
	return (s);
}


/**
 * input_buf - this buffers chained commands
 * @info: A parameter struct
 * @buf: A address of buffer
 * @len: A address of len var
 *
 * Return: bytes read
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t u = 0;
	size_t len_p = 0;

	if (!*len)
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		u = getline(buf, &len_p, stdin);
#else
		u = _getline(info, buf, &len_p);
#endif
		if (r > 0)
		{
			if ((*buf)[u - 1] == '\n')
			{
				(*buf)[u - 1] = '\0';
				u--;
			}
			info->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(info, *buf, info->histcount++);
			{
				*len = u;
				info->cmd_buf = buf;
			}
		}
	}
	return (r);
}

/**
 * get_input - the gets a line minus the newline
 * @info: parameter struct
 *
 * Return: bytes read
 */
ssize_t get_input(info_t *info)
{
	static char *buf;
	static size_t x, l, len;
	ssize_t u = 0;
	char **buf_p = &(info->arg), *q;

	_putchar(BUF_FLUSH);
	r = input_buf(info, &buf, &len);
	if (u == -1)
		return (-1);
	if (len)
	{
		j = i;
		p = buf + i;

		check_chain(info, buf, &l, x, len);
		while (l < len)
		{
			if (is_chain(info, buf, &j))
				break;
			l++;
		}

		x = l + 1;
		if (x >= len)
		{
			x = len = 0;
			info->cmd_buf_type = CMD_NORM;
		}

		*buf_p = q;
		return (_strlen(q));
	}

	*buf_p = buf;
	return (u);
}

/**
 * read_buf - the function reads a buffer
 * @info: parameter struct
 * @buf: buffer
 * @i: size
 *
 * Return: r
 */
ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
	ssize_t u = 0;

	if (*i)
		return (0);
	u = read(info->readfd, buf, READ_BUF_SIZE);
	if (r >= 0)
		*i = u;
	return (u);
}

/**
 * sigintHandler - blocks ctrl-C
 * @sig_num: the signal number
 *
 * Return: void
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
