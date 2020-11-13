/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 20:38:57 by student           #+#    #+#             */
/*   Updated: 2020/11/03 20:39:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_ssl.h"

void 	write_file_error(char *file, t_opt *opt)
{
	const char *hash_code[3] = {"md5", "sha256", NULL};
	ft_printf("ft_ssl %s: %s: No such file or directory\n", hash_code[opt->hash], file);
}

