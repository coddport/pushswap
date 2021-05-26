/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cport <cport@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 22:18:38 by cport             #+#    #+#             */
/*   Updated: 2020/11/18 22:18:43 by cport            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem	*next_value(t_stack *stack, int i, int flag)
{
	t_elem	*tmp1;
	t_elem	*tmp2;

	if (!stack)
		return (NULL);
	tmp1 = NULL;
	tmp2 = stack->top;
	while (i < stack->len)
	{
		if (tmp2->i == -1)
			if (!flag || tmp2->val < tmp1->val)
			{
				flag = 1;
				tmp1 = tmp2;
			}
		i++;
		tmp2 = tmp2->next;
	}
	return (tmp1);
}

t_stack	*index_stack(t_stack *stack)
{
	int		index;
	t_elem	*tmp;

	index = 0;
	while ((tmp = next_value(stack, 0, 0)))
	{
		tmp->i = index;
		index++;
	}
	return (stack);
}

int		is_sorted(t_stack *stack)
{
	t_elem	*tmp;
	int		min;
	int		i;

	i = 0;
	min = stack->top->val;
	tmp = stack->top->next;
	while (++i < stack->len)
	{
		if (tmp->val < min)
			return (0);
		min = tmp->val;
		tmp = tmp->next;
	}
	return (1);
}
