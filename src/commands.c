/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:54:35 by student           #+#    #+#             */
/*   Updated: 2020/11/03 18:54:37 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_ssl.h"

void 	ft_free_mem(t_mem *mem)
{
	free(mem->data);
	mem->data = NULL;
	free(mem);
	mem = NULL;
}


int 	print_usage(char *str)
{
	ft_printf("usage: %s [hash] [command options] [command arguments]\n",
		   str);
	return (-1);
}

