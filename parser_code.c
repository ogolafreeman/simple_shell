#include "shell.h"

/**
 * is_cmd - ahju
 * @info: ahju
 * @path: ahju
 * Return: ahju
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	/*if statement*/
	if (!path || stat(path, &st))
		return (0);

	/*if statement*/
	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	/*returns 0*/
	return (0);
}

/**
 * dup_chars - ahju
 * @pathstr: ahju
 * @start: ahju
 * @stop: ahju
 * Return: ahju
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int i = 0, k = 0;

	/*for loop*/
	for (k = 0, i = start; i < stop; i++)
		/*if statement*/
		if (pathstr[i] != ':')
			buf[k++] = pathstr[i];
	buf[k] = 0;
	return (buf);
}

/**
 * find_path - ahju
 * @info: ahju
 * @pathstr: ahju
 * @cmd: ahju
 * Return: ahju
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int i = 0, curr_pos = 0;
	char *path;

	/*if statement*/
	if (!pathstr)
		return (NULL);
	/*if statement*/
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	/*do while loop*/
	do{
		if (!pathstr[i] || pathstr[i] == ':')
		{
			path = dup_chars(pathstr, curr_pos, i);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[i])
				break;
			curr_pos = i;
		}
		i++;
	}while (1);
	return (NULL);
}
