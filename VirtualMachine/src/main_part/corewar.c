/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 17:03:35 by vmiachko          #+#    #+#             */
/*   Updated: 2018/07/27 17:06:12 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vm.h"
#include "../../inc/commands.h"

void			dump(t_union *un)
{
	int			i;
	int			k;
	int			h;

	i = 0;
	k = 0;
	h = 0;
	ft_printf("%#.4x : ", h);
	while (i < MEM_SIZE)
	{
		ft_printf("%02x ", un->map[i].value);
		++i;
		++k;
		if (k == 64)
		{
			ft_printf("\n");
			h += 64;
			if (i < MEM_SIZE)
				ft_printf("%#.4x : ", h);
			k = 0;
		}
	}
}

void			without_visual(t_union *un)
{
	print_players_info(un);
	while (un->cycle_to_die > 0 && un->pc)
	{
		corewar(un);
		if (un->cycle == un->dump)
		{
			dump(un);
			break ;
		}
	}
	if (!un->dump)
		print_winner(un);
	ft_printf("%d\n", un->cycle);
	ft_printf("%d\n", un->bot->last_live);
}

void			execute_command(t_pc *pc, t_union *un)
{
	if (un->map[pc->curr_position].value >= 1 &&
		un->map[pc->curr_position].value <= 16 &&
			pc->number_cycles_to_wait == -1)
	{
		choose_number_cycles_to_wait(pc, un);
		--pc->number_cycles_to_wait;
	}
	else if (pc->number_cycles_to_wait == 1)
	{
		choose_commands(pc, un);
		pc->number_cycles_to_wait = -1;
	}
	else if (pc->number_cycles_to_wait > 0)
		--pc->number_cycles_to_wait;
	else
		pc->curr_position++;
	if (pc->curr_position >= MEM_SIZE)
		pc->curr_position %= MEM_SIZE;
	else if (pc->curr_position < 0)
		pc->curr_position += MEM_SIZE;
}

void			move_pc(t_union *un)
{
	t_pc		*pc;

	pc = un->pc;
	while (pc)
	{
		execute_command(pc, un);
		pc = pc->next;
	}
}

void			corewar(t_union *un)
{
	if (un->k == un->cycle_to_die && un->cycle != 0)
	{
		check_if_pc_alive(un);
		if (decrease_cycle_to_die(un))
		{
			un->cycle_to_die -= CYCLE_DELTA;
			un->checks = 0;
		}
		else
			++un->checks;
		if (un->checks == MAX_CHECKS)
		{
			un->checks = 0;
			un->cycle_to_die -= CYCLE_DELTA;
		}
		clear_num_live(un);
		un->k = 0;
	}
	++un->cycle;
	++un->k;
	move_pc(un);
}