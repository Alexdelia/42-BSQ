#include <unistd.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	char	buffer[500];
	int		r;

	(void)av;
	while ((r = read(0, buffer, 500)) > 0)
	{
		printf("%d\t|%s|\n", r, buffer);
	}
	printf("%d\t|%s|\n", r, buffer);
	return (0);
}
