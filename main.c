#include "push_swap.h"


t_stack *create_list(int x, int s, int t, int z)
{
    t_stack *a = (t_stack *)malloc(sizeof(t_stack));
    t_stack *b = (t_stack *)malloc(sizeof(t_stack));
    t_stack *c = (t_stack *)malloc(sizeof(t_stack));
    t_stack *d = (t_stack *)malloc(sizeof(t_stack));

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = NULL;

    a->prev = NULL;
    b->prev = a;
    c->prev = b;
    d->prev = c;

    a->value = x;
    b->value = s;
    c->value = t;
    d->value = z;

    return a;
}

void printlist(t_stack *a)
{
    t_stack *tmp;

    if (!a)
        printf("AAA: lo stack non esiste\n");
    tmp = a;
    while(tmp)
    {
        printf("a: %d\n", tmp->value);
        tmp = tmp->next;
    }
   // printf("\n");
}


int main(int argc, char **argv)
{
    (void)argc;
    t_stack *a;
    t_stack *b;

    a = NULL;
    b = NULL;

    /*
    //a = create_list(3, 5, 8, 11);
    //printlist(a);
    b = create_list(7, 9 , 14 , 2);
    printlist(b);

    
    pb(&b, &a);

    printlist(a);
    */
    put_argv_into_stack(&a, argv, argc);
    //AAA metteremo sempre piu di tre nodi i nodi non saranno mai ordinati
    ft_push_swap(&a, &b);

    printlist(a);




}