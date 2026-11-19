#include "push_swap.h"

static int	chunk_width(int n)
{
	int	width;

	width = 1;
	while ((long long)width * width < n)
		width++;
	return (width);
}

static void	collect_chunk(t_stack *a, t_stack *b, int low, int high)
{
	int	count;

	count = 0;
	while (count < high - low)
	{
		if (a->items[0].rank >= low && a->items[0].rank < high)
		{
			pb(a, b);
			count++;
		}
		else
			ra(a);
	}
}

static void	align_stack(t_stack *a, int low)
{
	int	i;
	int	moves;

	if (low == 0 || a->size < 2)
		return ;
	i = 0;
	while (a->items[i].rank != low - 1)
		i++;
	moves = (i + 1) % a->size;
	if (moves <= a->size / 2)
	{
		while (moves-- > 0)
			ra(a);
	}
	else
	{
		moves = a->size - moves;
		while (moves-- > 0)
			rra(a);
	}
}

void	sort_medium(t_stack *a, t_stack *b)
{
	int	low;
	int	high;
	int	width;
	int	total;

	total = a->size;
	width = chunk_width(total);
	low = 0;
	while (low < total)
	{
		high = low + width;
		if (high > total)
			high = total;
		collect_chunk(a, b, low, high);
		align_stack(a, low);
		move_chunk_to_a(a, b);
		low = high;
	}
}
