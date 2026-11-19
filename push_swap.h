#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_item
{
	int	value;
	int	rank;
}	t_item;

typedef struct s_stack
{
	t_item	*items;
	int		size;
}	t_stack;

int		parse_value(const char *s, int *value);
int		parse_numbers(t_stack *a, t_stack *b, int argc, char **argv);
void	assign_ranks(t_stack *a);
int		is_sorted(t_stack *a);
void	sa(t_stack *a);
void	sort_small(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rra(t_stack *a);
void	rb(t_stack *b);
void	rrb(t_stack *b);
void	sort_medium(t_stack *a, t_stack *b);
void	move_chunk_to_a(t_stack *a, t_stack *b);

#endif
