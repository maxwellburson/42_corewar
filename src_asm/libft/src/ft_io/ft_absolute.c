/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absolute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:58:59 by kdavis            #+#    #+#             */
/*   Updated: 2016/12/05 13:03:25 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Returns the absolute value of a long long.
*/

unsigned long long	ft_absolute(long long n)
{
	return (n < 0 ? -n : n);
}
