/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_03h_resolve_big.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdouniol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 19:26:49 by jdouniol          #+#    #+#             */
/*   Updated: 2019/01/23 19:27:08 by jdouniol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ps_03h_resolve_big.c                                     |
**   |     ft_get_fiftieme(25 lines)                            |
**   |     ft_get_the_rest2(17 lines)                           |
**   |     ft_do_it_twice2(16 lines)                            |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include "../../includes/push_swap.h"

int		ft_get_fiftieme(t_mega *elem)
{
	int i;
	int j;
	int pivot;
	int count_min;
	int count_plus;

	i = -1;
	while (++i < elem->size_a)
	{
		count_min = 0;
		count_plus = 0;
		j = -1;
		while (++j < elem->size_a)
			(elem->pile_a[j] < elem->pile_a[i]) ? count_min++ : count_plus++;
		if (count_min == 60 && elem->size_a > 65)
		{
			pivot = elem->pile_a[i];
			return (pivot);
		}
		else if (elem->size_a > 60)
			pivot = ft_get_minus_three(elem);
		else
			continue;
	}
	return (0);
}

void	ft_get_the_rest2(t_mega *elem, int fiftieme)
{
	ft_actualize_infos3(elem, fiftieme);
	while (elem->min_a <= fiftieme)
	{
		ft_manage_pb2(elem);
		ft_actualize_infos3(elem, fiftieme);
	}
	if (elem->min_a > fiftieme && elem->size_a > 55)
	{
		ft_sort_pile_b_decreas(elem);
		ft_do_it_twice(elem);
	}
	else if (elem->min_a > fiftieme && elem->size_a > 3)
	{
		ft_sort_pile_b_decreas(elem);
		ft_do_it_last(elem);
	}
	return ;
}

void	ft_do_it_twice2(t_mega *elem)
{
	int fiftieme;

	fiftieme = ft_get_fiftieme(elem);
	while (elem->pile_a[0] > fiftieme)
		ft_ra(elem);
	if (elem->pile_a[0] <= fiftieme)
		ft_pb(elem);
	while (elem->pile_a[0] > fiftieme)
		ft_ra(elem);
	if (elem->pile_a[0] <= fiftieme)
		ft_pb(elem);
	if (elem->pile_b[0] < elem->pile_b[1])
		ft_sb(elem);
	ft_actualize_infos3(elem, fiftieme);
	ft_get_the_rest2(elem, fiftieme);
	return ;
}
