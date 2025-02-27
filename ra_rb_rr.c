/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalabro <ccalabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:34:10 by ccalabro          #+#    #+#             */
/*   Updated: 2025/01/11 19:49:22 by ccalabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **head)
{
	t_stack	*last;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return ;
	last = ft_last_node(*head);
	last->next = *head;
	*head = (*head)->next;
	last->next->prev = last;
	last->next->next = NULL;
	(*head)->prev = NULL;
}

void	ra(t_stack **a)
{
	ft_rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	ft_rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	ft_rotate(a);
	ft_rotate(b);
	write(1, "rr\n", 3);
}
