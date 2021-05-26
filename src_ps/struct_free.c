/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cport <cport@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 22:18:19 by cport             #+#    #+#             */
/*   Updated: 2020/11/19 04:06:23 by cport            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(char *str, int debug)
{
	if (debug)
	{
		ft_putstr_fd(str, 2);
		ft_putchar_fd('\n', 2);
	}
	else
		ft_putstr_fd("Error\n", 2);
	exit(1);
}

int		free_stack(t_stack *stack)
{
	t_elem	*tmp;
	t_elem	*to_del;
	int		i;

	i = -1;
	tmp = stack->top;
	while (++i < stack->len)
	{
		to_del = tmp;
		tmp = tmp->next;
		free(to_del);
	}
	free(stack);
	return (0);
}

int		free_plan(t_plan *plan)
{
	t_step	*tmp;
	t_step	*to_del;

	tmp = plan->start;
	while (tmp)
	{
		to_del = tmp;
		tmp = tmp->next;
		free(to_del);
	}
	free(plan);
	return (0);
}

int		free_state(t_state *state)
{
	free(state->a);
	free(state->b);
	free(state->exe);
	return (0);
}
