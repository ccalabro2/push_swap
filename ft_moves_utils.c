/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalabro <ccalabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:54:38 by ccalabro          #+#    #+#             */
/*   Updated: 2025/01/11 20:27:14 by ccalabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a_and_b(t_stack **a,
						t_stack **b,
						t_stack *cheapest_node) {
	while (*a != cheapest_node->goal
		&& *b != cheapest_node)
		rr(a, b);
	ft_node_position(*a);
	ft_median(*a);
	ft_node_position(*b);
	ft_median(*b);
}

void	ft_reverse_rotate_a_and_b(t_stack **a,
								t_stack **b,
								t_stack *cheapest_node) {
	while (*a != cheapest_node->goal
		&& *b != cheapest_node)
		rrr(a, b);
	ft_node_position(*a);
	ft_median(*a);
	ft_node_position(*b);
	ft_median(*b);
}

void	ft_till_end_rotation(t_stack **head,
							t_stack *x_node,
							char name_stack) {
	while (*head != x_node)
	{
		if (name_stack == 'a')
		{
			if (x_node->median == 1)
				ra(head);
			else
				rra(head);
		}
		else if (name_stack == 'b')
		{
			if (x_node->median == 1)
				rb(head);
			else
				rrb(head);
		}
	}
}

void	ft_node_position(t_stack *head)
{
	int	i;

	if (!head)
		return ;
	i = 0;
	while (head)
	{
		head->position = i;
		i++;
		head = head->next;
	}
}

void	ft_median(t_stack *head)
{
	int	len;

	if (head == NULL)
		return ;
	len = ft_stacklen(head);
	while (head != NULL)
	{
		if (head->position <= len / 2 + 1)
			head->median = 1;
		else
			head->median = -1;
		head = head->next;
	}
}
