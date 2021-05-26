/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cport <cport@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 22:18:23 by cport             #+#    #+#             */
/*   Updated: 2020/11/19 02:58:02 by cport            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem	*init_element(int value)
{
	t_elem	*element;

	if (!(element = (t_elem *)ft_memalloc(sizeof(t_elem))))
		error("init_element allocation failed", 0);
	element->val = value;
	element->i = -1;
	element->prev = NULL;
	element->next = NULL;
	element->sorted = 0;
	return (element);
}

t_stack	*init_stack(void)
{
	t_stack	*stack;

	if (!(stack = (t_stack *)ft_memalloc(sizeof(t_stack))))
		error("init_stack allocation failed", 0);
	stack->top = NULL;
	stack->len = 0;
	stack->seq = 0;
	stack->medi = NULL;
	return (stack);
}

t_step	*init_step(char *s)
{
	t_step	*step;

	if (!(step = (t_step *)malloc(sizeof(t_step))))
		error("init_step allocation failed", 0);
	if ((ft_strlen(s) == 2) && (s[0] == 's' || s[0] == 'p' || s[0] == 'r'))
	{
		step->dir = s[0];
		step->arg = s[1];
	}
	else if (ft_strlen(s) == 3 && s[0] == 'r' && s[1] == 'r')
	{
		step->dir = 'l';
		step->arg = s[2];
	}
	else
		error("unknown command", 0);
	step->next = NULL;
	return (step);
}

t_plan	*init_plan(void)
{
	t_plan	*plan;

	if (!(plan = (t_plan *)malloc(sizeof(t_plan))))
		error("init_commands allocation failed", 0);
	plan->start = NULL;
	plan->len = 0;
	plan->v = 0;
	return (plan);
}

t_trace	*init_trace(void)
{
	t_trace	*trace;

	if (!(trace = (t_trace *)malloc(sizeof(t_trace))))
		error("solving: init_trace allocation failed", 0);
	trace->done = 0;
	trace->len = 0;
	trace->x = NULL;
	trace->y = NULL;
	trace->to_x = 0;
	trace->to_y = 0;
	trace->i = 0;
	trace->tmp = NULL;
	trace->right_a = 0;
	trace->left_a = 0;
	trace->right_b = 0;
	trace->left_b = 0;
	return (trace);
}
