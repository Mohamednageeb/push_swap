#include "push_swap.h"

static int	contains(t_stack *a, int value)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		if (a->items[i].value == value)
			return (1);
		i++;
	}
	return (0);
}

int	parse_numbers(t_stack *a, t_stack *b, int count, char **words)
{
	int	i;
	int	value;

	a->size = 0;
	b->size = 0;
	a->items = malloc(sizeof(t_item) * count);
	b->items = malloc(sizeof(t_item) * count);
	if (!a->items || !b->items)
		return (0);
	i = 0;
	while (i < count)
	{
		if (!parse_value(words[i], &value) || contains(a, value))
			return (0);
		a->items[a->size].value = value;
		a->size++;
		i++;
	}
	return (1);
}
