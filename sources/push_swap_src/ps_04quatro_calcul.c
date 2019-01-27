/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_04quatro_calcul.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdouniol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 12:37:27 by jdouniol          #+#    #+#             */
/*   Updated: 2018/12/18 12:37:44 by jdouniol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ps_04ter_calcul.c                                        |
**   |     ft_rrr(23 lines)                                     |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include "../includes/push_swap.h"

t_mega	*ft_ra2(t_mega *elem)
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
	return (elem);
}

t_mega	*ft_rb2(t_mega *elem)
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
	ft_ra2(elem);
	ft_rb2(elem);
	ft_printf("rr\n");
	return (elem);
}
