/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_ants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 17:25:38 by cbarbier          #+#    #+#             */
/*   Updated: 2017/05/11 19:05:14 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclucdes/lemin.h"

static t_node	**set_paths(t_start)
{
	t_node	**paths;
	int		index;
	int		index_path;

	if (!(paths = (t_node **)ft_memalloc(lemin->nb_path * sizeof(t_node *))))
		return (0);
	index = 0;
	while (index < start->nb_child)
	{
		if (start->child[index].state < 0)
		{
			index_path = -paths[-start->child[index]->state] - 1;
			paths[index_path] = start->child[index];
		}
		index++;
	}
	return (paths);
}


int				put_ants(t_lemin *lemin)
{
	t_node		**path;
	t_node		*start;
	int			index;

	if (!(path = set_paths(lemin, lemin->start)))
		return (0);
	while (lemin->nb_ant)
	{
		index = 0;
		while (index < lemin->nb_path)
		{
			make_step(paths[index];
		}



	return (1);
}
