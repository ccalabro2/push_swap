/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_general_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalabro <ccalabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:07:49 by ccalabro          #+#    #+#             */
/*   Updated: 2025/01/11 20:17:06 by ccalabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_node_to_list(t_stack **head, int num)
{
	t_stack	*node;
	t_stack	*last_node;

	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return ;
	node->next = NULL;
	node->value = num;
	if (*head == NULL)
	{
		*head = node;
		node->prev = NULL;
	}
	else
	{
		last_node = ft_last_node(*head);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	ft_argv_in_stack(t_stack **a, char **argv, int argc)
{
	long	n;
	int		i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (ft_is_number(argv[i]))
			ft_free_argv_nd_list(a, argv, argc);
		n = ft_atoi(argv[i]);
		if (n > 2147483647 || n < -2147483648)
			ft_free_argv_nd_list(a, argv, argc);
		if (ft_number_repetition(*a, (int)n))
			ft_free_argv_nd_list(a, argv, argc);
		ft_add_node_to_list(a, (int)n);
		i++;
	}
	if (argc == 2)
		ft_free_argv(argv);
}

int	ft_number_repetition(t_stack *head, int n)
{
	int	is_repeated;
	int	is_not_repeated;

	is_repeated = 1;
	is_not_repeated = 0;
	if (head == NULL)
		return (is_not_repeated);
	while (head)
	{
		if (head->value == n)
			return (is_repeated);
		head = head->next;
	}
	return (is_not_repeated);
}

int	ft_is_number(char *num)
{
	int	no;
	int	yes;
	int	i;

	no = 1;
	yes = 0;
	if (num == NULL || num[0] == '\0')
		return (no);
	i = 0;
	if (num[i] == '+' || num[i] == '-')
		i++;
	if (num[i] == '\0')
		return (no);
	while (num[i] >= '0' && num[i] <= '9')
		i++;
	if (num[i] == '\0')
		return (yes);
	else
		return (no);
}
