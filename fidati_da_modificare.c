#include "push_swap.h"

long	ft_atoi(const char *str)
{
	long	num;
	int		multiply_for_negative;
	int		i;

	num = 0;
	multiply_for_negative = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		multiply_for_negative *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * multiply_for_negative);
}

t_stack	*find_last_node(t_stack *head)
{
	if (head == NULL)
		return (NULL);
	while ((head)->next != NULL)
		head = head->next;
	return (head);
}

void	append_node(t_stack **stack, int nbr)
{
	t_stack	*node;
	t_stack *last_node;

	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return ;
	node->next = NULL;
	node->value = nbr;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

int	is_it_number(char *input_num)
{
	int	wrong;
	int	correct;
	int	i;

	wrong = 1;
	correct = 0;
	if (input_num == NULL || input_num[0] == '\0')
		return (wrong);
	i = 0;
	if (input_num[i] == '+' || input_num[i] == '-')
		i++;
	if (input_num[i] == '\0')
		return (wrong);
	while (input_num[i] >= '0' && input_num[i] <= '9')
		i++;
	if (input_num[i] == '\0')
		return (correct);
	else
		return (wrong);
}

int	error_repetition(t_stack *a, int n)
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

void	put_argv_into_stack(t_stack **a, char **argv, int argc)
{
	long	n;
	int		i;
    (void)argc;
	i = 1;
	while (argv[i] != NULL)
	{
		is_it_number(argv[i]);
		n = ft_atoi(argv[i]);
        append_node(a, (int)n);
		i++;
	}
}

void	sort_three_nodes(t_stack **a)
{
	if (*a == ft_smallest(*a))
	{
		ra(a);
		if ((*a)->value > (*a)->next->value)
			sa(a);
		rra(a);
		return ;
	}
	else if ((*a)->next == ft_smallest(*a))
	{
		if (*a == ft_highest(*a))
			ra(a);
		else
			sa(a);
	}
	else
	{
		if ((*a)->value > (*a)->next->value)
			sa(a);
		rra(a);
	}
}