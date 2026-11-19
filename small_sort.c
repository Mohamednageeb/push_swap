#include "push_swap.h"

static int	min_index(t_stack *a)
{
	int	i;
	int	pos;

	pos = 0;
	i = 1;
	while (i < a->size)
	{
		if (a->items[i].value < a->items[pos].value)
			pos = i;
		i++;
	}
	return (pos);
}

static void	push_smallest(t_stack *a, t_stack *b)
{
	int	pos;

	pos = min_index(a);
	if (pos <= a->size / 2)
	{
		while (pos-- > 0)
			ra(a);
	}
	else
	{
		pos = a->size - pos;
		while (pos-- > 0)
			rra(a);
	}
	pb(a, b);
}

static void	sort_three(t_stack *a)
{
	t_item	*v;

	v = a->items;
	if (v[0].value > v[1].value)
	{
		if (v[1].value > v[2].value)
		{
			sa(a);
			rra(a);
		}
		else if (v[0].value > v[2].value)
			ra(a);
		else
			sa(a);
	}
	else if (v[0].value > v[2].value)
		rra(a);
	else if (v[1].value > v[2].value)
	{
		sa(a);
		ra(a);
	}
}

void	sort_small(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		if (a->items[0].value > a->items[1].value)
			sa(a);
		return ;
	}
	while (a->size > 3)
		push_smallest(a, b);
	if (a->size == 3)
		sort_three(a);
	while (b->size > 0)
		pa(a, b);
}
