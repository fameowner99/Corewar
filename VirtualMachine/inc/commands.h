/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 19:23:01 by vmiachko          #+#    #+#             */
/*   Updated: 2018/07/27 19:23:37 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H

# define COMMANDS_H

#include "vm.h"

int					ft_get_int(t_union *un, int start, int lenght);
uint8_t* ft_get_char_from_int(t_pc *pc, unsigned int num);
int ft_check_codage(uint8_t codage,  int num_args, int number_command,t_union *un);
void				ft_live(t_pc *pc, t_union *un);
void ft_load(t_pc *pc, t_union *un);
void ft_st(t_pc *pc, t_union *un);
void ft_add(t_pc *pc, t_union *un);
void ft_sub(t_pc *pc, t_union *un);
void ft_and(t_pc *pc, t_union *un);
void ft_or(t_pc *pc, t_union *un);
void ft_xor(t_pc *pc, t_union *un);
void ft_zjmp(t_pc *pc, t_union *un);
void ft_ldi(t_pc *pc, t_union *un);
void ft_sti(t_pc *pc, t_union *un);
void ft_fork(t_pc *pc, t_union *un);
void ft_lld(t_pc *pc, t_union *un);
void ft_lldi(t_pc *pc, t_union *un);
void ft_lfork(t_pc *pc, t_union *un);
void ft_aff(t_pc *pc, t_union *un);
t_pc    *pc_copy(t_pc *prev, int position);
void choose_number_cycles_to_wait(t_pc *pc, t_union *un);
void choose_commands(t_pc *pc, t_union *un);

#endif
