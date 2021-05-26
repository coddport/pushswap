/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cport <cport@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 22:18:06 by cport             #+#    #+#             */
/*   Updated: 2020/11/18 22:19:14 by cport            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *st)
{
	t_elem	*tmp1;
	t_elem	*tmp2;

	if (st->len == 2)
	{
		st->top = st->top->next;
		return ;
	}
	tmp1 = st->top->prev;
	tmp2 = st->top->next->next;
	tmp1->next = st->top->next;
	st->top->next->prev = tmp1;
	st->top->next->next = st->top;
	st->top->prev = st->top->next;
	st->top->next = tmp2;
	tmp2->prev = st->top;
	st->top = tmp1->next;
}

void	push(t_elem *element, t_stack *stack)
{
	t_elem	*tmp1;

	if (!stack->len)
	{
		stack->top = element;
		element->prev = stack->top;
		element->next = stack->top;
	}
	else
	{
		tmp1 = stack->top->prev;
		element->prev = tmp1;
		tmp1->next = element;
		element->next = stack->top;
		stack->top->prev = element;
		stack->top = element;
	}
	stack->len++;
}

void	ps_swap(t_stack *a, t_stack *b, char c)
{
	if (c != 'a' && c != 'b' && c != 's')
		error("swap: bad argument", 0);
	if (c == 'a' || c == 's')
		(a && a->len > 1) ? swap(a) : 0;
	if (c == 'b' || c == 's')
		(b && b->len > 1) ? swap(b) : 0;
}

void	ps_rotate(t_stack *a, t_stack *b, char c, char d)
{
	if (c != 'a' && c != 'b' && c != 'r')
		error("rotate: bad argument", 0);
	if (c == 'a' || c == 'r')
		if (a->len > 1)
			a->top = (d == 'r') ? a->top->next : a->top->prev;
	if (c == 'b' || c == 'r')
		if (b->len > 1)
			b->top = (d == 'r') ? b->top->next : b->top->prev;
}

void	ps_push(t_stack *a, t_stack *b, char c)
{
	if (c != 'a' && c != 'b')
		error("push: bad argument", 0);
	if ((c == 'a' && !b->len) || (c == 'b' && !a->len))
		return ;
	if (c == 'a' && b->len)
		push(cut_element(b->top, b), a);
	else if (c == 'b' && a->len)
		push(cut_element(a->top, a), b);
}
