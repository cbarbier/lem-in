/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 13:48:56 by cbarbier          #+#    #+#             */
/*   Updated: 2017/05/10 17:58:32 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static int	is_valid_line(char *line)
{
	if (line && line[0] == '#' && line[1] != '#')
		return (-1);
	if (!line || (*line && ft_strchr("#L", *line)))
		return (0);
	return (1);
}

static int	set_start_n_end(t_lemin *lemin, char *str)
{
	t_node		*new;
	char		*line;
	int			ret;

	if (ft_strcmp(str + 2, "start") && ft_strcmp(str + 2, "end"))
		return (0);
	line = 0;
	while ((ret = get_next_line(0, &line)) > 0 && is_valid_line(line) < 0)
		lemin->file = ft_str_to_tab(lemin->file, line);
	if (ret <= 0)
		return (0);
	else
		lemin->file = ft_str_to_tab(lemin->file, line);
	if (!(new = add_room(lemin, lemin->rooms, line)))
		return (0);
	if (!ft_strcmp(str + 2, "start"))
		lemin->start = new;
	else
		lemin->end = new;
	return (1);
}

int			parse_nodes(t_lemin *lemin, char *str)
{
	if (str && !strncmp(str, "##", 2))
		return (set_start_n_end(lemin, str));
	if (str && ft_strchr("#L", str[0]))
		return (0);
	add_room(lemin, lemin->rooms, str);
	return (1);
}

