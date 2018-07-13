

#include "../inc/vm.h"

void 		move_code_to_map(t_union *un, int color)
{
	int i;
	int j;
	int move;
	t_bot	*bot;

	j = 0;
	bot = un->bot;
	move = 0;
	while (bot)
	{
		i = 0;
		while (i < bot->code_length)
		{
			un->map[j + move].value = bot->code[i];
			un->map[j + move].color = color;
			++i;
			++j;
		}
		move += 682 - bot->code_length + 100;
		++color;
		bot = bot->next;
	}
}

void		display_map(t_union *un)
{
	int key;
	int i;
	int k;



	key = 1;
	initscr();
	raw();
	nodelay(stdscr, TRUE);
	noecho();
	curs_set(0);
	move_code_to_map(un, 2);
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
	while (key)
	{

		i = 0;
		k = 0;

			/* Start color 			*/


		while (i < MEM_SIZE)
		{

			attron(COLOR_PAIR(un->map[i].color));
			printw("%02x ", un->map[i].value);
			attroff(COLOR_PAIR(un->map[i].color));
			++k;
			if (k == 64)
			{
				printw("\n");
				k = 0;
			}
			++i;
		}

		refresh();

		key = getch();
		if (key == 27)
			break ;
		sleep(1);
		clear();
}

	endwin();
	curs_set(1);
}