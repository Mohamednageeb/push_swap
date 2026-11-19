#include "push_swap.h"

void	pb(t_stack *a, t_stack *b)
{
	t_item	item;
	int		i;

	if (a->size == 0)
		return ;
	item = a->items[0];
	i = b->size;
	while (i > 0)
	{
		b->items[i] = b->items[i - 1];
		i--;
	}
	b->items[0] = item;
	b->size++;
	i = 0;
	while (i < a->size - 1)
	{
		a->items[i] = a->items[i + 1];
		i++;
	}
	a->size--;
	write(1, "pb\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
	t_item	item;
	int		i;

	if (b->size == 0)
		return ;
	item = b->items[0];
	i = a->size;
	while (i > 0)
	{
		a->items[i] = a->items[i - 1];
		i--;
	}
	a->items[0] = item;
	a->size++;
	i = 0;
	while (i < b->size - 1)
	{
		b->items[i] = b->items[i + 1];
		i++;
	}
	b->size--;
	write(1, "pa\n", 3);
}
