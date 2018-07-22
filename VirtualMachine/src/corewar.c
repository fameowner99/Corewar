

#include "../inc/vm.h"

void		choose_command(t_union *un, t_pc *pc)
{
	/*if (pc->curr_command == 1)
		//;
	else if (pc->curr_command == 2)
		//;
	else if (pc->curr_command == 3)
		//;
	else if (pc->curr_command == 4)
		//;
	else if (pc->curr_command == 5)
		//;
	else if (pc->curr_command == 6)
		//;
	else if (pc->curr_command == 7)
		//;
	else if (pc->curr_command == 8)
		//;
	else if (pc->curr_command == 9)
		//;
	else if (pc->curr_command == 10)
		//;
	else if (pc->curr_command == 11)
		//;
	else if (pc->curr_command == 12)
		//;
	else if (pc->curr_command == 13)
		//;
	else if (pc->curr_command == 14)
		//;
	else if (pc->curr_command == 15)
		//;
	 */

}

void		execute_command(t_union *un)
{
	t_pc	*pc;

	pc = un->pc;
	while (pc)
	{
		if (pc->number_cycles_to_wait > 0)
			--pc->number_cycles_to_wait;
		else
			choose_command(un, pc);
		pc = pc->next;
	}
}

void	corewar(t_union *un)
{

}