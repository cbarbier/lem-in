/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:17:05 by cbarbier          #+#    #+#             */
/*   Updated: 2017/05/09 18:38:13 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static int			parse_nb_ants(t_lemin *lemin)
{
	char	*line;
	int	ret;

	ret = 1;
	line = 0;
	if (get_next_line(0, &line) <= 0)
		return (0);
	else
	lemin->file = ft_str_to_tab(lemin->file, line);
	if (!ft_myatoi(line, &(lemin->nb_ant)))
		ret = 0;
	if (!ret || lemin->nb_ant <= 0)
		ret = 0;
	return (ret);
}

static int		is_dash_in_name(char *str)
{
	while (*str && *str != ' ' && *str != '\t')
	{
		if (*str == '-')
			return (1);
		str++;
	}
	return (0);
}

int				parse(t_lemin *lemin)
{
	char	*line;
	int		flag;

	line = 0;
	if (!parse_nb_ants(lemin))
		return (0);
	ft_printf("nb ants: %d\n", lemin->nb_ant);
	flag = 0;
	while (get_next_line(0, &line) > 0)
	{
		lemin->file = ft_str_to_tab(lemin->file, line);
		if (!(line[0] == '#' && line[1] != '#'))
		{
			if (is_dash_in_name(line))
				flag = 1;
			if ((!flag && !parse_nodes(lemin, line))
					|| (flag && !parse_links(lemin, line)))
				return (0);
		}
		ft_printf("lemin->file next line: %s\n", line);
	}
	return (ret);
}
