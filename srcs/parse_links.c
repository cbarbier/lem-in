/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 18:41:25 by cbarbier          #+#    #+#             */
/*   Updated: 2017/05/09 18:52:05 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include "includes/lemin.h"

int			parse_links(t_lemin *lemin, char *line)
{
	int 	ret;

	ret = 1;
	lemin->file = ft_str_to_tab(lemin->file, line);
	if (!ft_strncmp(str, "##", 2))
		ret = 0;
		
