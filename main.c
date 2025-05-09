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

typedef void (*CommandFunc)(void);

typedef struct {
	const char *name;
	CommandFunc func;
} Command;

Command command_list[] = {
	{"help", cmd_help},
	{"hello", cmd_hello},
	{"exit", cmd_exit},
	{NULL, NULL}
};

int main(void)
{
	char input[50];
	bool running = true;

	print_banner();
	printf(MSG_INSTRUCTIONS);

	while (running) {
		printf(GREEN BOLD "examshell" RESET "> ");
		fgets(input, sizeof(input), stdin);
		input[strcspn(input, "\n")] = '\0';

		if (strlen(input) == 0)
			continue;

		bool found = false;
		for (int i = 0; command_list[i].name != NULL; i++) {
			if (strcmp(input, command_list[i].name) == 0) {
				if (strcmp(input, "exit") == 0)
					running = false;
				command_list[i].func();
				found = true;
				break;
			}
		}

		if (!found) {
			printf("Comando desconhecido: %s\n", input);
		}
	}

	return 0;
}


