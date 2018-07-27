/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_border.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 19:56:45 by vmiachko          #+#    #+#             */
/*   Updated: 2018/07/27 21:29:09 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vm.h"
#include "../../inc/visualization.h"

void		print_border(WINDOW *win)
{
	int		i;

	i = 1;
	wattron(stdscr, COLOR_PAIR(30));
	wattron(win, COLOR_PAIR(30));
	while (i < 67)
	{
		mvwprintw(win, i, 0, "*");
		mvwprintw(win, i, 196, "*");
		mvwprintw(stdscr, i, 240, "*");
		++i;
	}
	i = 0;
	while (i < 241)
	{
		mvwprintw(i < 197 ? win : stdscr, 0, i, "*");
		mvwprintw(i < 197 ? win : stdscr, 67, i, "*");
		++i;
	}
	wattroff(win, COLOR_PAIR(30));
	wattroff(stdscr, COLOR_PAIR(30));
}
