/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_players.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmilda <cmilda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 21:28:39 by cmilda            #+#    #+#             */
/*   Updated: 2020/11/06 21:57:30 by cmilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void        set_players(t_filler *game)
{
    char    *line;
    int     i;
    
    if (!get_next_line(0, &line))
        exit(0);
    i = 0;
    while (line[i] && line[i] != 'p')
        i++;
    if (line[i + 1] == '1')
    {
        game->my = 'x';
        game->enemy = 'o';
    }
    else
    {
        game->my = 'x';
        game->enemy = 'o';
    }
    free(line);
}
