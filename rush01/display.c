#include <unistd.h>

void	display(int inputs[4][4])
{
	int		i;
	int		j;
	char	ans;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 3)
		{
			ans = inputs[i][j] + 48;
			write(1, &ans, 1);
			write(1, " ", 1);
            j++;
		}
		ans = inputs[i][j] + 48;
		write(1, &ans, 1);
		write(1, "\n", 1);
        i++;
	}
}
