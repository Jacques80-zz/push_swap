/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_03g_resolve_tools2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdouniol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 17:43:52 by jdouniol          #+#    #+#             */
/*   Updated: 2019/01/10 17:43:52 by jdouniol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ps_03g_resolve_tools2.c                                  |
**   |     ft_get_minus_three(23 lines)                         |
**   |     ft_get_twentieme(25 lines)                           |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include "../../includes/push_swap.h"

int	ft_get_minus_three(t_mega *elem)
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
		if (count_plus == 3)
		{
			minus_three = elem->pile_a[i];
			return (minus_three);
		}
		else
			continue;
	}
	return (0);
}

int	ft_get_twentieme(t_mega *elem)
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
		if (count_min == 20 && elem->size_a > 25)
		{
			pivot = elem->pile_a[i];
			return (pivot);
		}
		else if (elem->size_a > 15)
			pivot = ft_get_minus_three(elem);
		else
			continue;
	}
	return (0);
}
