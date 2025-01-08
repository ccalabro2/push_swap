#include "push_swap.h"

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

int ft_stacklen(t_stack *head)
{
    int i;
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

void	ft_median(t_stack *head)
{
	int	len;

	if (head == NULL)
		return ;
	len = ft_stacklen(head);
	while (head != NULL)
	{
		if (head->position <= len / 2) // AAA ho ritolto + 
			head->median = 1;
		else
			head->median = -1;
		head = head->next;
	}
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

t_stack	*ft_smallest(t_stack *head)
{
	long    smallest;
	t_stack *smallest_node;

	if (!head)
		return (NULL);
	smallest = LONG_MAX; //vuoi inserire il vlore ?
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
	t_stack *cheapest_node;

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