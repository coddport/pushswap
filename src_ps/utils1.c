/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cport <cport@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 22:18:34 by cport             #+#    #+#             */
/*   Updated: 2020/11/19 02:55:58 by cport            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_state(t_stack *a, t_stack *b, int i)
{
	t_elem	*temp_a;
	t_elem	*temp_b;

	a ? temp_a = a->top : error("no stack a", 0);
	b ? temp_b = b->top : error("no stack b", 0);
	ft_printf(" >>>\n");
	while (++i < a->len || i < b->len)
	{
		if (i < a->len)
		{
			ft_printf("%d>\t%d\t", i, temp_a->val);
			temp_a = temp_a->next;
		}
		else
			ft_printf("%d>\t.\t", i);
		if (i < b->len)
		{
			ft_printf("%d\n", temp_b->val);
			temp_b = temp_b->next;
		}
		else
			ft_printf(".\n");
	}
	ft_printf("\n");
}

void	print_plan(t_plan *exe, int checker)
{
	t_step	*temp;
	int		i;

	i = -1;
	temp = exe->start;
	checker ? ft_printf("Exec") : 0;
	while (++i < exe->len)
	{
		checker ? ft_printf(" ") : 0;
		(temp->dir == 'l') ? ft_printf("rr") : ft_printf("%c", temp->dir);
		ft_printf("%c", temp->arg);
		checker ? 0 : ft_printf("\n");
		temp = temp->next;
	}
	checker ? ft_printf(":\n") : 0;
}

void	execute_plan(t_stack *a, t_stack *b, t_plan *plan, int i)
{
	t_step	*t;

	t = plan->start;
	(plan->v) ? print_plan(plan, 1) : 0;
	while (++i < plan->len)
	{
		if (t->dir == 's')
			ps_swap(a, b, t->arg);
		else if (t->dir == 'p')
			ps_push(a, b, t->arg);
		else if (t->dir == 'r')
			ps_rotate(a, b, t->arg, t->dir);
		else if (t->dir == 'l')
			ps_rotate(a, b, t->arg, t->dir);
		if (plan->v == 1)
		{
			ft_printf(">>> ");
			(t->dir == 'l') ? ft_printf(" rr") : ft_printf(" %c", t->dir);
			ft_printf("%c ", t->arg);
			print_state(a, b, -1);
		}
		t = t->next;
	}
	free_plan(plan);
}

int		to_swap(t_stack *stack, char c, int alg)
{
	int		tseq;

	if (c == 'a')
	{
		ps_swap(stack, NULL, 'a');
		tseq = put_label(stack, stack->medi, alg, 0);
		ps_swap(stack, NULL, 'a');
		put_label(stack, stack->medi, alg, 0);
		if (stack->len > 1 && tseq > stack->seq)
			return (1);
	}
	else if (stack->len > 1 && stack->top->i < stack->top->next->i)
		return (1);
	return (0);
}
