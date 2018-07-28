/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 19:23:01 by vmiachko          #+#    #+#             */
/*   Updated: 2018/07/28 17:05:53 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H

# define COMMANDS_H

# include "vm.h"

# define ADD_SUB    84
# define AFF_COD  64
# define LD_COD(x)	(x != 144 && x != 208)
# define ST_COD(x)  (x != 80 && x != 112)
# define STI_COD(x) (x != 84 &&  x != 100 &&  x != 116 && x != 120)
# define STI(x)  (x != 88 && x != 104)

# define AND_OR(x) ( x != 84 && x != 148 &&  x != 212 && x !=  244 && x != 180)
# define AND_XOR(x) (x != 118 &&  x != 100 && x != 228 && x != 164)
# define LDI_COD(x) (x != 84 && x != 212 && x != 148 && x !=  164)
# define LLDI_COD(x) (x != 228 && x != 100)

int					ft_get_int(t_union *un, int start, int lenght);
uint8_t				*ft_get_char_from_int(t_pc *pc, unsigned int num);
void				ft_check_codage(uint8_t codage, t_union *un);
void				ft_live(t_pc *pc, t_union *un);
void				ft_load(t_pc *pc, t_union *un);
void				ft_st(t_pc *pc, t_union *un);
void				ft_add(t_pc *pc, t_union *un);
void				ft_sub(t_pc *pc, t_union *un);
void				ft_and(t_pc *pc, t_union *un);
void				ft_or(t_pc *pc, t_union *un);
void				ft_xor(t_pc *pc, t_union *un);
void				ft_zjmp(t_pc *pc, t_union *un);
void				ft_ldi(t_pc *pc, t_union *un);
void				ft_sti(t_pc *pc, t_union *un);
void				ft_fork(t_pc *pc, t_union *un);
void				ft_lld(t_pc *pc, t_union *un);
void				ft_lldi(t_pc *pc, t_union *un);
void				ft_lfork(t_pc *pc, t_union *un);
void				ft_aff(t_pc *pc, t_union *un);
t_pc				*pc_copy(t_pc *prev, int position);
void				choose_number_cycles_to_wait(t_pc *pc, t_union *un);
void				choose_commands(t_pc *pc, t_union *un);
int					ft_check_position(int position);
void				ft_sti_ind_reg(t_pc *pc, t_union *un);
void				ft_sti_dir_reg(t_pc *pc, t_union *un);
void				ft_sti_reg_dir(t_pc *pc, t_union *un);
void				ft_sti_dir_dir(t_pc *pc, t_union *un);
void				ft_sti_ind_dir(t_pc *pc, t_union *un);
void				ft_and_ind_dir(t_pc *pc, t_union *un);
void				ft_and_reg_dir(t_pc *pc, t_union *un);
void				ft_and_dir_dir(t_pc *pc, t_union *un);
void				ft_and_dir_ind(t_pc *pc, t_union *un);
void				ft_and_reg_ind(t_pc *pc, t_union *un);
void				ft_or_reg_dir(t_pc *pc, t_union *un);
void				ft_or_dir_dir(t_pc *pc, t_union *un);
void				ft_or_ind_dir(t_pc *pc, t_union *un);
void				ft_or_reg_ind(t_pc *pc, t_union *un);
void				ft_or_dir_ind(t_pc *pc, t_union *un);
void				ft_xor_reg_dir(t_pc *pc, t_union *un);
void				ft_xor_dir_dir(t_pc *pc, t_union *un);
void				ft_xor_ind_dir(t_pc *pc, t_union *un);
void				ft_xor_reg_ind(t_pc *pc, t_union *un);
void				ft_xor_dir_ind(t_pc *pc, t_union *un);

#endif
