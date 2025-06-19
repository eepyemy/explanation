#include <stdio.h>
#include <unistd.h>

void	print_character(char c, int index)
{
	if (index == 0)
	{
		write(1, &c, 1);
		return ;
	}
	if (index % 3 == 0)
		write(1, "5", 1);
	if (index % 5 == 0 && index % 3 != 0)
		write(1, "3", 1);
	if (index % 3 != 0 && index % 5 != 0)
		write(1, &c, 1);
}

// 20 -> c 15 -> 5, 45 -> 5, 75 -> 5
// 3 -> 5, 6 -> 5
// 5 -> 3
// 0 -> '0'5

void	work_with_str(char* str)
{
	// we work with str
	int i;
	i = 0;
	while (str[i] != '\0')
	{
		print_character(str[i], i);
		i++;
	}
}


int	main(int argc, char* argv[])
{
	//./a.out => argv => {"./a.out"} and argc => 1
	if (argc == 1)
		write(1, "\n", 1);
	if (argc == 2)
	{
		work_with_str(argv[1]);
		write(1, "\n", 1);
	}
	return (0);
}
// char* a; => {'a', 'b', ..., '\0'}
// char** b => { "./a.out", "argument 1" (a string), "argument 2" }


// ./a.out "argument 1" "argument 2" sdsad
// ./a.out