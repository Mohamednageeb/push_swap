#include "push_swap.h"

void	assign_ranks(t_stack *a)
{
	int	i;
	int	j;
	int	rank;

	i = 0;
	while (i < a->size)
	{
		rank = 0;
		j = 0;
		while (j < a->size)
		{
			if (a->items[j].value < a->items[i].value)
				rank++;
			j++;
		}
		a->items[i].rank = rank;
		i++;
	}
}

int	is_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->size - 1)
	{
		if (a->items[i].value > a->items[i + 1].value)
			return (0);
		i++;
	}
	return (1);
}
