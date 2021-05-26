/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_modify.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cport <cport@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 22:18:26 by cport             #+#    #+#             */
/*   Updated: 2020/11/19 02:57:30 by cport            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_element(t_elem *element, t_stack *stack)
{
	t_elem	*tmp;

	if (!stack || !element)
		error("add: NULL stack or element", 0);
	if (!stack->top)
	{
		stack->top = element;
		stack->top->prev = stack->top;
		stack->top->next = stack->top;
	}
	else
	{
		tmp = stack->top->prev;
		element->prev = tmp;
		tmp->next = element;
		element->next = stack->top;
		stack->top->prev = element;
	}
	stack->len++;
}

t_elem	*cut_element(t_elem *element, t_stack *stack)
{
	t_elem	*tmp1;
	t_elem	*tmp2;

	if (stack->len == 0)
		return (NULL);
	if (element && stack->len == 1)
		stack->top = NULL;
	else if (element && stack->len > 1)
	{
		tmp1 = element->prev;
		tmp2 = element->next;
		tmp1->next = tmp2;
		tmp2->prev = tmp1;
		(element == stack->top) ? stack->top = tmp2 : 0;
	}
	element->prev = NULL;
	element->next = NULL;
	stack->len--;
	return (element);
}

void	add_step(t_step *step, t_plan *plan)
{
	t_step	*tmp;

	if (!plan || !step)
		error("add: NULL plan or step", 0);
	if (!plan->start)
		plan->start = step;
	else
	{
		tmp = plan->start;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = step;
	}
	plan->len++;
}

void	execute_move(t_stack *a, t_stack *b, t_plan *plan, char *str)
{
	t_step	*step;

	add_step((step = init_step(str)), plan);
	(step->dir == 's') ? ps_swap(a, b, step->arg) : 0;
	(step->dir == 'p') ? ps_push(a, b, step->arg) : 0;
	(step->dir == 'r') ? ps_rotate(a, b, step->arg, step->dir) : 0;
	(step->dir == 'l') ? ps_rotate(a, b, step->arg, step->dir) : 0;
}
