#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack 
{
    int value;
    struct s_stack  *prev;
    struct s_stack  *next;
    struct s_stack  *goal;
    int             position;
    int             median;
    int             cost;
    int             cheapest;
} t_stack;

void	ft_if_dest_null(t_stack **dest, t_stack **src);
void	ft_else_dest_null(t_stack **dest, t_stack **src);
void    ft_push(t_stack **dest, t_stack **src);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);
void	ft_rotate(t_stack **head);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	ft_reverse_rotate(t_stack **head);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	ft_swap(t_stack **head);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	ft_cpy(char *dst, char *src, int start, int len);
int     count_words(char *s);
char    **matrix_argv(int n);
void    fill_matrix(char *src, char **matrix, int n_words);
void    ft_push_swap(t_stack **a, t_stack **b);
int     ft_stacklen(t_stack *head);
void	ft_mechanicalturk(t_stack *a, t_stack *b);
void	ft_heart(t_stack **a, t_stack **b);
void    ft_median(t_stack *head);
void	ft_node_position(t_stack *head);
t_stack	*ft_smallest(t_stack *head);
void	ft_find_goal(t_stack *a, t_stack *b);
void	ft_cost(t_stack *a, t_stack *b);
void	ft_cheapest(t_stack *head);
t_stack	*ft_return_cheapest(t_stack *head);
void	ft_rotate_a_and_b(t_stack **a,
						t_stack **b,
						t_stack *cheapest_node);
void	ft_reverse_rotate_a_and_b(t_stack **a,
								t_stack **b,
								t_stack *cheapest_node);
void	ft_till_end_rotation(t_stack **head,
							t_stack *x_node,
							char name_stack);
t_stack	*ft_highest(t_stack *head);


//da modificare
void	put_argv_into_stack(t_stack **a, char **argv, int argc);
void	append_node(t_stack **stack, int nbr);
long	ft_atoi(const char *str);
t_stack	*find_last_node(t_stack *head);
void	sort_three_nodes(t_stack **a);


#endif