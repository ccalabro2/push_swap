/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalabro <ccalabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:34:21 by ccalabro          #+#    #+#             */
/*   Updated: 2025/01/11 19:49:22 by ccalabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_stack **head)
{
	t_stack	*last;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return ;
	last = ft_last_node(*head);
	last -> next = (*head);
	*head = last;
	(*head)->prev->next = NULL;
	(*head)->prev = NULL;
	(*head)->next->prev = *head;
}

void	rra(t_stack **a)
{
	ft_reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	ft_reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	write(1, "rrr\n", 4);
}
