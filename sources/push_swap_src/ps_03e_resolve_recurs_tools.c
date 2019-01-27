/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_03e_resolve_recurs_tools.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdouniol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 17:43:20 by jdouniol          #+#    #+#             */
/*   Updated: 2019/01/10 17:43:20 by jdouniol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ps_03e_resolve_recurs_tools.c                            |
**   |     ft_pile_b_is_sort2(21 lines)                         |
**   |     ft_pile_a_is_sort2(21 lines)                         |
**   |     ft_mg_pb_i_pos(24 lines)                             |
**   |     ft_mg_pb_i_nul_j_pos(10 lines)                       |
**   |     ft_manage_pb2(19 lines)                              |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include "../../includes/push_swap.h"

int		ft_pile_b_is_sort2(t_mega *elem)
{
	int max;
	int i;

	i = 1;
	max = elem->pile_b[0];
	while (i < elem->size_b)
	{
		if (elem->pile_b[i] < max)
		{
			max = elem->pile_b[i];
			i++;
		}
		else
			return (0);
	}
	if (i == elem->size_b)
	{
		return (1);
	}
	else
		return (0);
}

int		ft_pile_a_is_sort2(t_mega *elem)
{
	int min;
	int i;

	i = 1;
	min = elem->pile_a[0];
	while (i < elem->size_a)
	{
		if (elem->pile_a[i] > min)
		{
			min = elem->pile_a[i];
			i++;
		}
		else
			return (0);
	}
	if (i == elem->size_a)
	{
		return (1);
	}
	else
		return (0);
}

void	ft_mg_pb_i_pos(t_mega *elem, int i, int j)
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
		if (elem->size_b - j < 21 && elem->size_b - j >= 0 && elem->size_b > 30)
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

void	ft_mg_pb_i_nul_j_pos(t_mega *elem, int j)
{
	if (elem->size_b - j < 21 && elem->size_b - j >= 0 && elem->size_b > 30)
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

void	ft_manage_pb2(t_mega *elem)
{
	int i;
	int j;

	i = elem->index_next_twentieme;
	j = elem->index_approx_min;
	if (i > 0)
		ft_mg_pb_i_pos(elem, i, j);
	if (i == 0 && j != 0 && j != -1)
		ft_mg_pb_i_nul_j_pos(elem, j);
	if (j == -1 && i == 0)
	{
		ft_sort_pile_b_decreas(elem);
		ft_pb(elem);
		ft_rb(elem);
	}
	if (j == 0 && i == 0)
	{
		ft_pb(elem);
	}
}
