/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:22:15 by fbenini-          #+#    #+#             */
/*   Updated: 2025/05/07 20:59:53 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(void)
{
	char input[50];

	print_banner();
	printf(MSG_INSTRUCTIONS);
	printf(GREEN BOLD "examshell" RESET "> ");
	fgets(input, sizeof(input), stdin);
	return (0);
}
