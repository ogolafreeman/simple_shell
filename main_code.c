#include "shell.h"

/**
 * main - An entry point
 * @ac: An arg count
 * @av: An arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av)
{
	info_t info[] = { INFO_INIT };
	int fld = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fld)
		: "r" (fld));

	if (ac == 2)
	{
		fld = open(av[1], O_RDONLY);
		if (fld == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(av[0]);
				_eputs(": 0: Can't open ");
				_eputs(av[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fld;
	}
	populate_env_list(info);
	read_history(info);
	hsh(info, av);
	return (EXIT_SUCCESS);
}

