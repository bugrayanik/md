#include <unistd.h>

void	compute(int inputs[4][4]);
void	display(int inputs[4][4]);
void	init_board(int inputs[4][4], int board[4][4]);
int		backtrack(int board[4][4], int inputs[4][4], int r, int c);
int		checkRowLeftRight(int check, int *buffer, int board[4][4], int inputs[4][4]);
int		checkColUpDown(int check, int *buffer, int board[4][4], int inputs[4][4]);
int		checkRightLeft(int check, int *buffer, int board[4][4], int inputs[4][4]);
int		checkDownUp(int check, int *buffer, int board[4][4], int inputs[4][4]);


int	is_valid(int board[4][4], int inputs[4][4], int *buffer)
{
	board[buffer[0]][buffer[1]] = buffer[2];
	if (checkRowLeftRight(0, buffer, board, inputs) == 1)
		return (1);
	if (checkColUpDown(0, buffer, board, inputs) == 1)
		return (1);
	if (checkRightLeft(0, buffer, board, inputs) == 1)
		return (1);
	if (checkDownUp(0, buffer, board, inputs) == 1)
		return (1);
	return (0);
}

int	verifyCondition(int inputs[4][4], int r, int c)
{
	if ((r == 0) && (inputs[0][c] == 2 || inputs[0][c] == 3))
		return (1);
	if ((r == 3) && (inputs[1][c] == 2 || inputs[1][c] == 3))
		return (1);
	if ((c == 0) && (inputs[2][r] == 2 || inputs[2][r] == 3))
		return (1);
	if ((c == 3) && (inputs[3][r] == 2 || inputs[3][r] == 3))
		return (1);
	return (0);
}

int	verifyConditionLoop(int *i, int *buffer, int inputs[4][4], int board[4][4])
{
	int	r;
	int	c;

	r = buffer[0];
	c = buffer[1];
	while (++*i < 5)
	{
		if (*i == 4 && (buffer[0] == 0 || buffer[1] == 0 \
			|| buffer[0] == 3 || buffer[1] == 3))
		{
			if (verifyCondition(inputs, r, c) == 1)
				continue ;
		}
		buffer[2] = *i;
		if (is_valid(board, inputs, buffer) == 0)
		{
			if (backtrack(board, inputs, r, c + 1) == 0)
				return (0);
			board[r][c] = -1;
		}
		else
			board[r][c] = -1;
	}
	return (1);
}

int	backtrack(int board[4][4], int inputs[4][4], int r, int c)
{
	int	i;
	int	buffer[3];

	i = 0;
	buffer[0] = r;
	buffer[1] = c;
	if (r == 4)
		return (0);
	else if (c == 4)
		return (backtrack(board, inputs, r + 1, 0));
	else if (board[r][c] != -1)
		return (backtrack(board, inputs, r, c + 1));
	else
	{
		if (verifyConditionLoop(&i, buffer, inputs, board) == 0)
			return (0);
		else
			return (1);
	}
}

void	compute(int inputs[4][4])
{
	int	board[4][4]; //oyun tahtamiz, inside of the board is junk values, only declaration
	int	i;
	int	j;
	
	int	result;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
        {
            board[i][j] = -1;
            j++;
        }
        i++;
	}
	init_board(inputs, board);
	result = backtrack(board, inputs, 0, 0);
	if (result == 0)
		display(board);
	else
		write(1, "Board could not be generated.\n", 31);
}