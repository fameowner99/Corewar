//
// Created by Tetiana PIVEN on 7/27/18.
//

#include "../../inc/vm.h"
#include "../../inc/commands.h"

void ft_xor_reg_reg(t_pc *pc, t_union *un)
{
	unsigned int one;
	unsigned int two;
	unsigned int three;

	one = un->map[ft_check_position(pc->curr_position + 2)].value;
	two = un->map[ft_check_position(pc->curr_position + 3)].value ;
	three = un->map[ft_check_position(pc->curr_position + 4)].value ;
	if (one <= 16 && one > 0 && two <= 16 && two > 0 && three <= 16 && three > 0)
	{
		pc->reg[three - 1] = pc->reg[one - 1] ^ pc->reg[two - 1];
		if ( pc->reg[three - 1] == 0)
			pc->carry = 1;
		else
			pc->carry = 0;
	}
	pc->curr_position = pc->curr_position + 5;
}

void ft_xor_dir_reg(t_pc *pc, t_union *un)
{
	unsigned int one;
	unsigned int two;
	unsigned int three;

	one = (unsigned int)ft_get_int(un, ft_check_position(pc->curr_position + 2), 4);
	two = un->map[ft_check_position(pc->curr_position + 6)].value ;
	three = un->map[ft_check_position(pc->curr_position + 7)].value ;
	if (two <= 16 && two > 0 && three <= 16 && three > 0)
	{
		pc->reg[three - 1] = one ^ pc->reg[two - 1];
		if ( pc->reg[three - 1] == 0)
			pc->carry = 1;
		else
			pc->carry = 0;
	}
	pc->curr_position = pc->curr_position + 8;
}
void ft_xor_ind_reg(t_pc *pc, t_union *un)
{
	unsigned int one;
	unsigned int two;
	unsigned int three;

	one = (unsigned int)ft_get_int(un, ft_check_position(pc->curr_position + ((short)ft_get_int(un, ft_check_position(pc->curr_position + 2), 2))), 4);
	two = un->map[ft_check_position(pc->curr_position + 4)].value ;
	three = un->map[ft_check_position(pc->curr_position + 5)].value ;
	if (two <= 16 && two > 0 && three <= 16 && three > 0)
	{
		pc->reg[three - 1] = one ^ pc->reg[two - 1];
		if ( pc->reg[three - 1] == 0)
			pc->carry = 1;
		else
			pc->carry = 0;
	}
	pc->curr_position = pc->curr_position + 6;
}

void ft_xor_ind_ind(t_pc *pc, t_union *un)
{
	unsigned int one;
	unsigned int two;
	unsigned int three;

	one = (unsigned int)ft_get_int(un, ft_check_position(pc->curr_position + ((short)ft_get_int(un, ft_check_position(pc->curr_position + 2), 2))), 4);
	two = (unsigned int)ft_get_int(un, ft_check_position(pc->curr_position + ((short)ft_get_int(un, ft_check_position(pc->curr_position + 4), 2))), 4);
	three = un->map[ft_check_position(pc->curr_position + 6)].value ;
	if (three <= 16 && three > 0)
	{
		pc->reg[three - 1] = one ^ two;
		if ( pc->reg[three - 1] == 0)
			pc->carry = 1;
		else
			pc->carry = 0;
	}
	pc->curr_position = pc->curr_position + 7;
}

void ft_xor(t_pc *pc, t_union *un)
{
	if (AND_OR(un->map[ft_check_position(pc->curr_position + 1)].value) && AND_XOR(un->map[ft_check_position(pc->curr_position + 1)].value))
	{
		pc->curr_position += 2;
		return ;
	}
	ft_check_codage(un->map[ft_check_position(pc->curr_position + 1)].value, un);
	if (un->arg[0] == REG_CODE && un->arg[1] == REG_CODE)
		ft_xor_reg_reg(pc, un);
	if (un->arg[0] == DIR_CODE && un->arg[1] == REG_CODE)
		ft_xor_dir_reg(pc, un);
	if (un->arg[0] == IND_CODE && un->arg[1] == REG_CODE)
		ft_xor_ind_reg(pc, un);
	if (un->arg[0] == REG_CODE && un->arg[1] == DIR_CODE)
		ft_xor_reg_dir(pc, un);
	if (un->arg[0] == DIR_CODE && un->arg[1] == DIR_CODE)
		ft_xor_dir_dir(pc, un);
	if (un->arg[0] == IND_CODE && un->arg[1] == DIR_CODE)
		ft_xor_ind_dir(pc, un);
	if (un->arg[0] == REG_CODE && un->arg[1] == IND_CODE)
		ft_xor_reg_ind(pc, un);
	if (un->arg[0] == DIR_CODE && un->arg[1] == IND_CODE)
		ft_xor_dir_ind(pc, un);
	if (un->arg[0] == IND_CODE && un->arg[1] == IND_CODE)
		ft_xor_ind_ind(pc, un);
}