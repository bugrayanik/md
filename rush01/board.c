void	display(int inputs[4][4]);

void	fill_for_four(int board[4][4], int pos, int rowOrColumn, int incOrDec)
{
	int	i;

	if (incOrDec == 0)
	{
		i = 0;
		while (i < 4)
		{
			if (rowOrColumn == 0)
				board[pos][i] = i + 1;
			else
				board[i][pos] = i + 1;
			i++;
		}
	}
	else
	{
		i = 3;
		while (i > -1)
		{
			if (rowOrColumn == 0)
				board[pos][i] = 4 - i;
			else
				board[i][pos] = 4 - i;
			i--;
		}
	}
}

void	fill_for_one(int board[4][4], int i, int j)
{
	
	if (i == 0)
		board[0][j] = 4;
	else if (i == 1)
		board[3][j] = 4;
	else if (i == 2)
		board[j][0] = 4;
	else
		board[j][3] = 4;
	
}

void	fill(int board[4][4], int inputs[4][4], int *i, int *j)
{
	//int	i;

	//i = -1;
	if (inputs[*i][*j] == 1) // if i see only 1 skyscraper
		fill_for_one(board, *i, *j);
	else if (*i == 0)  //i see 4 
		fill_for_four(board, *j, 1, 0);
	else if (*i == 1) //i see 4 
		fill_for_four(board, *j, 1, 1);
	else if (*i == 2) //i see 4 
		fill_for_four(board, *j, 0, 0);
	else //i see 4 
		fill_for_four(board, *j, 0, 1);
}

void	init_board(int inputs[4][4], int board[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (inputs[i][j] == 4 || inputs[i][j] == 1)
			{
				fill(board, inputs, &i, &j);
			}
            j++;
		}
        i++;
	}
}