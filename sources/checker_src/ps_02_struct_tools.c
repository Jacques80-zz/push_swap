/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_02_struct_tools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdouniol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 10:18:11 by jdouniol          #+#    #+#             */
/*   Updated: 2018/12/18 10:18:14 by jdouniol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ps_02_struct_tools.c                                     |
**   |     ft_id_max_pile_a(13 lines)                           |
**   |     ft_id_min_pile_a(13 lines)                           |
**   |     ft_min_pile_a(17 lines)                              |
**   |     ft_max_pile_a(17 lines)                              |
**   |     ft_average_pile_a(11 lines)                          |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include "../../includes/push_swap.h"

int	ft_id_max_pile_a(t_mega *elem)
{
	int i;
	int j;

	i = -1;
	j = 0;
	if (!(elem->pile_a))
		return (0);
	while (++i < elem->size_a)
	{
		if (elem->pile_a[i] > elem->pile_a[j])
			j = i;
	}
	return (j);
}

int	ft_id_min_pile_a(t_mega *elem)
{
	int i;
	int j;

	i = -1;
	j = 0;
	if (!(elem->pile_a))
		return (0);
	while (++i < elem->size_a)
	{
		if (elem->pile_a[i] < elem->pile_a[j])
			j = i;
	}
	return (j);
}

int	ft_min_pile_a(t_mega *elem)
{
	int min;
	int i;

	i = -1;
	if (!(elem->pile_a))
		return (0);
	min = elem->pile_a[0];
	while (++i < elem->size_a)
	{
		if (elem->pile_a[i] < min)
		{
			min = elem->pile_a[i];
		}
		else
			continue;
	}
	return (min);
}

int	ft_max_pile_a(t_mega *elem)
{
	int max;
	int i;

	i = -1;
	if (!(elem->pile_a))
		return (0);
	max = elem->pile_a[0];
	while (++i < elem->size_a)
	{
		if (elem->pile_a[i] > max)
		{
			max = elem->pile_a[i];
		}
		else
			continue;
	}
	return (max);
}

int	ft_average_pile_a(t_mega *elem)
{
	int somme;
	int i;

	i = 0;
	somme = 0;
	while (i < elem->size_a)
	{
		somme = somme + elem->pile_a[i];
		i++;
	}
	return ((somme / elem->size_a));
}
