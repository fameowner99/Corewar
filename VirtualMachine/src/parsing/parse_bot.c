/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 12:43:17 by vmiachko          #+#    #+#             */
/*   Updated: 2018/07/06 12:43:18 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vm.h"
#include "../../inc/parsing.h"

int 		fill_bot(t_union *un)
{
	t_bot	*tmp;
	int 	fd;
	unsigned char 	magic_header[8];
	int 	r;

	tmp = un->bot;
	while (tmp)
	{
		fd = open(tmp->filename, O_RDONLY);
		if (read(fd, &magic_header, 0) < 0)
		{
			ft_printf(RED"Error: File %s is too small to be a champion\n"RESET, tmp->filename);
			return (0);
		}
		//test
		r = (int)read(fd, &magic_header, 4);
		magic_header[r] = '\0';
		unsigned int sum = 0;
		sum += magic_header[3] +
			   (magic_header[2] << 8) +
			   (magic_header[1] << 16) +
			   (magic_header[0] << 24);
		if (sum != COREWAR_EXEC_MAGIC)
			return (0);
		r = (int)read(fd, &tmp->name, 128);
		if (r < 128)
			return (0);
		r = (int)read(fd, &magic_header, 4);
		if (r < 4)
			return (0);
		sum = 0;
		sum += magic_header[3] +
			   (magic_header[2] << 8) +
			   (magic_header[1] << 16) +
			   (magic_header[0] << 24);
		if (sum != 0)
			return (0);

		r = (int)read(fd, &magic_header, 4);
		if (r < 4)
			return (0);
		sum = 0;


		sum += magic_header[3] +
			   (magic_header[2] << 8) +
			   (magic_header[1] << 16) +
			   (magic_header[0] << 24);
		tmp->size = sum;


		r = (int)read(fd, &tmp->comment, 254);
		if (r < 254)
			return (0);

		r = (int)read(fd, &magic_header, 4);
		sum = 0;
		sum += magic_header[3] +
			   (magic_header[2] << 8) +
			   (magic_header[1] << 16) +
			   (magic_header[0] << 24);
		if (sum != 0)
			return (0);
		int rr;
		rr = 0;
		while((r = (int)read(fd, &tmp->code, 100)) > 0)
		{
			rr += r;
		}



			//tmp->code[r] = '\0';

		//test
		for(int i=0;i < tmp->size;i++)
			ft_printf("%02x ",tmp->code[i]);
		tmp = tmp->next;
	}
	return (1);
}

int 		parse_bot(t_union *un)
{
	int		r;

	while (!(r = set_bot_id(un)))
		set_bot_id(un);
	if (r == -1)
		return (-1);
	else if (!fill_bot(un))
		return (0);
	return (1);
}