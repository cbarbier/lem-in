/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:17:05 by cbarbier          #+#    #+#             */
/*   Updated: 2017/05/03 18:17:41 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int				parse(t_lemin *lemin)
{
	char	*line;
	int	ret;

	ret = 1;
	if (get_next_line(0, &line) <= 0)
		return (0);
	if (!ft_myatoi(line, &(lemin->nb_ant)))
		ret = 0;
	ft_strdel(&line);
	if (lemin->nb_ant <= 0)
		ret = 0;
	ft_printf("nb ants: %d\n", lemin->nb_ant);	
	return (ret);
}
