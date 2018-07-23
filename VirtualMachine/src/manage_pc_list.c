/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_pc_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 10:39:18 by vmiachko          #+#    #+#             */
/*   Updated: 2018/07/06 10:39:20 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/vm.h"



static t_pc *clear_arr(t_pc *pc)
{
	int i;

	i = 1;
	while (i < 16)
	{
		pc->reg[i] = 0;
		++i;
	}
	return (pc);
}

t_pc	*pc_new(int pos, int bot_num)
{
	t_pc	*res;
	int 	i;

	i = 0;
	if (!(res = (t_pc *)malloc(sizeof(t_pc))))
		return (NULL);
	res->curr_position = pos;
	res->carry = 0;
	res->creator_id = bot_num;
	res->reg[0] = res->creator_id;
	i = 1;
	while (i < 16)
	{
		res->reg[i] = 0;
		++i;
	}
	res->alive = 0;
	res->curr_command = 0;
	res->number_cycles_to_wait = 0;
	res->next = NULL;
	res->prev = NULL;
	clear_arr(res);
	return (res);
}

t_pc    *pc_copy(t_pc *prev, int position)
{
	t_pc    *res;

	if (!(res = (t_pc *)malloc(sizeof(t_pc))))
		return (NULL);
	res->curr_position = position;
	res->carry = 0; //перевірити
	res->creator_id = prev->creator_id;
	res->reg[0] = prev->reg[0];
	res->alive = 0;
	res->curr_command = 0;
	res->number_cycles_to_wait = -1;
	res->next = NULL;
	res->prev = NULL;
	return (res);
}


t_pc		*pc_push_front(t_pc *head, t_pc *new)
{
	new->next = head;
	if (head != NULL)
		head->prev = new;
	return (new);
}

/*t_pc		*pc_push_back(t_pc *head, int pos, int bot_num)
{
	t_pc	*tmp;
	t_pc	*new;
	t_pc	*prev;

	prev = NULL;
	tmp = head;
	if (!tmp)
		return (pc_new(pos, bot_num));
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	new = pc_new(pos, bot_num);
	tmp->next = new;
	return (head);
}*/

void		delete_pc(t_pc *head, t_pc *to_del)
{
	t_pc	*tmp;
	t_pc	*prev;
	t_pc	*next;

	prev = NULL;
	tmp = head;
	while (tmp)
	{
		next = tmp->next;
		if (tmp == to_del)
		{
			free(tmp);
			if (prev)
				prev->next = next;
			if (next)
				next->prev = prev;
			return ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}