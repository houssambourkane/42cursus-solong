/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:39:00 by hbourkan          #+#    #+#             */
/*   Updated: 2021/12/18 13:49:04 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	compteur_nombre(int n)
{
	int		cpt;
	long	n2;

	cpt = 0;
	n2 = n;
	if (n2 < 0)
		n2 = n2 * -1;
	if (n2 == 0)
		return (1);
	while (n2 > 0)
	{
		n2 = n2 / 10;
		cpt++;
	}
	return (cpt);
}

static char	calcul(long *n2)
{
	char	n;

	n = *n2 % 10 + '0';
	*n2 /= 10;
	return (n);
}

char	*ft_itoa(int n)
{
	char	*nb;
	long	n2;
	int		cpt_digit;

	n2 = n;
	cpt_digit = compteur_nombre(n);
	if (n2 < 0)
		cpt_digit++;
	nb = malloc(sizeof(char) * (cpt_digit + 1));
	if (nb == NULL)
		return (NULL);
	if (n2 < 0)
	{
		nb[0] = '-';
		n2 = n2 * -1;
	}
	else if (n2 == 0)
		nb[0] = '0';
	nb[cpt_digit] = '\0';
	cpt_digit--;
	while (n2 > 0)
		nb[cpt_digit--] = calcul(&n2);
	return (nb);
}
