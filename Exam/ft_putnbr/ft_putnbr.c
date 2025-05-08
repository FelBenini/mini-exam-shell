/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsilveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 22:01:53 by wsilveir          #+#    #+#             */
/*   Updated: 2025/05/07 22:01:54 by wsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int nb)
{
	char	ld;
	int		rd;
	int		negative;

	negative = 0;
	ld = nb % 10;
	rd = nb / 10;
	if (ld < 0)
	{
		ld = ld * -1;
		negative = 1;
	}
	ld = ld + '0';
	if (rd != 0)
		ft_putnbr (rd);
	else
	{
		if (negative == 1)
			ft_putchar ('-');
	}
	ft_putchar (ld);
}
