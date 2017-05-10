/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:17:05 by cbarbier          #+#    #+#             */
/*   Updated: 2017/05/10 20:40:39 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static int		put_tree(t_lemin *lemin)
{
	t_node		*rooms;
	int			index;

	rooms = lemin->rooms;
	ft_printf("{red}TREE{no}\n");
	while (rooms)
	{
		index = 0;
		if (rooms == lemin->start)
			ft_printf("{red}start{no}\n");
		if (rooms == lemin->end)
			ft_printf("{red}end{no}\n");
		ft_printf("{grn}%s {yel}[%d,  %d]{no}  nb_child: %d\n", rooms->name, rooms->x, rooms->y, rooms->nb_child);
		while (index < rooms->nb_child)
			ft_printf("{blu} %s", rooms->child[index++]->name);
		ft_printf("\n{grn}------------{no}\n");
		rooms = rooms->next;
	}
	ft_printf("{red}END OF TREE{no}\n");
	return (1);
}

int				main(int argc, char **argv)
{
	t_lemin		lemin;
	t_node		*end;
	(void)argv;
	(void)argc;

	ft_bzero(&lemin, sizeof(t_lemin));
	if (!parse(&lemin) || !set_links(lemin.links))
	{
		ft_printf("ERROR\n");
		return (0);
	}
	ft_putstrtab(lemin.file);
	put_tree(&lemin);
	lemin.start->state = 1;
	bfs(&lemin, lemin.start);
	ft_printf("bfs done!\n");
	end = lemin.end;
	while (end)
	{
		ft_printf("%s\n", end->name);
		end = end->pprev;
	}
	return (1);
}
