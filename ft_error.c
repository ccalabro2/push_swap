/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalabro <ccalabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:33:08 by ccalabro          #+#    #+#             */
/*   Updated: 2025/01/11 20:15:19 by ccalabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_argv(char **argv)
{
	int	i;

	i = 1;
	if (argv == NULL || argv[i] == NULL)
		return ;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	ft_free_every_nodes(t_stack **head)
{
	t_stack	*tmp;

	if (head == NULL || *head == NULL)
		return ;
	while (*head)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
}

void	ft_free_argv_nd_list(t_stack**a, char **argv, int argc)
{
	ft_free_every_nodes(a);
	if (argc == 2)
		ft_free_argv(argv);
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_error_repetition(t_stack *a, int n)
{
	int	is_doubled;
	int	is_unique;

	is_doubled = 1;
	is_unique = 0;
	if (a == NULL)
		return (is_unique);
	while (a != NULL)
	{
		if (a->value == n)
			return (is_doubled);
		a = a->next;
	}
	return (is_unique);
}
