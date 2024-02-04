#include <unistd.h>

int	checkRowLeftRight(int check, int *buffer, int board[4][4], int inputs[4][4])
{
	int	i;
	int	highest;
	int	count;

	i = 0;
	highest = 0;
	count = 0;
	while (i < 4)
	{
		if (buffer[2] == board[buffer[0]][i] && i != buffer[1])
			return (1);
		if (board[buffer[0]][i] > highest)
		{
			highest = board[buffer[0]][i];
			count++;
		}
		if (board[buffer[0]][i] == -1)
			check = 1;
        i++;
	}
	if (count > inputs[2][buffer[0]] && check == 0)
		return (1);
	if (check == 0 && count != inputs[2][buffer[0]])
		return (1);
	return (0);
}

int	checkColUpDown(int check, int *buffer, int board[4][4], int inputs[4][4])
{
	int	i;
	int	highest;
	int	count;

	count = 0;
	i = 0;
	highest = 0;
	while (i < 4)
	{
		if (buffer[2] == board[i][buffer[1]] && i != buffer[0])
			return (1);
		if (board[i][buffer[1]] > highest)
		{
			highest = board[i][buffer[1]];
			count++;
		}
		if (board[i][buffer[1]] == -1)
			check = 1;
        i++;
	}
	if (count > inputs[0][buffer[1]] && check == 0)
		return (1);
	if (check == 0 && count != inputs[0][buffer[1]])
		return (1);
	return (0);
}

int	checkRightLeft(int check, int *buffer, int board[4][4], int inputs[4][4])
{
	int	count;
	int	highest;
	int	i;

	count = 0;
	highest = 0;
	i = 3;
	while (i > -1)
	{
		if (board[buffer[0]][i] > highest)
		{
			highest = board[buffer[0]][i];
			count++;
		}
		if (board[buffer[0]][i] == -1)
			check = 1;
        i--;
	}
	if (count > inputs[3][buffer[0]] && check == 0)
		return (1);
	if (check == 0 && count != inputs[3][buffer[0]])
		return (1);
	return (0);
}

int	checkDownUp(int check, int *buffer, int board[4][4], int inputs[4][4])
{
	int	count;
	int	highest;
	int	i;

	count = 0;
	highest = 0;
	i = 3;
	while (i > -1)
	{
		if (board[i][buffer[1]] > highest)
		{
			highest = board[i][buffer[1]];
			count++;
		}
		if (board[i][buffer[1]] == -1)
			check = 1;
        i--;
	}
	if (count > inputs[1][buffer[1]] && check == 0)
		return (1);
	if (check == 0 && count != inputs[1][buffer[1]])
		return (1);
	return (0);
}
