typedef struct s_stack 
{
    int value;
    struct s_stack *prev;
    struct s_stack *next;
} t_stack;