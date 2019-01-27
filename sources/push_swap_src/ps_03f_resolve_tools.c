/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_03f_resolve_tools.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdouniol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 17:43:40 by jdouniol          #+#    #+#             */
/*   Updated: 2019/01/10 17:43:40 by jdouniol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ps_03f_resolve_tools.c                                   |
**   |     ft_check_sort_ps(14 lines)                           |
**   |     ft_check_sort2(15 lines)                             |
**   |     ft_sort_pile_b_decreas_small(18 lines)               |
**   |     ft_sort_very_small2(24 lines)                        |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include "../../includes/push_swap.h"

int		ft_check_sort_ps(t_mega *elem)
{
	int i;

	i = -1;
	while ((++i) < (elem->size_a))
	{
		if ((i + 1 != (elem->size_a) && elem->pile_a[i] < elem->pile_a[i + 1])
			|| ((i + 1) == (elem->size_a)))
			continue;
		else
			break ;
	}
	if (i == elem->size_a && elem->size_b == 0)
		return (1);
	else
		return (0);
}

int		ft_check_sort2(t_mega *elem)
{
	int i;

	i = -1;
	while ((++i) < (elem->size_a))
	{
		if (elem->pile_a[i] < elem->pile_a[i + 1]
			|| ((i + 1) == (elem->size_a)))
			continue ;
		else
			break ;
	}
	if (i == elem->size_a)
		return (1);
	else
		return (0);
}

void	ft_sort_pile_b_decreas_small(t_mega *elem)
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

void	ft_sort_very_small2(t_mega *elem)
{
	if (PRINT_MODE)
		ft_print_array(elem);
	if ((elem->pile_a[0] < elem->pile_a[1] && elem->pile_a[1]
		< elem->pile_a[2] && elem->size_a == 3)
			|| (elem->pile_a[0] < elem->pile_a[1] && elem->size_a == 2))
		return ;
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
	else if (elem->pile_a[0] > elem->pile_a[1] && elem->size_a == 2)
		ft_sa(elem);
	else
		ft_sa(elem) && ft_rra(elem);
	if (PRINT_MODE)
		ft_print_array(elem);
}
