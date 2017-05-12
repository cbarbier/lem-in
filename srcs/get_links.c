/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 17:47:59 by cbarbier          #+#    #+#             */
/*   Updated: 2017/05/12 19:20:18 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_node		*get_room(t_node *rooms, char *name)
{
	while (rooms)
	{
		if (!ft_strcmp(rooms->name, name))
			return (rooms);
		rooms = rooms->next;
	}
	return (0);
}

int			save_links(t_lemin *lemin, char *line)
{
	int		ret;

	ret = 1;
	if (!ft_strncmp(line, "##", 2))
		ret = 0;
	if (ret && ft_strnchr(line, '-') != 1)
		ret = 0;
	if (!(links_to_tab(lemin, lemin->links, line)))
		ret = 0;
	if (ret)
		lemin->nb_link++;
	return (ret);
}

static int	set_a_link(t_node *r1, t_node *r2)
{
	int		index;

	if (!r1->child &&
	!(r1->child = (t_node **)ft_memalloc(r1->nb_child * sizeof(t_node *))))
		return (0);
	index = 0;
	while (index < r1->nb_child && r1->child[index])
		index++;
	r1->child[index] = r2;
	return (1);
}

int			set_links(t_node ***links)
{
	if (!links)
		return (0);
	while (*links)
	{
		set_a_link((*links)[0], (*links)[1]);
		set_a_link((*links)[1], (*links)[0]);
		links++;
	}
	return (1);
}
