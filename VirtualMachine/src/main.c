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
	while(un->cycle_to_die > 0 && un->pc)
	{
		corewar(un);
		if (un->cycle == un->dump)
		{
			dump(un);
			break ;
		}
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
		pc_sort_ascending(&un);
		if (un.visual)
			display_map(&un);
		else
			without_visual(&un);
		bot_clear_list(un.bot);
		pc_clear_list(un.pc);
		free(un.map);
	}
	return (0);
}
