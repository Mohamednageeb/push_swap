#include "push_swap.h"

static int	min_position(t_stack *b)
{
	int	i;
	int	pos;

	pos = 0;
	i = 1;
	while (i < b->size)
	{
		if (b->items[i].rank < b->items[pos].rank)
			pos = i;
		i++;
	}
	return (pos);
}

static void	bring_min_to_top(t_stack *b)
{
	int	pos;
	int	moves;

	pos = min_position(b);
	if (pos <= b->size / 2)
	{
		while (pos-- > 0)
			rb(b);
	}
	else
	{
		moves = b->size - pos;
		while (moves-- > 0)
			rrb(b);
	}
}

void	move_chunk_to_a(t_stack *a, t_stack *b)
{
	while (b->size > 0)
	{
		bring_min_to_top(b);
		pa(a, b);
		ra(a);
	}
}
