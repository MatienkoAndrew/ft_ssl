/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:29:19 by student           #+#    #+#             */
/*   Updated: 2020/11/03 18:29:22 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_ssl.h"

t_mem	*padding(t_mem *mem)
{
	t_mem	*message;
	size_t	newlen;
	size_t	len;
	uint32_t	bitlen;

	message = (t_mem *)malloc(sizeof(t_mem));
	message->h[0] = 0x67452301;
	message->h[1] = 0xefcdab89;
	message->h[2] = 0x98badcfe;
	message->h[3] = 0x10325476;
	len = mem->len;
	bitlen = len * 8;
	newlen = len + 1;
	while (newlen % 64 != 56)
		newlen++;
	message->data = (unsigned char *)ft_strnew(newlen + 64);
	message->len = newlen;
	ft_memcpy(message->data, mem->data, mem->len);
	message->data[len] = (char)128;
	while (++len <= newlen)
		message->data[len] = 0;
	ft_memcpy(message->data + newlen, &bitlen, 4);
	ft_free_mem(mem);
	return (message);
}

void 	hash(t_opt *opt, t_mem *message, t_arg *arg)
{
	message = padding(message);
	hash_md5(message);

}

void 	handle_string(t_opt *opt, t_arg *arg)
{
	t_mem	*message;

	message = (t_mem *)malloc(sizeof(t_mem));
	message->data = (unsigned char *)ft_strdup(arg->str);
	arg->is_string = 1;
	message->len = ft_strlen((char *)message->data);
	hash(opt, message, arg);
}

void 	handle_args(t_opt *opt)
{
	t_arg	*arg
	t_mem	*message;
	int 	fd;

	message = NULL;
	arg = opt->arg;
	while (arg)
	{
		if (!arg->is_string && (ft = open(arg->str, O_RDONLY)) != -1)
		{
			message = read_fd(fd);
			hash(opt, message, arg);
		}
		else
		{
			if (arg->is_string)
				handle_string(opt, arg);
			else
				(!opt->q) ? (write_file_error(arg->str, opt)) : 0;
		}
		arg = arg->next;
	}
}

int		main(int argc, char **argv)
{
	t_opt	*opt;

	opt = NULL;
	if (argc < 2)
		return (print_usage(argv[0]));
	opt = check_opt(opt, argv);
	if (opt->p || !opt->arg)
		handle_stdin(opt);
	if (argc >= 3)
		handle_args(opt);
	return (0);
}
