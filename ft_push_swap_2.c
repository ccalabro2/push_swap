/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalabro <ccalabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:03:23 by ccalabro          #+#    #+#             */
/*   Updated: 2025/01/11 20:04:14 by ccalabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_smallest(t_stack *head)
{
	long	smallest;
	t_stack	*smallest_node;

	if (!head)
		return (NULL);
	smallest = LONG_MAX;
	while (head)
	{
		if (head->value < smallest)
		{
			smallest = head->value;
			smallest_node = head;
		}
		head = head->next;
	}
	return (smallest_node);
}

t_stack	*ft_highest(t_stack *head)
{
	t_stack	*highest;

	if (!head)
		return (NULL);
	highest = head;
	while (head->next)
	{
		if (highest->value < head->next->value)
			highest = head->next;
		head = head->next;
	}
	return (highest);
}

int	ft_stack_ordered(t_stack *head)
{
	int	ordered;

	ordered = 1;
	if (head == NULL)
		return (0);
	while (head->next != NULL)
	{
		if (head->value > head->next->value)
		{
			ordered = 0;
			return (ordered);
		}
		head = head->next;
	}
	return (ordered);
}
