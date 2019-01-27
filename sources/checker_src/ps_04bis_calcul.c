/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_04bis_calcul.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdouniol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 12:36:27 by jdouniol          #+#    #+#             */
/*   Updated: 2018/12/18 12:36:30 by jdouniol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ps_04bis_calcul.c                                        |
**   |     ft_ra(14 lines)                                      |
**   |     ft_rb(14 lines)                                      |
**   |     ft_rr(22 lines)                                      |
**   |     ft_rra(14 lines)                                     |
**   |     ft_rrb(14 lines)                                     |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include "../includes/push_swap.h"

t_mega	*ft_ra(t_mega *elem)
{
	int tmp;
	int i;

	i = -1;
	if (elem->size_a)
	{
		tmp = elem->pile_a[0];
		while (++i < elem->size_a - 1)
		{
			elem->pile_a[i] = elem->pile_a[i + 1];
		}
		elem->pile_a[elem->size_a - 1] = tmp;
	}
	return (elem);
}

t_mega	*ft_rb(t_mega *elem)
{
	int tmp;
	int i;

	i = -1;
	if (elem->size_b)
	{
		tmp = elem->pile_b[0];
		while (++i < elem->size_b - 1)
		{
			elem->pile_b[i] = elem->pile_b[i + 1];
		}
		elem->pile_b[elem->size_b - 1] = tmp;
	}
	return (elem);
}

t_mega	*ft_rr(t_mega *elem)
{
	ft_ra(elem);
	ft_rb(elem);
	return (elem);
}

t_mega	*ft_rra(t_mega *elem)
{
	int tmp;
	int i;

	if (elem->size_a)
	{
		i = elem->size_a - 1;
		tmp = elem->pile_a[elem->size_a - 1];
		while (i >= 1)
		{
			elem->pile_a[i] = elem->pile_a[i - 1];
			i--;
		}
		elem->pile_a[0] = tmp;
	}
	return (elem);
}

t_mega	*ft_rrb(t_mega *elem)
{
	int tmp;
	int i;

	if (elem->size_b)
	{
		i = elem->size_b - 1;
		tmp = elem->pile_b[elem->size_b - 1];
		while (i >= 1)
		{
			elem->pile_b[i] = elem->pile_b[i - 1];
			i--;
		}
		elem->pile_b[0] = tmp;
	}
	return (elem);
}
