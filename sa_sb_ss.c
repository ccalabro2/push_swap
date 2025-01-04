#include "push_swap.h"

void	ft_swap(t_stack **src)
{
	int len;
    len = stack_len(*src);
    
    if (*src == NULL || src == NULL || len <= 1)
    	return ;
	*src = (*src)->next;
	(*src)->prev->prev = *src;
	(*src)->prev->next = (*src)->next;
	if ((*src)->next)
		(*src)->next->prev = (*src)->prev;
	(*src)->next = (*src)->prev;
	(*src)->prev = NULL;
}

void	sa(t_stack **a)
{
	ft_swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	ft_swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	ft_swap(a);
	ft_swap(b);
	write(1, "ss\n", 3);
}
