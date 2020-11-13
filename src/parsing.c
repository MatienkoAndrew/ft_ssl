/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:53:20 by student           #+#    #+#             */
/*   Updated: 2020/11/03 18:53:22 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_ssl.h"

t_opt	*add_arg(t_opt *opt, char *str)
{
	t_arg *arg;
	t_arg *tmp;

	arg = (t_arg *)malloc(sizeof(t_arg));
	arg->str = ft_strdup(str);
	arg->is_string = 0;
	if (opt->s)
	{
		arg->is_string = 1;
		opt->s = 0;
	}
	arg->next = NULL;
	if (opt->arg == NULL)
		opt->arg = NULL;
	else
	{
		tmp = opt->arg;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = arg;
	}
	return (opt);
}

t_opt	*check_options(t_opt *opt, char *str)
{
	int 	i;
	int 	bool;

	i = -1;
	bool = 0;
	while (str[++i])
	{
		if (str[0] == '-' && opt->arg == NULL)
			bool = 1;
		else
			return (add_arg(opt, str));
		if (bool == 1)
		{
			(str[i] == 'p') ? (opt->p = 1) : 0;
			(str[i] == 'q') ? (opt->q = 1) : 0;
			(str[i] == 'r') ? (opt->r = 1) : 0;
			(str[i] == 's') ? (opt->s = 1) : 0;
		}
	}
	return (opt);
}

int 	get_hash_index(char *hash)
{
	int 	i;
	const char* hash_code[3]= {"md5", "sha256", NULL};

	i = -1;
	while (hash_code[++i])
		if (!ft_strcmp(hash_code[i], hash))
			return (i);
	return (-1);
}

t_opt	*check_opt(t_opt *opt, char **argv)
{
	int 	i;

	i = 1;
	opt = (t_opt *)malloc(sizeof(t_opt));
	opt->hash = get_hash_index(argv[1]);
	opt->p = 0;
	opt->q = 0;
	opt->r = 0;
	opt->s = 0;
	opt->arg = NULL;
	if (opt->hash == -1)
	{
		ft_printf("ft_ssl: invalid hash algorithm\nMessage Digest Commands:\nmd5\nsha256");
		exit(-1);
	}
	while (argv[++i])
		opt = check_options(opt, argv[i]);
	return (opt);
}


