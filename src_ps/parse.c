/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cport <cport@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 22:18:12 by cport             #+#    #+#             */
/*   Updated: 2020/11/19 04:34:26 by cport            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_int(char *str, int sign, int i)
{
	char	*minmax;
	int		len;

	minmax = "2147483647";
	if (*str == '+' || *str == '-')
	{
		sign = (str[0] == '-') ? 1 : 0;
		str++;
	}
	if ((len = ft_strlen(str)) > 10)
		return (0);
	else if (len == 10)
		while (++i < len)
		{
			if ((i == 9) && (str[i] - '0') > (minmax[i] - '0' + sign))
				return (0);
			else if ((i < 9) && (str[i] - '0') > (minmax[i] - '0'))
				return (0);
		}
	return (1);
}

int		is_doubled(t_stack *stack)
{
	t_elem	*tmp;
	t_elem	*tval;
	int		i;

	i = -1;
	tval = stack->top;
	while (++i < stack->len)
	{
		tmp = tval->next;
		while (tmp != tval)
		{
			(tmp->val == tval->val) ? error("parsing: input duplicate", 0) : 0;
			tmp = tmp->next;
		}
		tval = tval->next;
	}
	return (0);
}

t_stack	*build_stack(int ac, char **av, ssize_t i)
{
	t_stack	*stack;

	stack = init_stack();
	while (++i < ac)
		if (ft_isnum(av[i]) && is_int(av[i], 0, -1))
			add_element(init_element(ft_atoi(av[i])), stack);
		else
			error("parsing: input not numeral", 0);
	is_doubled(stack);
	return (stack);
}

t_stack	*parse_values(int ac, char **av)
{
	t_stack	*a;

	if (ac == 2 && !ft_isnum(av[1]))
	{
		if (!(av = ft_strsplit(av[1], ' ')))
			error("parsing: strsplit failed", 0);
		ac = 0;
		while (av[ac])
			ac++;
		a = build_stack(ac, av, -1);
		ft_strsplitdel(&av);
	}
	else
		a = build_stack(ac, av, 0);
	return (a);
}

t_plan	*parse_directives(void)
{
	char	*line;
	int		ret;
	t_plan	*plan;

	plan = init_plan();
	while ((ret = get_next_line(0, &line)) > 0)
	{
		add_step(init_step(line), plan);
		free(line);
	}
	(ret < 0) ? error("parsing: command read failed", 0) : 0;
	return (plan);
}
