/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsilveir- <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:22:15 by wsilveir-         #+#    #+#             */
/*   Updated: 2025/05/07 20:59:53 by wsilveir-        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void cmd_help(void) {
	printf("Comandos disponíveis: help, hello, exit\n");
}

void cmd_hello(void) {
	printf("Olá! Este é um exemplo de comando.\n");
}

void cmd_exit(void) {
	printf("Saindo do programa.\n");
}