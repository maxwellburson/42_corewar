/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 18:52:02 by mburson           #+#    #+#             */
/*   Updated: 2017/03/04 18:52:04 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

#include <stdint.h>

struct		s_game
{
	char				arena[MEM_SIZE];
	struct s_champ		*champs;
	struct t_vect		*pc;
	unsigned int		time_to_death;
	struct s_champ		*winner;
};

struct		s_champ
{
  	char			prog_name[PROG_NAME_LENGTH + 1];
  	char			comment[COMMENT_LENGTH + 1];
	unsigned int	lives;
};

extern		int32_t		g_flags;

# define	FLAG_V		0x1
# define	FLAG_N		0x2
# define	FLAG_D		0x4
# define	FLAG_S		0x8
# define	FLAG_B		0x10

/*
** flags_get.c
*/
int			flags_get(int *argc, char ***argv);

/*
** game_init.c
*/
int			game_init(int argc, char **argv, struct s_game *game);

/*
** game_step/game_step.c
*/
int			game_step(struct s_game *game);

/*
** game_print/game_print.c
*/
int			game_print(struct s_game *game);

#endif
