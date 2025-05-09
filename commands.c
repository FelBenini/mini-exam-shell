/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsilveir- <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:22:15 by wsilveir-         #+#    #+#             */
/*   Updated: 2025/05/09 01:47:25 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void cmd_help(void) {
	printf("Available commands: help, hello, exit\n");
}

void cmd_hello(void) {
	printf("Hello! This is a command example.\n");
}

void cmd_exit(void) {
	printf("Leaving the program.\n");
}
