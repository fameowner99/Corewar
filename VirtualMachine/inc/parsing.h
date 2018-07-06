/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 12:31:47 by vmiachko          #+#    #+#             */
/*   Updated: 2018/07/05 12:31:49 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H

# define PARSING_H

#include "vm.h"

int 				parsing(int argc, char **argv, t_union *un);
int					check_if_input_correct(char **argv, t_union *un);
int					set_bot_id(t_union *un);
#endif