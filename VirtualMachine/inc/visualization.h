/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualization.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 14:17:38 by vmiachko          #+#    #+#             */
/*   Updated: 2018/07/27 14:18:33 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZATION_H

# define VISUALIZATION_H

# define XMAX 200
# define YMAX 200

typedef struct	s_vis
{
	int key;
	int i;
	int k;
	int x;
	int y;
	WINDOW *win;
}				t_vis;
#endif
