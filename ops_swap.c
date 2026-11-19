#include "push_swap.h"

void	sa(t_stack *a)
{
	t_item	temp;

	if (a->size < 2)
		return ;
	temp = a->items[0];
	a->items[0] = a->items[1];
	a->items[1] = temp;
	write(1, "sa\n", 3);
}
