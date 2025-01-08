#include "push_swap.h"

//da modificare internamente...nome ok
void	ft_push_swap(t_stack **a, t_stack **b)
{
	t_stack	*smallest;
	int					len_a;

	len_a = ft_stacklen(*a);
	while (len_a > 3)
	{
		pb(b, a);
		len_a--;
	}
	sort_three_nodes(a);
	while (*b != NULL)
	{
		ft_mechanicalturk(*a, *b);
		ft_heart(a, b);
	}
	ft_node_position(*a);
	ft_median(*a);
	smallest = ft_smallest(*a);
	if (smallest->median == 1)
		while (*a != smallest)
			ra(a);
	else
		while (*a != smallest)
			rra(a);
}