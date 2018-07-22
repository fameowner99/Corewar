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

void			initialize_map(t_union *un)
{
	t_map		*tmp;
	int 		i;

	tmp = un->map;
	i = 0;
	while (i < MEM_SIZE)
	{
		tmp[i].color = 1;
		tmp[i].value = '\0';
		tmp[i].cursor = 0;
		++i;
	}
}

int				main(int argc, char **argv)
{
	t_union		un;

	un.visual = 0;
	if (parsing(argc, argv, &un))
	{
		ft_printf("OK\n");
		un.map = (t_map *)malloc(MEM_SIZE * sizeof(t_map) + 1);
		initialize_map(&un);
		display_map(&un);
	}
	return (0);
}
