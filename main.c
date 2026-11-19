#include "push_swap.h"

static int	is_medium(const char *s)
{
	const char	*flag;

	flag = "--medium";
	while (*s && *flag && *s == *flag)
	{
		s++;
		flag++;
	}
	return (*s == '\0' && *flag == '\0');
}

static int	end_with_error(t_stack *a, t_stack *b)
{
	free(a->items);
	free(b->items);
	write(2, "Error\n", 6);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		start;

	if (argc == 1)
		return (0);
	a.items = NULL;
	b.items = NULL;
	start = 1;
	if (is_medium(argv[1]))
		start = 2;
	if (start == argc || !parse_numbers(&a, &b, argc - start, argv + start))
		return (end_with_error(&a, &b));
	if (!is_sorted(&a))
	{
		assign_ranks(&a);
		if (a.size <= 12)
			sort_small(&a, &b);
		else
			sort_medium(&a, &b);
	}
	free(a.items);
	free(b.items);
	return (0);
}
