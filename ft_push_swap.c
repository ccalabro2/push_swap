/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalabro <ccalabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:33:29 by ccalabro          #+#    #+#             */
/*   Updated: 2025/01/11 20:07:19 by ccalabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap(t_stack **a, t_stack **b)
{
	t_stack	*smallest;
	int		len_a;

	len_a = ft_stacklen(*a);
	while (len_a > 3)
	{
		pb(a, b);
		len_a--;
	}
	ft_order_three_nodes(a);
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

void	ft_mechanicalturk(t_stack *a, t_stack *b)
{
	ft_find_goal(a, b);
	ft_node_position(a);
	ft_median(a);
	ft_node_position(b);
	ft_median(b);
	ft_cost(a, b);
	ft_cheapest(b);
}

void	ft_heart(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = ft_return_cheapest(*b);
	if (cheapest_node->median == 1
		&& cheapest_node->goal->median == 1)
		ft_rotate_a_and_b(a, b, cheapest_node);
	else if ((cheapest_node->median == -1)
		&& (cheapest_node->goal->median == -1))
		ft_reverse_rotate_a_and_b(a, b, cheapest_node);
	ft_till_end_rotation(b, cheapest_node, 'b');
	ft_till_end_rotation(a, cheapest_node->goal, 'a');
	pa(a, b);
}

void	ft_order_three_nodes(t_stack **head)
{
	if (*head == ft_smallest(*head))
	{
		ra(head);
		if ((*head)->value > (*head)->next->value)
			sa(head);
		rra(head);
		return ;
	}
	else if ((*head)->next == ft_smallest(*head))
	{
		if (*head == ft_highest(*head))
			ra(head);
		else
			sa(head);
	}
	else
	{
		if ((*head)->value > (*head)->next->value)
			sa(head);
		rra(head);
	}
}

int	ft_stacklen(t_stack *head)
{
	int	i;

	if (!head)
		return (0);
	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}
