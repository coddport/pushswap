/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cport <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 16:54:04 by cport             #+#    #+#             */
/*   Updated: 2020/11/24 17:37:00 by cport            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct		s_step
{
	struct s_step	*next;
	char			dir;
	char			arg;
}					t_step;

typedef struct		s_plan
{
	t_step			*start;
	int				len;
	int				v;
}					t_plan;

typedef struct		s_elem
{
	struct s_elem	*prev;
	struct s_elem	*next;
	int				i;
	int				val;
	int				sorted;
}					t_elem;

typedef struct		s_stack
{
	t_elem			*top;
	int				len;
	int				seq;
	t_elem			*medi;
}					t_stack;

typedef struct		s_state
{
	t_stack			*a;
	t_stack			*b;
	t_plan			*exe;
}					t_state;

typedef struct		s_trace
{
	t_elem			*x;
	t_elem			*y;
	t_elem			*tmp;
	int				i;
	int				len;
	int				done;
	int				to_x;
	int				to_y;
	int				right_a;
	int				left_a;
	int				right_b;
	int				left_b;
}					t_trace;

t_stack				*parse_values(int ac, char **av);
t_plan				*parse_directives(void);

void				print_state(t_stack *a, t_stack *b, int i);
void				print_plan(t_plan *plan, int checker);
void				execute_plan(t_stack *a, t_stack *b, t_plan *plan, int i);
void				execute_move(t_stack *a, t_stack *b, t_plan *plan,
		char *str);

int					update_sorted(t_stack *stack, int alg);
t_stack				*index_stack(t_stack *stack);
int					put_label(t_stack *stack, t_elem *optimum, int alg,\
		int tseq);
t_plan				*calculate_plan(t_stack *stack, int alg);
void				scout_road(t_stack *a, t_stack *b, t_elem *try,
		t_trace *road);
void				rotate_rl(t_stack *a, t_stack *b, t_trace *new,
		t_plan *plan);

void				ps_swap(t_stack *a, t_stack *b, char c);
void				ps_rotate(t_stack *a, t_stack *b, char c, char d);
void				ps_push(t_stack *a, t_stack *b, char c);

int					is_sorted(t_stack *stack);
int					is_doubled(t_stack *stack);
int					is_filtered(t_stack *stack);

int					to_swap(t_stack *stack, char c, int alg);

t_stack				*init_stack();
t_elem				*init_element(int value);
t_step				*init_step(char *s);
t_plan				*init_plan();
t_trace				*init_trace();

void				add_step(t_step *step, t_plan *plan);
void				add_element(t_elem *element, t_stack *stack);
t_elem				*cut_element(t_elem *element, t_stack *stack);

void				error(char *str, int debug);

int					free_stack(t_stack *stack);
int					free_plan(t_plan *plan);
int					free_state(t_state *state);

#endif
