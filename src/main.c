/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmilda <cmilda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 21:15:45 by cmilda            #+#    #+#             */
/*   Updated: 2020/11/09 19:30:05 by cmilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "filler.h"

int				main(void)
{
    t_filler	*game;
    
    game = malloc(sizeof(t_filler));
    set_players(game);
    while (play(game))
      continue ;
    return (0);
}
