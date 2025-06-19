#include <unistd.h>

void put_number(int i)
{
	char	output;

	if (i >= 1 && i <= 9)
	{
		output = i + '0';
		write(1, &output, 1);
	}
	else
	{
		output = i / 10 + '0';
		write(1, &output, 1);
		output = i % 10 + '0';
		write(1, &output, 1);
	}
	
}

void	check_fizzbuzz(int i)
{
	if (i % 4 == 0)
		write(1, "buzz", 4);
	if (i % 7 == 0)
		write(1, "fizz", 4);
	if (i % 7 != 0 && i % 4 != 0)
		put_number(i);
}

// i = 24
// 7 % 4 => 3
// 6 % 4 => 2
// 5 % 4 => 1
// 4 % 4 => 0
// 8 % 4 => 0
// 16 % 4 => 0
int	main(void)
{
	int	i;

	i = 1;
	while (i <= 100)
	{
		check_fizzbuzz(i);
		write(1, "\n", 1);
		i++;
	}
}
