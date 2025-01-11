/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalabro <ccalabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:33:47 by ccalabro          #+#    #+#             */
/*   Updated: 2025/01/11 19:40:47 by ccalabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		return (0);
	else if (argc == 2)
		argv = ft_split_argv(argv[1]);
	if (argv == NULL)
		return (0);
	a = NULL;
	b = NULL;
	ft_argv_in_stack(&a, argv, argc);
	if (ft_stack_ordered(a) == 0)
	{
		if (ft_stacklen(a) == 2)
			sa(&a);
		else if (ft_stacklen(a) == 3)
			ft_order_three_nodes(&a);
		else
			ft_push_swap(&a, &b);
	}
	ft_free_every_nodes(&a);
}
