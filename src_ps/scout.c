/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cport <cport@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 22:18:30 by cport             #+#    #+#             */
/*   Updated: 2020/11/18 22:18:55 by cport            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem	*end_of_seq(t_stack *stack, int index)
{
	t_elem	*tmp;

	tmp = stack->medi;
	if (index > stack->medi->i)
	{
		while (index > tmp->i && tmp->i < tmp->next->i)
			tmp = tmp->next;
		if (index > tmp->i && tmp->i > tmp->next->i)
			tmp = tmp->next;
	}
	else
		while (index < tmp->prev->i && tmp->i > tmp->prev->i)
			tmp = tmp->prev;
	return (tmp);
}

void	get_distance(t_stack *a, t_stack *b, t_trace *ttmp)
{
	t_elem	*tmp;

	if (a && a->top)
	{
		tmp = a->top->prev;
		while ((tmp = tmp->next) && tmp->i != ttmp->x->i)
			ttmp->right_a++;
		tmp = a->top->next;
		while ((tmp = tmp->prev) && tmp->i != ttmp->x->i)
			ttmp->left_a++;
	}
	if (b && b->top)
	{
		tmp = b->top->prev;
		while ((tmp = tmp->next) && tmp->i != ttmp->y->i)
			ttmp->right_b++;
		tmp = b->top->next;
		while ((tmp = tmp->prev) && tmp->i != ttmp->y->i)
			ttmp->left_b++;
	}
}

void	compare_road(int length, t_trace *new, t_trace *road)
{
	if (road->done == 1 && length >= road->len)
		return ;
	road->x = new->x;
	road->y = new->y;
	road->to_x = new->to_x;
	road->to_y = new->to_y;
	road->len = length;
	road->done = 1;
}

void	scout_road(t_stack *a, t_stack *b, t_elem *try, t_trace *road)
{
	t_trace	*new;
	int		max;

	new = init_trace();
	new->y = try;
	new->x = end_of_seq(a, try->i);
	get_distance(a, b, new);
	new->to_x = 'r';
	new->to_y = 'r';
	max = (new->right_a > new->right_b) ? new->right_a : new->right_b;
	compare_road(max, new, road);
	new->to_x = 'l';
	compare_road(new->right_b + new->left_a, new, road);
	new->to_y = 'l';
	max = (new->left_a > new->left_b) ? new->left_a : new->left_b;
	compare_road(max, new, road);
	new->to_x = 'r';
	compare_road(new->left_b + new->right_a, new, road);
	free(new);
}

void	rotate_rl(t_stack *a, t_stack *b, t_trace *new, t_plan *plan)
{
	while (new->x != a->top || new->y != b->top)
		if (new->to_x == new->to_y && new->x != a->top && new->y != b->top)
		{
			if (new->to_x == 'r')
				execute_move(a, b, plan, "rr");
			else
				execute_move(a, b, plan, "rrr");
		}
		else if (new->x != a->top)
		{
			if (new->to_x == 'r')
				execute_move(a, b, plan, "ra");
			else
				execute_move(a, b, plan, "rra");
		}
		else if (new->y != b->top)
		{
			if (new->to_y == 'r')
				execute_move(a, b, plan, "rb");
			else
				execute_move(a, b, plan, "rrb");
		}
}
