#include "shell.h"

/**
 * input_buf - A function buffers chained commands
 * @info: A parameter struct
 * @buf: A address of buffer
 * @len: An address of len var
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
		if (u > 0)
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
	return (u);
}

/**
 * get_input - the function gets a line minus the newline
 * @info: A parameter struct
 *
 * Return: bytes read
 */
ssize_t get_input(info_t *info)
{
	static char *buf;
	static size_t x, l, len;
	ssize_t t = 0;
	char **buf_p = &(info->arg), *p;

	_putchar(BUF_FLUSH);
	t = input_buf(info, &buf, &len);
	if (t == -1)
		return (-1);
	if (len)
	{
		l = x;
		p = buf + x;

		check_chain(info, buf, &l, x, len);
		while (l < len)
		{
			if (is_chain(info, buf, &l))
				break;
			l++;
		}

		x = l + 1;
		if (x >= len)
		{
			x = len = 0;
			info->cmd_buf_type = CMD_NORM;
		}

		*buf_p = p;
		return (_strlen(p));
	}

	*buf_p = buf;
	return (t);
}

/**
 * read_buf - A function that reads a buffer
 * @info: parameter struct
 * @buf: buffer
 * @j: size
 *
 * Return: r
 */
ssize_t read_buf(info_t *info, char *buf, size_t *j)
{
	ssize_t u = 0;

	if (*j)
		return (0);
	u = read(info->readfd, buf, READ_BUF_SIZE);
	if (u >= 0)
		*j = u;
	return (u);
}

/**
 * _getline - the function gets the next line of input from STDIN
 * @info: A parameter structure
 * @pointer: An address of pointer to buffer, preallocated or NULL
 * @length: A size of preallocated pointer buffer if not NULL
 *
 * Return: s
 */
int _getline(info_t *info, char **pointer, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t x, len;
	size_t m;
	ssize_t r = 0, s = 0;
	char *q = NULL, *new_p = NULL, *c;

	q = *pointer;
	if (q && length)
		s = *length;
	if (x == len)
		x = len = 0;

	r = read_buf(info, buf, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);

	c = _strchr(buf + x, '\n');
	m = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = _realloc(q, s, s ? s + m : m + 1);
	if (!new_p)
		return (q ? free(q), -1 : -1);

	if (s)
		_strncat(new_p, buf + x, m - x);
	else
		_strncpy(new_p, buf + x, m - x + 1);

	s += m - x;
	x = m;
	q = new_p;

	if (length)
		*length = s;
	*pointer = q;
	return (s);
}

/**
 * sigintHandler - blocks ctrl-C
 * @sig_num: the signal number
 *
 * Return: void
 */
void sigintHandler(__attribute__((unused)) int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
