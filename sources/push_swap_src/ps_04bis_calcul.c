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
**   |     ft_ra(15 lines)                                      |
**   |     ft_rb(15 lines)                                      |
**   |     ft_rra(15 lines)                                     |
**   |     ft_rrb(15 lines)                                     |
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
	if (elem->pile_a)
	{
		tmp = elem->pile_a[0];
		while (++i < elem->size_a - 1)
		{
			elem->pile_a[i] = elem->pile_a[i + 1];
		}
		elem->pile_a[elem->size_a - 1] = tmp;
	}
	ft_printf("ra\n");
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
	ft_printf("rb\n");
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
		while (i)
		{
			elem->pile_a[i] = elem->pile_a[i - 1];
			i--;
		}
		elem->pile_a[0] = tmp;
	}
	ft_printf("rra\n");
	return (elem);
}

t_mega	*ft_rrb(t_mega *elem)
{
	int tmp;
	int i;

	if (elem->size_b)
	{
		i = elem->size_b;
		tmp = elem->pile_b[elem->size_b - 1];
		while (i)
		{
			elem->pile_b[i] = elem->pile_b[i - 1];
			i--;
		}
		elem->pile_b[0] = tmp;
	}
	ft_printf("rrb\n");
	return (elem);
}
