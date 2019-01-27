/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_03b_resolve_medium.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdouniol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 17:42:22 by jdouniol          #+#    #+#             */
/*   Updated: 2019/01/10 17:42:22 by jdouniol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ps_03b_resolve_medium.c                                  |
**   |     ft_mg_pb_i_pos_medium(24 lines)                      |
**   |     ft_mg_pb_i_nul_j_pos_medium(10 lines)                |
**   |     ft_manage_pb2_medium(19 lines)                       |
**   |     ft_get_the_rest_medium(13 lines)                     |
**   |     ft_do_it_twice_medium(16 lines)                      |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include "../../includes/push_swap.h"

void	ft_mg_pb_i_pos_medium(t_mega *elem, int i, int j)
{
	if (i > j)
	{
		while (i >= j && j != 0 && j != -1)
			ft_rr(elem) && i-- && j--;
		while (i > 0)
			ft_ra(elem) && i--;
	}
	else
	{
		if (elem->size_b - j < 9 && elem->size_b - j >= 0 && elem->size_b > 15)
		{
			while (j != elem->size_b)
				ft_rrb(elem) && j++;
			while (i != 0)
				ft_ra(elem) && i--;
		}
		else
		{
			while (i != 0)
				ft_rr(elem) && i-- && j--;
			while (j != 0)
				ft_rb(elem) && j--;
		}
	}
}

void	ft_mg_pb_i_nul_j_pos_medium(t_mega *elem, int j)
{
	if (elem->size_b - j < 9 && elem->size_b - j >= 0 && elem->size_b > 15)
	{
		while (j != elem->size_b)
			ft_rrb(elem) && j++;
	}
	else
	{
		while (j != 0)
			ft_rb(elem) && j--;
	}
}

void	ft_manage_pb2_medium(t_mega *elem)
{
	int i;
	int j;

	i = elem->index_next_twentieme;
	j = elem->index_approx_min;
	if (i > 0)
		ft_mg_pb_i_pos_medium(elem, i, j);
	if (i == 0 && j != 0 && j != -1)
		ft_mg_pb_i_nul_j_pos_medium(elem, j);
	if (j == -1 && i == 0)
	{
		ft_sort_pile_b_decreas_small(elem);
		ft_pb(elem);
		ft_rb(elem);
	}
	if (j == 0 && i == 0)
	{
		ft_pb(elem);
	}
}

void	ft_get_the_rest_medium(t_mega *elem, int minus_three)
{
	ft_actualize_infos3(elem, minus_three);
	while (elem->min_a <= minus_three)
	{
		ft_manage_pb2_medium(elem);
		ft_actualize_infos3(elem, minus_three);
	}
	if (elem->min_a > minus_three)
	{
		ft_sort_pile_b_decreas(elem);
		ft_do_it_last(elem);
	}
	return ;
}

void	ft_do_it_twice_medium(t_mega *elem)
{
	int minus_three;

	minus_three = ft_get_minus_three(elem);
	while (elem->pile_a[0] > minus_three)
		ft_ra(elem);
	if (elem->pile_a[0] <= minus_three)
		ft_pb(elem);
	while (elem->pile_a[0] > minus_three)
		ft_ra(elem);
	if (elem->pile_a[0] <= minus_three)
		ft_pb(elem);
	if (elem->pile_b[0] < elem->pile_b[1])
		ft_sb(elem);
	ft_actualize_infos3(elem, minus_three);
	ft_get_the_rest_medium(elem, minus_three);
	return ;
}
