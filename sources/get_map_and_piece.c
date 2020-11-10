/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_and_piece.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmilda <cmilda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 16:38:07 by cmilda            #+#    #+#             */
/*   Updated: 2020/11/10 18:51:12 by cmilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		get_map_size(t_filler *game)
{
	char	*line;
	int		i;

	i = 0;
	if (!get_next_line(0, &line))
		exit(0);
	while (!ft_isdigit(line[i]))
		i++;
	game->x = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	game->y = ft_atoi(&line[i + 1]);
	free(line);
}

void		get_map(t_filler *game)
{
	char	*line;
	int		i;

	i = 0;
	game->mapa = (char**)malloc(sizeof(char*) * (game->x + 1));
	get_next_line(0, &line);
	free(line);
	while (i < game->x)
	{
		get_next_line(0, &line);
		game->mapa[i] = ft_strdup(line + 4);
		free(line);
		i++;
	}
	game->mapa[i] = NULL;
}

void		get_piece(t_filler *game)
{
	char	*line;
	int		i;
	int		size;

	i = 0;
	get_next_line(0, &line);
	while (line[i] && !ft_isdigit(line[i]))
		i++;
	if (line[i] == '0')
		size = 0;
	else
		size = ft_atoi(&line[i]);
	free(line);
	game->piece = (char**)malloc(sizeof(char*) * (size + 1));
	i = 0;
	while (i < size)
	{
		get_next_line(0, &line);
		game->piece[i] = ft_strdup(line);
		free(line);
		i++;
	}
	game->piece[i] = NULL;
}

void		get(t_filler *game)
{
	get_map_size(game);
	get_map(game);
	get_piece(game);
}
