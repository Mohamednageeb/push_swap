#include "push_swap.h"

void	rra(t_stack *a)
{
	t_item	last;
	int		i;

	if (a->size < 2)
		return ;
	last = a->items[a->size - 1];
	i = a->size - 1;
	while (i > 0)
	{
		a->items[i] = a->items[i - 1];
		i--;
	}
	a->items[0] = last;
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	t_item	last;
	int		i;

	if (b->size < 2)
		return ;
	last = b->items[b->size - 1];
	i = b->size - 1;
	while (i > 0)
	{
		b->items[i] = b->items[i - 1];
		i--;
	}
	b->items[0] = last;
	write(1, "rrb\n", 4);
}
