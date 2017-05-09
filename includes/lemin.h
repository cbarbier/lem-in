/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 14:12:45 by cbarbier          #+#    #+#             */
/*   Updated: 2017/05/09 19:24:56 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "../libft/includes/libft.h"

typedef struct	s_node
{
	int				id;
	char			*name;
	int				x;
	int				y;
	char			pos;
	struct s_node	*child;
	struct s_node	*next;
	char			state;
}				t_node;

typedef struct	s_lemin
{
	char	**file;
	int		nb_ant;
	int		nb_room;
	int		nb_link;
	t_node	*rooms;
	t_list	*paths;
}				t_lemin;
int				parse(t_lemin *lemin);
int				add_room(t_lemin *lemin, t_node *lst,  char *str);
int				parse_nodes(t_lemin *lemin, char *str);

#endif
