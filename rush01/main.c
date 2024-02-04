#include <unistd.h>

void	compute(int inputs[4][4]);
void	print_board(int inputs[4][4]);

void	convert(char *str, int inputs[4][4], int *buffer)
{
	if(buffer[1] == 4)
	{
		buffer[1] = 0;
		buffer[2] += 1;
	}
	inputs[buffer[2]][buffer[1]] = str[buffer[0]] - 48;
	buffer[1]++;
	buffer[0]++;
}

int	convert_inputs(char *str, int inputs[4][4], int *buffer)
{
	while (str[buffer[0]] != '\0')
	{
		if (str[buffer[0]] >= '1' && str[buffer[0]] <= '4')
		{
			convert(str, inputs, buffer);
		}
		else if (str[buffer[0]] == ' ')
			buffer[0]++;
		else
		{
			write(1, "Wrong input!", 13);
			return (1);
		}
	}

	if (buffer[0] >= 32)
	{
		write(1, "Total number of inputs exceeded.", 33);
		return (1);
	}
	return (0);
}

int main(int arc, char **arv)
{
	int index;
	int inputs[4][4];
	int buffer[3];

	if (arc == 2)
	{
		index = 0;

		while (index < 3)
		{
			buffer[index] = 0;
			index++;
		}

		inputs[3][3] = 0;

		if(convert_inputs(arv[1],inputs, buffer) != 0)
			return (0);

		if (inputs[3][3] == 0)
		{
			write(1, "Could not get the inputs correctly", 35);
			return (0);
		}
		
		compute(inputs);
	}
	else
		write(1, "Wrong number of command line arguments", 39);

	return (0);
}
