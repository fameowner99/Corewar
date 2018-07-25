/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 13:23:18 by vmiachko          #+#    #+#             */
/*   Updated: 2018/07/25 13:23:19 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/vm.h"

void		check_if_pc_alive(t_union *un)
{
	t_pc	*pc;

	pc = un->pc;
	while (pc)
	{
		if (!pc->alive)
			un->pc = delete_pc(un->pc, pc, un);
		else
			pc->alive = 0;
		pc = pc->next;
	}
}

int		decrease_cycle_to_die(t_union *un)
{
	t_bot	*bot;

	bot = un->bot;
	while (bot)
	{
		if (bot->num_live > 21)
			return (1);
		bot = bot->next;
	}
	return (0);
}

void		clear_num_live(t_union *un)
{
	t_bot	*bot;

	bot = un->bot;
	while (bot)
	{
		bot->num_live = 0;
		bot = bot->next;
	}
}
