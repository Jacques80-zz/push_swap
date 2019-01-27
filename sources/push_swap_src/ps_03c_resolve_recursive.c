/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_03c_resolve_recursive.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdouniol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 17:42:34 by jdouniol          #+#    #+#             */
/*   Updated: 2019/01/10 17:42:34 by jdouniol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ps_03c_resolve_recursive.c                               |
**   |     ft_sort_pile_b_decreas(18 lines)                     |
**   |     ft_do_it_last(20 lines)                              |
**   |     ft_get_the_rest(17 lines)                            |
**   |     ft_do_it_twice(16 lines)                             |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include "../../includes/push_swap.h"

void	ft_sort_pile_b_decreas(t_mega *elem)
{
	int i;

	i = 0;
	while ((i < elem->size_b - 1) && (elem->pile_b[i] > elem->pile_b[i + 1]))
		i++;
	if (i != elem->size_b)
	{
		if (elem->size_b - i < elem->size_b / 2)
		{
			while (i != elem->size_b - 1)
				ft_rrb(elem) && i++;
		}
		else
		{
			while (i != -1)
				ft_rb(elem) && i--;
		}
	}
}

void	ft_do_it_last(t_mega *elem)
{
	int minus_three;

	minus_three = ft_get_minus_three(elem);
	ft_actualize_infos3(elem, minus_three);
	while (elem->min_a <= minus_three)
	{
		ft_manage_pb2(elem);
		ft_actualize_infos3(elem, minus_three);
		if (PRINT_MODE)
			ft_print_array(elem);
	}
	ft_sort_pile_b_decreas(elem);
	if (PRINT_MODE)
		ft_print_array(elem);
	ft_sort_very_small2(elem);
	while (elem->size_b != 0)
		ft_pa(elem);
	while (!(ft_pile_a_is_sort2(elem)))
		ft_rra(elem);
	return ;
}

void	ft_get_the_rest(t_mega *elem, int twentieme)
{
	ft_actualize_infos3(elem, twentieme);
	while (elem->min_a <= twentieme)
	{
		ft_manage_pb2(elem);
		ft_actualize_infos3(elem, twentieme);
	}
	if (elem->min_a > twentieme && elem->size_a > 30)
	{
		ft_sort_pile_b_decreas(elem);
		ft_do_it_twice(elem);
	}
	else if (elem->min_a > twentieme && elem->size_a > 3)
	{
		ft_sort_pile_b_decreas(elem);
		ft_do_it_last(elem);
	}
	return ;
}

void	ft_do_it_twice(t_mega *elem)
{
	int twentieme;

	twentieme = ft_get_twentieme(elem);
	while (elem->pile_a[0] > twentieme)
		ft_ra(elem);
	if (elem->pile_a[0] <= twentieme)
		ft_pb(elem);
	while (elem->pile_a[0] > twentieme)
		ft_ra(elem);
	if (elem->pile_a[0] <= twentieme)
		ft_pb(elem);
	if (elem->pile_b[0] < elem->pile_b[1])
		ft_sb(elem);
	ft_actualize_infos3(elem, twentieme);
	ft_get_the_rest(elem, twentieme);
	return ;
}
