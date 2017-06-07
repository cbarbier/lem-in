/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:17:05 by cbarbier          #+#    #+#             */
/*   Updated: 2017/06/07 19:05:38 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int				is_blank_tab(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

static int		parse_nb_ants(t_lemin *lemin)
{
	char	*line;
	int		ret;

	ret = 1;
	line = 0;
	if (get_next_line(0, &line) <= 0)
		return (0);
	lemin->file = ft_str_to_tab(lemin->file, line);
	if (!ft_myatoi(line, &(lemin->nb_ant)))
		ret = 0;
	if (!ret || lemin->nb_ant <= 0)
		ret = 0;
	return (ret);
}

static int		dash_in_name(char *str)
{
	while (*str && *str != ' ' && *str != '\t')
	{
		if (*str == '-')
			return (1);
		str++;
	}
	return (0);
}

static int		parse_helper(t_lemin *lemin)
{
	char	*line;
	int		flag;
	int		ret;

	line = 0;
	if (!parse_nb_ants(lemin))
		return (0);
	flag = 0;
	while ((ret = get_next_line(0, &line)) > 0)
	{
		lemin->file = ft_str_to_tab(lemin->file, line);
		if (!(line[0] == '#' && (line[1] != '#'
		|| (ft_strcmp(line, "##end") && ft_strcmp(line, "##start")))))
		{
			if (dash_in_name(line))
				flag = 1;
			if ((!flag && !parse_nodes(lemin, line))
					|| (flag && !save_links(lemin, line)))
				break ;
		}
	}
	if (!ret)
		ft_strdel(&line);
	return (lemin->nb_link);
}

int				parse(t_lemin *lemin)
{
	if (!parse_helper(lemin))
		return (0);
	if (!lemin->start || !lemin->end)
		return (0);
	if (!lemin->nb_link)
		return (0);
	return (1);
}
