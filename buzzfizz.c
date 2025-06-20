#include <unistd.h>
#include <stdio.h>
#include <limits.h>	
#include <stdlib.h>				// len = 7
									//   0 1 2 3 4 5 6 7
void	print_reverse(char *str) // a = "a b c d e f g"<- a[len-1]
{
	int	i;
	i = 0;
	while(str[i])
		i++;
	
}

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
		output = i / 10 + '0'; // 72 => 70 + 2
		write(1, &output, 1);
		output = i % 10 + '0';
		write(1, &output, 1);
	}
	
}

void	putint(int nb) // -123
{
	char output;
	if (nb % 10 == nb) // 15 % 10 => 5 ; 9 % 10 => 9 
	{
		// here is a digit
		if (nb < 0)
			write(1, "-", 1);
		if (nb < 0)
			nb = -nb;
		output = nb + '0';
		write(1, &output, 1);
	}
	else
	{
		putint(nb / 10); //put(-214748364) -> put(-21474836) -> ... -> put(-2) 
		if (nb < 0)
			putint(-(nb % 10));
		else
			putint(nb % 10);   //INT_MIN     //put(-2147483648) -> put(-214748364); put(-2147483648 % 10) // -2147483648 % 10 => -8 -> 8
	}
}

void	append(char* str, char c)
{
	while(*str)
		str++;
	*str = c;
	*(str + 1) = '\0';
}

void	putint_str(int nb, char *str) // -123
{
	char output;
	if (nb % 10 == nb) // 15 % 10 => 5 ; 9 % 10 => 9 
	{
		// here is a digit
		if (nb < 0)
			append(str, '-');
		if (nb < 0)
			nb = -nb;
		output = nb + '0';
		append(str, output);
	}
	else
	{
		putint(nb / 10); //put(-214748364) -> put(-21474836) -> ... -> put(-2) 
		if (nb < 0)
			putint(-(nb % 10));
		else
			putint(nb % 10);   //INT_MIN     //put(-2147483648) -> put(-214748364); put(-2147483648 % 10) // -2147483648 % 10 => -8 -> 8
	}
}

char *ft_itoa(int nb)
{
	char	*result;
	int		i;

	result = malloc(sizeof(char) * 12); 
	i = 0;
	while(i < 12)
	{
		result[i] = '\0';
		i++;
	}
	
	putint_str(nb, result);
	return (result);
}

void	check_fizzbuzz(int i)
{
	if (i % 4 == 0)
		write(1, "buzz", 4);
	if (i % 7 == 0)
		write(1, "fizz", 4);
	if (i % 7 != 0 && i % 4 != 0)       // putint(123) -> putint(12); putint(3) -> putint(1); putint(2); putint(3)
		putint(i);						// 
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
	//putint(INT_MIN);
	printf("\n%s", ft_itoa(INT_MIN));
	// while (i <= 1000)
	// {
	// 	check_fizzbuzz(i);
	// 	write(1, "\n", 1);
	// 	i++;
	// }
}
