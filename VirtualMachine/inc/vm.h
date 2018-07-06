/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 12:25:51 by vmiachko          #+#    #+#             */
/*   Updated: 2018/07/05 12:26:36 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	VM_H

# define VM_H

# include "../../libft/libft.h"
# include "op.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

typedef struct		s_bot
{
	char 			*filename;
	char 			name[PROG_NAME_LENGTH + 1];
	char 			comment[COMMENT_LENGTH + 1];
	int 			size;
	unsigned char	code[CHAMP_MAX_SIZE + 1]; //не забыть занулить массивы
	int 			id;
	struct s_bot	*next;
}					t_bot;

typedef	struct		s_pc
{
	int 			curr_position;
	int 			carry;
	int 			creator_id;
	int 			reg[16];
	int 			alive;
	char 			*curr_command;
	int 			number_cycles;
	struct s_pc		*next;
}					t_pc;

typedef struct		s_counter
{
	int i;
	int c;
	int fd;
}					t_counter;

typedef struct		s_union
{
	t_bot			*bot;
	t_pc			*pc;
	unsigned char	*map;
	int 			dump;
	int 			argc;
	t_counter		count;
}					t_union;

t_bot				*bot_push_back(t_bot *head, char *filename, int id);
int 		parse_bot(t_union *un);

#endif
