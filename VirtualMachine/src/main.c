/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 12:23:04 by vmiachko          #+#    #+#             */
/*   Updated: 2018/07/05 12:27:01 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/vm.h"
#include "../inc/parsing.h"


void			without_visual(t_union *un)
{
	while(un->cycle_to_die > 0 && un->pc)
	{
		corewar(un);
	}
}

int				main(int argc, char **argv)
{
	t_union		un;

	un.visual = 0;
	un.checks = 0;
	un.cycle_to_die = CYCLE_TO_DIE;
	un.bots_number = 0;
	un.procces_number = 0;
	if (parsing(argc, argv, &un))
	{
		ft_printf("OK\n");
		un.map = (t_map *)malloc(MEM_SIZE * sizeof(t_map) + 1);
		initialize_map(&un);
		move_code_to_map(&un, 2);
		if (un.visual)
			display_map(&un);
		else
			without_visual(&un);
	}
	return (0);
}
