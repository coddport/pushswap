/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cport <cport@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 22:14:37 by cport             #+#    #+#             */
/*   Updated: 2020/11/19 04:45:50 by cport            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_state	state;
	int		debug;

	if (ac < 2)
		return (0);
	debug = (ft_strcmp(av[1], "-v")) ? 0 : 1;
	(debug && --ac) ? av++ : 0;
	if (ac < 2)
		return (0);
	state.a = parse_values(ac, av);
	if (state.a->len < 2)
		return (free_stack(state.a));
	state.b = init_stack();
	(debug) ? print_state(state.a, state.b, -1) : 0;
	state.exe = parse_directives();
	state.exe->v = debug;
	execute_plan(state.a, state.b, state.exe, -1);
	ft_printf((is_sorted(state.a) && !state.b->len) ? "OK\n" : "KO\n");
	free_stack(state.b);
	return (free_stack(state.a));
}
