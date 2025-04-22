// Archivo: src/main.c
#include "push_swap.h"

int	move_count = 0;

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		i;

	a.size = 0;
	b.size = 0;
	if (argc < 2)
	{
        printf("Error: No arguments provided.\n");
		return (1);
	}
	i = 1;
	while (i < argc)
	{
		if (!add_number(&a, argv[i]))
		{
			write(2, "Error\n", 6);
			return (1);
		}
		i++;
	}
	assign_indices(&a);
	turco(&a, &b);
	print_stacks(&a, &b);
	printf("Total movimientos: %d\n", move_count);
	return (0);
}
