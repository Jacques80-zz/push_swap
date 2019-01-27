/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_01_parse_and_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdouniol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 10:17:59 by jdouniol          #+#    #+#             */
/*   Updated: 2019/01/23 19:02:33 by jdouniol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ps_01_parse_and_init.c                                   |
**   |     ft_check_error_in_str(20 lines)                      |
**   |     ft_all_in_one_str_aux(16 lines)                      |
**   |     ft_all_in_one_str(17 lines)                          |
**   |     ft_nbi(13 lines)                          |
**   |     ft_str_to_int_array(25 lines)                        |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include "../../includes/push_swap.h"

int		ft_check_error_in_str(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) || ft_isspace(str[i]) || (str[i] == '-'
			&& ft_isdigit(str[i + 1])))
			i++;
		else
			break ;
	}
	if (str[i] == '\0')
	{
		return (0);
	}
	else
	{
		ft_error();
		return (-1);
	}
}

char	*ft_all_in_one_str_aux(char **av, char *str)
{
	int lol;
	int tmp;

	lol = 1;
	tmp = ft_strlen(av[1]);
	str[tmp] = ' ';
	str[tmp + 1] = '\0';
	while (av[++lol])
	{
		ft_strcat(str, av[lol]);
		if (av[lol + 1])
		{
			tmp = ft_strlen(str);
			str[tmp] = ' ';
			str[tmp + 1] = '\0';
		}
	}
	return (str);
}

char	*ft_all_in_one_str(int ac, char **av)
{
	size_t	size;
	char	*str;

	size = size_of_args(av + 1);
	if (!(str = malloc(sizeof(char) * (size + (ac - 1)) + 1)))
		return (NULL);
	str[(size + (ac - 1))] = '\0';
	ft_strcpy(str, av[1]);
	str[ft_strlen(av[1])] = '\0';
	if (ac > 2)
		str = ft_all_in_one_str_aux(av, str);
	if (ft_check_error_in_str(str))
	{
		free(str);
		return (NULL);
	}
	return (str);
}

int		ft_nbi(char const *s, char c)
{
	int		nbr;
	char	space;

	nbr = 0;
	space = ' ';
	while (*s)
	{
		if (*s && *s != c && space == c)
			nbr++;
		space = *s;
		s++;
	}
	return (nbr);
}

int		*ft_str_to_int_array(char const *s, char c)
{
	int		count;
	int		*array;
	int		start;
	int		end;
	char	*str;

	if (!s || !(array = (int *)malloc(sizeof(int) * (ft_nbi(s, c)))))
		return (NULL);
	ft_init_to_null(&str, &count, &start);
	while (s[start])
	{
		if (s[start] != c && s[start] != '\0')
		{
			end = start;
			while (s[end] != c && s[end] != '\0')
				end++;
			if (ft_isint(ft_atol((str = ft_strsub(s, start, end - start)))))
				array[count++] = ft_transit_int(ft_atoi(str), str);
			else
				return ((int *)ft_free_two((void *)str, (void *)array));
			start = end - 1;
		}
		start++;
	}
	return (array);
}
