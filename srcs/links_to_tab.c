/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links_to_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 09:53:46 by cbarbier          #+#    #+#             */
/*   Updated: 2017/05/11 16:10:47 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static int		link_split(char c)
{
	if (c == ' ' || c == '\t' || c == '-')
		return (1);
	return (0);
}

static int		is_unique(t_node ***links, t_node **new)
{
	if (!links)
		return (1);
	while (*links)
	{
		if ((!ft_strcmp((*links)[0]->name, new[0]->name)
			&& (!ft_strcmp((*links)[1]->name, new[1]->name))) ||
			(!ft_strcmp((*links)[1]->name, new[0]->name)
			&& (!ft_strcmp((*links)[0]->name, new[1]->name))))
			return (0);
			links++;
	}
	return (1);
}

static t_node	**str_to_link(t_lemin *lemin, char *str)
{
	int			ret;
	char		**infos;
	t_node		**lk;

	ret = 1;
	lk = 0;
	if (!(infos = ft_strsplitif(str, link_split))
		|| !(lk = (t_node **)ft_memalloc(2 * sizeof(t_node *))))
		ret = 0;
	if (ret && (ft_strtablen(infos) != 2))
		ret = 0;
	if (ret && (!(lk[0] = get_room(lemin->rooms, infos[0]))
		|| !(lk[1] = get_room(lemin->rooms, infos[1]))))
		ret = 0;
	ft_strtabdel(&infos);
	if (!ret && lk)
		free(lk);
	return (ret ? lk : 0);
}

static t_node	***create_tab(t_node **link)
{
	t_node		***new;

	if (!(new = (t_node ***)ft_memalloc(2 * sizeof(t_node **))))
		return (0);
	new[0] = link;
	link[0]->nb_child++;
	link[1]->nb_child++;
	return (new);
}

t_node			***links_to_tab(t_lemin *lemin, t_node ***tab, char *str)
{
	t_node	***new;
	t_node	**link;
	int		len;

	if (!(link = str_to_link(lemin, str)))
		return (0);
	if (link[0] == link[1] || !is_unique(lemin->links, link))
	{
		free(link);
		return (tab);
	}
	if (!tab)
		return (create_tab(link));
	len = 0;
	while (tab[len])
		len++;
	if (!(new = (t_node ***)ft_memalloc((len + 2) * sizeof(t_node **))))
		return (0);
	link[0]->nb_child++;
	link[1]->nb_child++;
	ft_memcpy((void *)new, (void *)tab, len * sizeof(t_node **));
	new[len] = link;
	free((void *)tab);
	return (new);
}
