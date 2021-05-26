/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cport <cport@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 22:17:51 by cport             #+#    #+#             */
/*   Updated: 2020/11/18 23:10:51 by cport            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_stack	*stack;
	t_plan	*plan_a;
	t_plan	*plan_b;

	if (ac < 2)
		return (0);
	if (!ft_strcmp(av[1], "-v"))
	{
		av++;
		ac--;
	}
	stack = index_stack(parse_values(ac, av));
	if (stack->len < 2 || is_sorted(stack))
		return (free_stack(stack));
	update_sorted(stack, 0);
	plan_a = calculate_plan(stack, 0);
	stack = index_stack(parse_values(ac, av));
	update_sorted(stack, 1);
	plan_b = calculate_plan(stack, 1);
	(plan_a->len < plan_b->len) ? print_plan(plan_a, 0) : print_plan(plan_b, 0);
	free_plan(plan_a);
	free_plan(plan_b);
	return (0);
}
