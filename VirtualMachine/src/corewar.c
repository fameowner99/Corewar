

#include "../inc/vm.h"


void			dump(t_union *un)
{
	int 		i;
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
	while(un->cycle_to_die > 0 && un->pc)
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

}

void		execute_command(t_pc *pc, t_union *un)
{


		if (un->map[pc->curr_position].value >= 1 && un->map[pc->curr_position].value <= 16 && pc->number_cycles_to_wait == -1)
		{
			choose_number_cycles_to_wait(pc, un);

		}
		else if (pc->number_cycles_to_wait == 0)
		{
			choose_commands(pc, un);
			pc->number_cycles_to_wait = -1;
		}
		else if (pc->number_cycles_to_wait > 0)
			--pc->number_cycles_to_wait;
		else
			pc->curr_position++;

}

void		move_pc(t_union *un)
{
	t_pc	*pc;

	pc = un->pc;
	while (pc)
	{
		execute_command(pc, un);
		pc = pc->next;
	}
}

void	corewar(t_union *un)
{
	++un->cycle;
	move_pc(un);
	if (un->cycle % un->cycle_to_die == 0)
	{
		check_if_pc_alive(un);
		if (decrease_cycle_to_die(un))
			un->cycle_to_die -= CYCLE_DELTA;
		else
			++un->checks;
		if (un->checks == MAX_CHECKS)
		{
			un->checks = 0;
			un->cycle_to_die -= CYCLE_DELTA;
		}
		clear_num_live(un);
	}
}