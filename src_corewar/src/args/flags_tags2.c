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

#include <corewar.h>

int	flag_w(char ***av, char **champ)
{
	(void)champ;
	if (++(*av) && **av && ***av >= '0' && ***av <= '9')
	{
		g_flags.wait_time = (useconds_t)ft_atoui(**av);
		return (0);
	}
	return (-1);
}