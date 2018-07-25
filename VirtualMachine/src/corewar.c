

#include "../inc/vm.h"


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
	if (pc->curr_position >= MEM_SIZE)
		pc->curr_position %= MEM_SIZE;
	else if (pc->curr_position < 0)
		pc->curr_position += MEM_SIZE;
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