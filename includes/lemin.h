/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 14:12:45 by cbarbier          #+#    #+#             */
/*   Updated: 2017/05/03 18:20:44 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "../libft/includes/libft.h"

typedef struct	s_node
{
	char			*name;
	struct s_node	*child;
	struct s_node	*next;
	char			visited;
}				t_node;

typedef struct	s_lemin
{
	int		nb_ant;
	int		nb_room;
	int		nb_link;
	t_node	*nodes;
	t_node	*queue;
	t_node	*start;
	t_node	*end;
	t_list	*paths;
}				t_lemin;
int				parse(t_lemin *lemin);

#endif
