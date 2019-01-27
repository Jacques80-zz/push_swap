/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_03d_resolve_actualize.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdouniol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 17:42:51 by jdouniol          #+#    #+#             */
/*   Updated: 2019/01/10 17:42:51 by jdouniol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ps_03d_resolve_actualize.c                               |
**   |     ft_index_approx_plus2(22 lines)                      |
**   |     ft_index_approx_min2(22 lines)                       |
**   |     ft_approx_min_value2(19 lines)                       |
**   |     ft_approx_plus_value2(17 lines)                      |
**   |     ft_actualize_infos3(14 lines)                        |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include "../../includes/push_swap.h"

void	ft_index_approx_plus2(t_mega *elem, int twentieme)
{
	int reference;
	int i;
	int approx_plus;
	int j;

	(void)twentieme;
	i = -1;
	j = -1;
	reference = elem->value_next_twentieme;
	approx_plus = MAX_INT_POS - reference - 1;
	while (++i < elem->size_b)
	{
		if (elem->pile_b[i] - reference < approx_plus - reference
			&& elem->pile_b[i] - reference > 0)
		{
			approx_plus = elem->pile_b[i];
			j = i;
		}
		else
			continue;
	}
	elem->index_approx_plus = j;
}

void	ft_index_approx_min2(t_mega *elem, int twentieme)
{
	int reference;
	int i;
	int approx_min;
	int j;

	(void)twentieme;
	i = -1;
	j = -1;
	reference = elem->value_next_twentieme;
	approx_min = MAX_INT_NEG + reference + 1;
	while (++i < elem->size_b)
	{
		if (elem->pile_b[i] - reference > approx_min - reference
			&& elem->pile_b[i] - reference < 0)
		{
			approx_min = elem->pile_b[i];
			j = i;
		}
		else
			continue;
	}
	elem->index_approx_min = j;
}

void	ft_approx_min_value2(t_mega *elem, int twentieme)
{
	int reference;
	int i;
	int approx_min;

	(void)twentieme;
	i = -1;
	reference = elem->value_next_twentieme;
	approx_min = MAX_INT_NEG + reference + 1;
	while (++i < elem->size_b)
	{
		if (elem->pile_b[i] - reference > approx_min - reference
			&& elem->pile_b[i] - reference < 0)
			approx_min = elem->pile_b[i];
		else
			continue;
	}
	if (approx_min == MAX_INT_NEG + reference + 1)
		approx_min = MAX_INT_NEG;
	elem->approx_min_value = approx_min;
}

void	ft_approx_plus_value2(t_mega *elem, int twentieme)
{
	int reference;
	int i;
	int approx_plus;

	(void)twentieme;
	i = -1;
	reference = elem->value_next_twentieme;
	approx_plus = INT_MAX - reference - 1;
	while (++i < elem->size_b)
	{
		if (elem->pile_b[i] - reference < approx_plus - reference
			&& elem->pile_b[i] - reference > 0)
			approx_plus = elem->pile_b[i];
		else
			continue;
	}
	elem->approx_plus_value = approx_plus;
}

void	ft_actualize_infos3(t_mega *elem, int twentieme)
{
	elem->min_a = ft_min_pile_a(elem);
	elem->index_min_a = ft_id_min_pile_a(elem);
	elem->max_a = ft_max_pile_a(elem);
	elem->index_max_a = ft_id_max_pile_a(elem);
	elem->min_b = ft_min_pile_b(elem);
	elem->index_min_b = ft_id_min_pile_b(elem);
	elem->max_b = ft_max_pile_b(elem);
	elem->index_max_b = ft_id_max_pile_b(elem);
	ft_value_next_twentieme2(elem, twentieme);
	ft_id_next_twentieme2(elem, twentieme);
	ft_approx_plus_value2(elem, twentieme);
	ft_approx_min_value2(elem, twentieme);
	ft_index_approx_plus2(elem, twentieme);
	ft_index_approx_min2(elem, twentieme);
}
