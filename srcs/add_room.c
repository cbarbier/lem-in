/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 17:28:48 by cbarbier          #+#    #+#             */
/*   Updated: 2017/05/12 17:46:46 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static char		**check_room(char *str, char ***infos, int *coords)
{
	char	**t;
	int		ret;

	ret = 1;
	if (!str || !*str)
		return (0);
	if (!(t = ft_strsplitif(str, is_blank_tab)) || ft_strtablen(t) != 3)
		ret = 0;
	if (ret && !ft_myatoi(t[1], coords))
		ret = 0;
	if (ret && !ft_myatoi(t[2], coords + 1))
		ret = 0;
	*infos = t;
	return (ret ? t : 0);
}

static t_node	*create_node(t_lemin *lemin, char *str, int *co)
{
	t_node		*new;

	(void)lemin;
	if (!(new = ft_memalloc(sizeof(t_node))))
		return (0);
	if (!(new->name = ft_strdup(str)))
		return (0);
	new->x = co[0];
	new->y = co[1];
	return (new);
}

static t_node	*add_list(t_lemin *lemin, t_node **alst, char *str, int *co)
{
	t_node		*tmp;
	t_node		*new;
	t_node		*lst;

	lst = *alst;
	tmp = lst;
	new = 0;
	while (lst && (tmp = lst))
	{
		if (!ft_strcmp(lst->name, str))
			return (0);
		else
			lst = lst->next;
	}
	if (!(new = create_node(lemin, str, co)))
		return (0);
	if (!tmp)
		*alst = new;
	else
		tmp->next = new;
	return (new);
}

t_node			*add_room(t_lemin *lemin, t_node *lst, char *str)
{
	char	**infos;
	int		coords[2];
	int		ret;
	t_node	*new;

	(void)lst;
	ret = 1;
	new = 0;
	if (!(infos = check_room(str, &infos, coords)))
		ret = 0;
	if (ret && !(new = add_list(lemin, &(lemin->rooms), infos[0], coords)))
		ret = 0;
	ft_strtabdel(&infos);
	if (ret)
		lemin->nb_room++;
	return (ret ? new : 0);
}
