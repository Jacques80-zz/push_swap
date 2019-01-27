/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_03a_resolve_small.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdouniol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 17:42:11 by jdouniol          #+#    #+#             */
/*   Updated: 2019/01/10 17:42:11 by jdouniol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ps_03a_resolve_small.c                                   |
**   |     ft_get_minus_three_small(24 lines)                   |
**   |     ft_sort_pile_b_decreas_very_small(17 lines)          |
**   |     ft_sort_very_small(16 lines)                         |
**   |     ft_sort_small(20 lines)                              |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include "../../includes/push_swap.h"

int		ft_get_minus_three_small(t_mega *elem)
{
	int minus_three;
	int i;
	int j;
	int count_min;
	int count_plus;

	i = -1;
	while (++i < elem->size_a)
	{
		count_min = 0;
		count_plus = 0;
		j = -1;
		while (++j < elem->size_a)
			(elem->pile_a[j] <= elem->pile_a[i]) ? count_min++ : count_plus++;
		if (count_min == 3 && count_plus == 3 && elem->size_a == 6)
			minus_three = elem->pile_a[i];
		else if (count_min == 2 && count_plus == 3 && elem->size_a == 5)
			minus_three = elem->pile_a[i];
		else if (count_min == 1 && count_plus == 3 && elem->size_a == 4)
			minus_three = elem->pile_a[i];
		else
			continue;
	}
	return (minus_three);
}

void	ft_sort_pile_b_decreas_very_small(t_mega *elem)
{
	if (elem->size_b == 2)
		ft_sb(elem);
	else if (elem->pile_b[0] > elem->pile_b[1] && elem->pile_b[1]
		< elem->pile_b[2] && elem->pile_b[0] > elem->pile_b[2])
		ft_rb(elem) && ft_sb(elem) && ft_rrb(elem);
	else if (elem->pile_b[0] < elem->pile_b[1]
		&& elem->pile_b[0] > elem->pile_b[2])
		ft_sb(elem);
	else if (elem->pile_b[0] > elem->pile_b[1]
		&& elem->pile_b[0] < elem->pile_b[2])
		ft_rrb(elem);
	else if (elem->pile_b[0] < elem->pile_b[1]
		&& elem->pile_b[1] > elem->pile_b[2] && elem->pile_b[0]
			< elem->pile_b[2])
		ft_rb(elem);
	else
		ft_sb(elem) && ft_rrb(elem);
}

void	ft_sort_very_small(t_mega *elem)
{
	if (elem->size_max == 2)
		ft_sa(elem);
	else if (elem->pile_a[0] < elem->pile_a[1] && elem->pile_a[1]
		> elem->pile_a[2] && elem->pile_a[0] < elem->pile_a[2])
		ft_ra(elem) && ft_sa(elem) && ft_rra(elem);
	else if (elem->pile_a[0] > elem->pile_a[1]
		&& elem->pile_a[0] < elem->pile_a[2])
		ft_sa(elem);
	else if (elem->pile_a[0] < elem->pile_a[1]
		&& elem->pile_a[0] > elem->pile_a[2])
		ft_rra(elem);
	else if (elem->pile_a[0] > elem->pile_a[1]
		&& elem->pile_a[1] < elem->pile_a[2])
		ft_ra(elem);
	else
		ft_sa(elem) && ft_rra(elem);
}

void	ft_sort_small(t_mega *elem)
{
	int minus_three;

	minus_three = ft_get_minus_three_small(elem);
	ft_actualize_infos3(elem, minus_three);
	while (((elem->size_b != 2 && elem->size_max <= 5)
		|| elem->size_b != 3) && elem->min_a <= minus_three)
	{
		if (elem->pile_a[0] <= minus_three)
			ft_pb(elem);
		else
			ft_ra(elem);
		ft_actualize_infos3(elem, minus_three);
	}
	ft_actualize_infos3(elem, minus_three);
	if (!(ft_pile_b_is_sort2(elem)))
		ft_sort_pile_b_decreas_very_small(elem);
	if (!(ft_pile_a_is_sort2(elem)))
		ft_sort_very_small(elem);
	while (elem->size_b != 0)
		ft_pa(elem);
}
