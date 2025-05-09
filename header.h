/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:22:56 by fbenini-          #+#    #+#             */
/*   Updated: 2025/05/07 21:13:58 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

#define BOLD "\033[1m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"
#define PURPLE "\033[0;35m"
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <errno.h>
#define MSG_INSTRUCTIONS "Welcome to mini exam shell, a 42 Exam Environment Simulator!\n\n Mini exam shell is a traning ground for 42 students-a stress-free simulator to\n master the exam environment, build confidence, and adapt before the real battle.\n\n" YELLOW BOLD"• start" RESET " - Start the exam shell session\n" BOLD GREEN"• grademe" RESET " - Submit an exercise for evaluation\n" BOLD PURPLE"• finish" RESET " - End the exam shell and submit it\n"
void	print_banner(void);
void	cmd_help(void);
void	cmd_hello(void);
void	cmd_start(void);
void	cmd_finish(void);
void	cmd_grademe(void);
void cmd_grademe(void);

#endif
