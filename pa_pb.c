#include "push_swap.h"

void	ft_if_dest_null(t_stack **dest, t_stack **src)
{
	if ((*src)->next == NULL)
	{
		*dest = *src;
		*src = NULL;           
		(*dest)->next = NULL;
		(*dest)->prev = NULL;
	}
	else
	{
		*dest = *src;
		*src = (*src)->next;
		(*dest)->next = NULL;
		(*dest)->prev = NULL;
		(*src)->prev = NULL; 	
	}
}

void	ft_else_dest_null(t_stack **dest, t_stack **src)
{   
	if ((*src)->next == NULL)
	{
		(*src)->next = *dest;
		*dest = *src;
		(*dest)->next->prev = *dest;
		*src = NULL;
	}
	else
	{
		*src = (*src)->next;
		(*src)->prev->next = *dest;
		*dest = (*src)->prev;
		(*dest)->next->prev = *dest;
		(*src)->prev = NULL;
	}
}

void    ft_push(t_stack **dest, t_stack **src)
{
	if ((src == NULL) || (*src == NULL))
		return ;
	if (*dest == NULL)
		ft_if_dest_null(dest, src);
	else
		ft_else_dest_null(dest, src);
}

void	pa(t_stack **a, t_stack **b)
{
	ft_push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_stack **b, t_stack **a)
{
	ft_push(b, a);
	write(1, "pb\n", 3);
}