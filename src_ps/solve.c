/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cport <cport@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 22:18:16 by cport             #+#    #+#             */
/*   Updated: 2020/11/24 17:36:19 by cport            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_finish(t_stack *a, t_plan *plan)
{
	t_elem	*tmp;
	int		rot_r;
	int		rot_l;

	if (!a || !a->top)
		return ;
	rot_r = 0;
	rot_l = 0;
	tmp = a->top->prev;
	while ((tmp = tmp->next) && tmp->i != 0 && rot_r < a->len)
		rot_r++;
	tmp = a->top->next;
	while ((tmp = tmp->prev) && tmp->i != 0 && rot_l < a->len)
		rot_l++;
	while (a->top->i && rot_r < rot_l)
		execute_move(a, NULL, plan, "ra");
	while (a->top->i && !(rot_r < rot_l))
		execute_move(a, NULL, plan, "rra");
}

void	solve_continue(t_stack *a, t_stack *b, t_plan *plan)
{
	t_trace	*trace;

	trace = init_trace();
	while (b && b->len)
	{
		trace->done = 0;
		trace->i = 0;
		trace->tmp = b->top;
		while (trace->i < b->len)
		{
			scout_road(a, b, trace->tmp, trace);
			trace->tmp = trace->tmp->next;
			trace->i++;
		}
		rotate_rl(a, b, trace, plan);
		execute_move(a, b, plan, "pa");
	}
	free(trace);
	(b->len == 0) ? solve_finish(a, plan) : error("stack b not finished", 0);
}

void	solve_init(t_stack *a, t_stack *b, t_plan *plan, int alg)
{
	while (!is_filtered(a))
		if (to_swap(a, 'a', alg))
		{
			if (to_swap(b, 'b', alg))
				execute_move(a, b, plan, "ss");
			else
				execute_move(a, b, plan, "sa");
			a->seq = put_label(a, a->medi, alg, 0);
		}
		else if (a->top->sorted == 0)
			execute_move(a, b, plan, "pb");
		else
			execute_move(a, b, plan, "ra");
	solve_continue(a, b, plan);
}

t_plan	*calculate_plan(t_stack *a, int alg)
{
	t_plan	*plan;
	t_stack	*b;

	plan = init_plan();
	plan->v = 1;
	b = init_stack();
	solve_init(a, b, plan, alg);
	free_stack(b);
	free_stack(a);
	return (plan);
}
