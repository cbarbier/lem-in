/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 13:48:56 by cbarbier          #+#    #+#             */
/*   Updated: 2017/05/09 18:51:05 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inlcudes/lemin.h"

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

	lemin->map = ft_str_to_map(lemnin->file, str);
	if (ft_strcmp(str + 2, "start") && ft_strcmp(str + 2, "start"))
		return (0);
	line = 0;
	while ((ret = get_next_line(0, &line)) > 0 && is_valid_line(line) < 0)
		lemin->map = ft_str_to_map(lemnin->file, line);
	if (ret <= 0)
		return (0);
	if (!(new = add_room(lemin, line)))
		return (new);
	if (!ft_strcmp(str + 2, "start"))
		new->pos = 1;
	else
		new->pos = -1;
	return (1);
}

int			parse_nodes(t_lemin *lemin, char *str)
{
	if (str && !strncmp(str, "##", 2))
		return (set_start_n_end(lemin, str));
	if (str && ft_strchr("#L", str[0]))
		return (0);
	add_room(lemin, str);
	return (1);
}	

