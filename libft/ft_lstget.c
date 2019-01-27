/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdouniol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 07:14:08 by jdouniol          #+#    #+#             */
/*   Updated: 2019/01/15 07:14:10 by jdouniol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list		*ft_lstget(t_list *lst, int n)
{
	while (--n >= 0)
	{
		if (lst == NULL)
			return (NULL);
		lst = lst->next;
	}
	return (lst);
}
