//
// Created by quark on 30/03/22.
//

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include "./libft/libft.h"

// Custom Types
typedef enum e_type
{
    A,
    B
} t_type;

typedef struct s_stack
{
    int             content;
    struct s_stack  *next;
} t_stack;

// main.c
t_stack **get_stack(t_type stack);

// utils.c
void exec_command(int cmd);
void exec_multiple(int cmd, int rep);
int is_sorted(t_stack *head);
int get_min(t_stack *head);
int get_max(t_stack *head);
void reorder_a(void);
int count_occurrences(int nbr, t_stack *head);
int has_repeated_numbers(t_stack *head);
void print_list(t_stack *head);
int has_negative(t_stack *head);
void print_stack(t_type stack);

// commands.c
void	pa(void);
void	pb(void);
void	ra(int print);
void	rb(int print);
void	rr(void);
void	rra(int print);
void	rrb(int print);
void	rrr(void);
void	sa(int print);
void	sb(int print);
void	ss(void);

// stacks.c
t_stack	*lst_new(int nbr);
void lst_add_back(t_stack *head, int nbr);
void lst_initialize_add_back(t_stack **list, int nbr);
void lst_add_front(t_stack **list, int nbr);
int lst_length(t_stack *head);
int lst_value_by_index(t_stack *head, int  index);
int lst_index_by_value(t_stack *head, int value);
void lst_delete_back(t_stack *head);
void lst_delete_front(t_stack **list);

// sort_small.c
void sort_small(void);

// sort_large.c
void sort_large(int negative);
int flip_number(int nbr);
void flip_numbers();

// long_atoi.c
long long_atoi(const char *str);

#endif
