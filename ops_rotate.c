#include "push_swap.h"

void	ra(t_stack *a)
{
	t_item	first;
	int		i;

	if (a->size < 2)
		return ;
	first = a->items[0];
	i = 0;
	while (i < a->size - 1)
	{
		a->items[i] = a->items[i + 1];
		i++;
	}
	a->items[i] = first;
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	t_item	first;
	int		i;

	if (b->size < 2)
		return ;
	first = b->items[0];
	i = 0;
	while (i < b->size - 1)
	{
		b->items[i] = b->items[i + 1];
		i++;
	}
	b->items[i] = first;
	write(1, "rb\n", 3);
}
