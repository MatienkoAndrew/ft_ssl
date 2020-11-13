/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:49:33 by student           #+#    #+#             */
/*   Updated: 2020/11/03 18:49:35 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

typedef struct s_mem
{
	unsigned char 	*data;
	unsigned int 	h[8];
	int 			len;
}					t_mem;

typedef struct s_arg
{
	char 		*str;
	int 		is_string;
	struct s_arg	*next;
}				t_arg;

typedef struct s_opt
{
	int 		hash;
	struct s_arg	*arg;
	int 		p;
	int 		q;
	int 		r;
	int			s;
}				t_opt;


int 	print_usage(char *str);
t_opt	*check_opt(t_opt *opt, char **argv);
void 	write_file_error(char *file, t_opt *opt);
void 	hash_md5(t_mem *mem);
void 	ft_free_mem(t_mem *mem);

#endif