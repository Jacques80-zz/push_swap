/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_04_calcul.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdouniol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 10:18:51 by jdouniol          #+#    #+#             */
/*   Updated: 2018/12/18 14:56:51 by jdouniol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ps_04_calcul.c                                           |
**   |     ft_sa(6 lines)                                       |
**   |     ft_sb(6 lines)                                       |
**   |     ft_ss(10 lines)                                      |
**   |     ft_pa(22 lines)                                      |
**   |     ft_pb(22 lines)                                      |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include "../../includes/push_swap.h"

t_mega	*ft_sa(t_mega *elem)
{
	int tmp;

	tmp = elem->pile_a[0];
	elem->pile_a[0] = elem->pile_a[1];
	elem->pile_a[1] = tmp;
	return (elem);
}

t_mega	*ft_sb(t_mega *elem)
{
	int tmp;

	tmp = elem->pile_b[0];
	elem->pile_b[0] = elem->pile_b[1];
	elem->pile_b[1] = tmp;
	return (elem);
}

t_mega	*ft_ss(t_mega *elem)
{
	int tmp_a;
	int tmp_b;

	tmp_a = elem->pile_a[0];
	tmp_b = elem->pile_b[0];
	elem->pile_a[0] = elem->pile_a[1];
	elem->pile_b[0] = elem->pile_b[1];
	elem->pile_b[1] = tmp_b;
	elem->pile_a[1] = tmp_a;
	return (elem);
}

t_mega	*ft_pa(t_mega *elem)
{
	int tmp;
	int i;
	int j;

	i = -1;
	j = elem->size_a;
	tmp = elem->pile_b[0];
	if (elem->size_b)
	{
		while (++i < (elem->size_b - 1))
		{
			elem->pile_b[i] = elem->pile_b[i + 1];
		}
		elem->size_b -= 1;
		while (j--)
		{
			elem->pile_a[j + 1] = elem->pile_a[j];
		}
		elem->pile_a[0] = tmp;
		elem->size_a += 1;
	}
	return (elem);
}

t_mega	*ft_pb(t_mega *elem)
{
	int tmp;
	int i;
	int j;

	i = -1;
	j = elem->size_b;
	tmp = elem->pile_a[0];
	if (elem->size_a)
	{
		while (++i < (elem->size_a - 1))
		{
			elem->pile_a[i] = elem->pile_a[i + 1];
		}
		elem->size_a -= 1;
		while (j--)
		{
			elem->pile_b[j + 1] = elem->pile_b[j];
		}
		elem->pile_b[0] = tmp;
		elem->size_b += 1;
	}
	return (elem);
}
