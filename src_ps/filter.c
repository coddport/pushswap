/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cport <cport@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 22:18:02 by cport             #+#    #+#             */
/*   Updated: 2020/11/24 17:35:30 by cport            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		put_label(t_stack *st, t_elem *optimum, int alg, int tseq)
{
	t_elem	*tmp;
	int		ind;

	if (!st || !optimum)
		return (tseq);
	ind = optimum->i;
	optimum->sorted = 1;
	tmp = optimum;
	while ((tmp = tmp->next) && tmp != optimum)
		if (alg == 1 && (tmp->i == ind + 1))
		{
			tseq++;
			ind++;
			tmp->sorted = 1;
		}
		else if (alg == 0 && tmp->i > ind)
		{
			tseq++;
			ind = tmp->i;
			tmp->sorted = 1;
		}
		else
			tmp->sorted = 0;
	return (tseq);
}

int		update_sorted(t_stack *st, int alg)
{
	t_elem	*tmp;
	int		tseq;
	int		i;

	if (st)
	{
		tmp = st->top->prev;
		i = -1;
		while ((tmp = tmp->next) && ++i < st->len)
		{
			tseq = put_label(st, tmp, alg, 0);
			if (tseq > st->seq)
			{
				st->medi = tmp;
				st->seq = tseq;
			}
			else if (tseq == st->seq && (!st->medi || tmp->val < st->medi->val))
				st->medi = tmp;
		}
	}
	return (put_label(st, st->medi, alg, 0));
}
