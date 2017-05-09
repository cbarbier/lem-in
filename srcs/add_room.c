/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 17:28:48 by cbarbier          #+#    #+#             */
/*   Updated: 2017/05/09 18:49:48 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static char		**check_room(char *str, char ***infos, int *coords)
{
	char	**t; 
	int		ret;

	ret = 1;
	if (!str || !*str)
		return (0);
	if (!(t = ft_strsplit(str, is_blank_tab(str))) || ft_strtablen(t) != 3)
		ret = 0;
	if (ret && !ft_myatoi(res[1], coords))
		ret = 0;
	if (ret && !ft_myatoi(res[2], coords + 1))
		ret = 0;
	*infos = t;
	return (ret);
}

static t_node	*create_node(t_lemin *lemin, char *str, int *co)
{
	t_node		*new;

	if (!(new = ft_memalloc(sizeof(t_node))))
			return (0);
	new->name = ft_strdup(str);
	new->x = co[0];
	new->y = co[1];
	return (1);
}

static int		add_list(t_lemin *lemin, t_node **lst,  char *str, int *co)
{
	t_node		*tmp;
	t_node		*new;

	tmp = *lst;
	while (lst && (tmp = lst))
	{
		if (!ft_strcmp(lst->name, str))
			return (0);
		else
			lst = lst->next;
	}
	if (!(new = create_node(lemin, str, co)))
	if (!tmp)
		*lst = new;
	else
		tmp->next = new;
	return (new);
}

t_node			*add_room(t_lemin *lemin, t_node *lst,  char *str)
{
	char	**infos;
	int		coords[2];
	t_node	*ret;

	ret = 0;
	if (!(infos = check_room(str, &infos, coords)))
		ret = 0;
	if (ret && !(ret = add_list(lemin, &(lemin->rooms), res[0], coords)))
		ret = 0;
	ft_strtabdel(&infos);
	return (ret);
}

