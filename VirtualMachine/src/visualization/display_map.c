/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 14:10:10 by vmiachko          #+#    #+#             */
/*   Updated: 2018/07/27 15:07:25 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vm.h"
#include "../../inc/visualization.h"

WINDOW		*init_colors(int *key)
{
	*key = 1;
	initscr();
	raw();
	nodelay(stdscr, TRUE);
	noecho();
	curs_set(0);
	start_color();
	init_pair(9, COLOR_BLACK, COLOR_WHITE);
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(11, COLOR_WHITE, COLOR_CYAN);
	init_pair(19, COLOR_GREEN, COLOR_GREEN);
	init_pair(12, COLOR_WHITE, COLOR_RED);
	init_pair(13, COLOR_WHITE, COLOR_BLUE);
	init_pair(14, COLOR_WHITE, COLOR_MAGENTA);
	init_pair(15, COLOR_WHITE, COLOR_YELLOW);
	return (newwin(YMAX, XMAX, 1, 1));
}

void		print_to_back_window(t_union *un)
{
	mvprintw(5, XMAX + 5, "Cycle: %d\n", un->cycle);
	mvprintw(8, XMAX + 5, "Cycle_to_die: %d\n", un->cycle_to_die);
	mvprintw(12, XMAX + 5, "Number live: %d\n", un->bot->num_live);
	mvprintw(15, XMAX + 5, "Last live: %d\n", un->bot->last_live);
	mvprintw(18, XMAX + 5, "Number proccess: %d\n", un->procces_number);
}

void		print_map(t_vis *vis, t_union *un)
{
	while (vis->i < MEM_SIZE)
	{
		wattron(vis->win, COLOR_PAIR(un->map[vis->i].color));
		if (un->map[vis->i].cursor)
			wattron(vis->win, COLOR_PAIR(un->map[vis->i].color + 10));
		mvwprintw(vis->win, vis->y, vis->x, "%02x", un->map[vis->i].value);
		vis->x += 3;
		wattroff(vis->win, COLOR_PAIR(un->map[vis->i].color));
		mvwprintw(vis->win, vis->y, vis->x, " ");
		if (un->map[vis->i].cursor)
			wattroff(vis->win, COLOR_PAIR(un->map[vis->i].color + 10));
		++vis->k;
		if (vis->k == 64)
		{
			vis->y++;
			vis->x = 0;
			vis->k = 0;
		}
		++vis->i;
	}
	wrefresh(vis->win);
	refresh();
}

int			pause_exit(t_vis vis, t_union *un)
{
	if (vis.key == 32)
	{
		while (1)
		{
			vis.key = getch();
			if (vis.key == 32)
				break ;
			if (vis.key == 27)
				return (27);
		}
	}
	if (un->cycle_to_die <= 0 || !un->pc)
	{
		while (1)
		{
			vis.key = getch();
			if (vis.key == 27)
				return (27);
		}
	}
	if (vis.key == 27)
		return (27);
	return (1);
}

void		display_map(t_union *un)
{
	t_vis	vis;

	vis.win = init_colors(&vis.key);
	while (vis.key)
	{
		vis.i = 0;
		vis.k = 0;
		vis.x = 0;
		vis.y = 0;
		print_to_back_window(un);
		print_map(&vis, un);
		vis.key = getch();
		vis.key = pause_exit(vis, un);
		if (vis.key == 27)
			break ;
		corewar(un);
		update_pc(un);
	}
	endwin();
	curs_set(1);
}
