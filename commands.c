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
#define MAX_LEVELS 3
bool exam_started = false;

int current_level = 0;
int current_exercise_index = -1;

const char *exercise_levels[MAX_LEVELS][3] = {
	{"ft_strcpy", "ft_strlen", "ft_strdup"},
	{"ft_strcat", "ft_strcmp", "ft_strchr"},
	{"ft_atoi", "ft_isalpha", "ft_toupper"}
};

void cmd_help(void) {
	printf("Available commands: start, help, hello, finish\n");
}

void cmd_hello(void) {
	printf("Hello! This is a command example.\n");
}

void cmd_start(void) {
	exam_started = true;

	// Obter o caminho da home
	const char *home = getenv("HOME");
	if (home == NULL) {
		perror("Erro ao obter a HOME");
		return;
	}
	
	// Criar caminhos completos para as pastas 'rendu' e 'subject'
	char rendu_path[512];
	char subject_path[512];
	char exercise_folder_path[512];
	
	snprintf(rendu_path, sizeof(rendu_path), "%s/rendu", home);
	snprintf(subject_path, sizeof(subject_path), "%s/subject", home);
	
	// Criar ~/rendu
	if (mkdir(rendu_path, 0755) == 0) {
		printf(GREEN "📁 'rendu/' folder created at %s\n" RESET, rendu_path);
	} else if (errno == EEXIST) {
		printf(YELLOW "⚠️  'rendu/' folder already exists at %s\n" RESET, rendu_path);
	} else {
		perror("Erro ao criar a pasta 'rendu'");
	}
	
	// Criar ~/subject
	if (mkdir(subject_path, 0755) == 0) {
		printf(GREEN "📁 'subject/' folder created at %s\n" RESET, subject_path);
	} else if (errno == EEXIST) {
		printf(YELLOW "⚠️  'subject/' folder already exists at %s\n" RESET, subject_path);
	} else {
		perror("Erro ao criar a pasta 'subject'");
	}
	
	// Sorteio do exercício atual
	srand(time(NULL));
	current_exercise_index = rand() % 3; // Sorteia um exercício aleatório do nível atual
	const char *exercise_name = exercise_levels[current_level][current_exercise_index];
	
	// Criar a pasta para o exercício dentro de ~/subject
	snprintf(exercise_folder_path, sizeof(exercise_folder_path), "%s/%s", subject_path, exercise_name);
	
	if (mkdir(exercise_folder_path, 0755) == 0) {
		printf(GREEN "📁 Exercise folder '%s' created at %s\n" RESET, exercise_name, exercise_folder_path);
	} else if (errno == EEXIST) {
		printf(YELLOW "⚠️  Exercise folder '%s' already exists at %s\n" RESET, exercise_name, exercise_folder_path);
	} else {
		perror("Erro ao criar a pasta do exercício");
	}
	time_t now = time(NULL);
	struct tm *t = localtime(&now);

	srand(time(NULL));
	if (current_exercise_index == -1)
		current_exercise_index = rand() % 3;

	const char *exercise = exercise_levels[current_level][current_exercise_index];

	printf(BOLD WHITE "Welcome to the exam\n" RESET);
	printf("Date: %02d/%02d/%d\n", t->tm_mday, t->tm_mon + 1, t->tm_year + 1900);
	printf("Time: %02d:%02d:%02d\n", t->tm_hour, t->tm_min, t->tm_sec);
	printf("User: " CYAN "fbenini-" RESET "\n");
	printf("Terminal: " GREEN "/dev/exam" RESET "\n\n");

	printf(BOLD YELLOW "Instructions:\n" RESET);
	printf("You must solve the following exercise and place your solution in the " BOLD "rendu/" RESET " folder.\n");
	printf("Do not forget to name the file as specified in the subject.\n\n");

	printf(BOLD MAGENTA "Level: %d\n" RESET, current_level);
	printf("Exercise: " BOLD "%s\n\n" RESET, exercise);

	printf(BOLD CYAN "Attempts: [0/10]\n" RESET);
	printf("Timer: " RED BOLD "00:00:00" RESET "\n");

	printf(BOLD GREEN "\n> Exam environment initialized successfully!\n\n" RESET);
}

void cmd_grademe(void) {
	if (!exam_started) {
		printf(BOLD RED "⚠️  You must start the exam first by typing 'start'.\n" RESET);
		return;
	}
	
	if (current_level >= MAX_LEVELS) {
		printf(BOLD GREEN "🎉 You have completed all levels! Exam finished.\n" RESET);
		return;
	}

	printf("✅ Your solution for '%s' has been accepted!\n\n",
		exercise_levels[current_level][current_exercise_index]);

	current_level++;

	if (current_level >= MAX_LEVELS) {
		printf(BOLD GREEN "🎓 Congratulations! You finished the last level.\n" RESET);
		return;
	}

	srand(time(NULL));
	current_exercise_index = rand() % 3;
	const char *next_exercise = exercise_levels[current_level][current_exercise_index];

	time_t now = time(NULL);
	struct tm *t = localtime(&now);

	printf(BOLD WHITE "Welcome to the exam\n" RESET);
	printf("Date: %02d/%02d/%d\n", t->tm_mday, t->tm_mon + 1, t->tm_year + 1900);
	printf("Time: %02d:%02d:%02d\n", t->tm_hour, t->tm_min, t->tm_sec);
	printf("User: " CYAN "fbenini-" RESET "\n");
	printf("Terminal: " GREEN "/dev/exam" RESET "\n\n");

	printf(BOLD YELLOW "Instructions:\n" RESET);
	printf("You must solve the following exercise and place your solution in the " BOLD "rendu/" RESET " folder.\n");
	printf("Do not forget to name the file as specified in the subject.\n\n");

	printf(BOLD MAGENTA "Level: %d\n" RESET, current_level);
	printf("Exercise: " BOLD "%s\n\n" RESET, next_exercise);

	printf(BOLD CYAN "Attempts: [0/10]\n" RESET);
	printf("Timer: " RED BOLD "00:00:00" RESET "\n");

	printf(BOLD GREEN "\n> Exam environment initialized successfully!\n\n" RESET);
}


void cmd_finish(void) {
	printf("Leaving the program.\n");
}