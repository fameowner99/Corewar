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

int				main(int argc, char **argv)
{
	t_union		un;

	if (parsing(argc, argv, &un))
		ft_printf("OK\n");
	return (0);
}
