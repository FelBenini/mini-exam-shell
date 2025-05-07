/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:22:56 by fbenini-          #+#    #+#             */
/*   Updated: 2025/05/07 20:34:24 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

#define BOLD "\033[1m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RESET "\033[0m"
#define PURPLE "\033[0;35m"

#include <stdio.h>
#define MSG_INSTRUCTIONS "Welcome to mini exam shell, a 42 Exam Environment Simulator!\n" BOLD GREEN"• grademe" RESET " - Submit an exercise for evaluation\n" BOLD PURPLE"• finish" RESET " - End the exam shell and submit it\n"

#endif
