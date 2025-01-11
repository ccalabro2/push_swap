/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_target.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalabro <ccalabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:04:45 by ccalabro          #+#    #+#             */
/*   Updated: 2025/01/11 20:05:46 by ccalabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_find_goal(t_stack *a, t_stack *b)
{
	int		value;
	t_stack	*goal;
	t_stack	*temp;

	temp = a;
	while (b)
	{
		value = 2147483647;
		a = temp;
		while (a)
		{
			if (b->value < a->value && a->value < value)
			{
				value = a->value;
				goal = a;
			}
			a = a->next;
		}
		if (value == 2147483647)
			b->goal = ft_smallest(temp);
		else
			b->goal = goal;
		b = b->next;
	}
}

void	ft_cost(t_stack *a, t_stack *b)
{
	int	price;
	int	len_a;
	int	len_b;

	len_a = ft_stacklen(a);
	len_b = ft_stacklen(b);
	while (b)
	{
		price = b->position;
		if (b->median == 1)
			price = b->position;
		else
			price = len_b - b->position;
		if (b->goal->median == 1)
			price = price + b->goal->position;
		else
			price = price + len_a - b->goal->position;
		b->cost = price;
		b = b->next;
	}
}

void	ft_cheapest(t_stack *head)
{
	int		value;
	t_stack	*cheapest_node;

	if (!head)
		return ;
	value = head->cost;
	cheapest_node = head;
	head = head->next;
	while (head)
	{
		if (head->cost < value)
		{
			value = head->cost;
			cheapest_node = head;
		}
		head = head->next;
	}
	cheapest_node->cheapest = 1;
}

t_stack	*ft_return_cheapest(t_stack *head)
{
	if (!head)
		return (NULL);
	while (head)
	{
		if (head->cheapest == 1)
			return (head);
		head = head->next;
	}
	return (NULL);
}

t_stack	*ft_last_node(t_stack *head)
{
	if (head == NULL)
		return (NULL);
	while ((head)->next != NULL)
		head = head->next;
	return (head);
}
