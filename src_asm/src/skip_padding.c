/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_padding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 17:21:16 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/17 19:54:34 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

char	*next_token(char *cp)
{
		ft_printf("here:%c\n", *cp);
	while (ft_iswhitespace(*cp) || *cp == '#')
	{
		if (*cp == '#')
			if(!(cp = ft_strchr(cp, '\n')))
				return (NULL);
		cp++;
	}
	return (cp);
}
