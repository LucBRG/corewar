/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <mdeglain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 14:01:20 by mdeglain          #+#    #+#             */
/*   Updated: 2017/05/30 12:22:32 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../../libft/includes/libft.h"

typedef	struct		s_arg
{
	char			*name;
	unsigned char	op_code;
	unsigned char	special;
	unsigned char	ocp;
	unsigned char	n_args;
	unsigned char	octet;
	unsigned char	tot_octets;
	struct s_arg	*ref;
	struct s_arg	*next;
	struct s_arg	*prec;
}					t_arg;

typedef	struct		s_asm
{
	int				header_len;
	unsigned int	nb_line;
	char			**str;
	unsigned int	i;
	unsigned int	j;
	struct s_arg	*args;
	unsigned char	oct_line;

}					t_asm;

typedef	struct		s_op
{
	unsigned char	name[6];
	unsigned char	n_args;
	unsigned char	args[3];
	unsigned char	op_code;
	unsigned int	n_cycle;
	unsigned char	desc[256];
	unsigned char	has_ocp;
	unsigned char	has_carry;
}					t_op;




int					cor_strchr(const char *s, int c);
int					parsing_asm(t_asm *env, t_file *file);
void				show_err(int id, int line);
t_arg				*arg_create(void);
void				arg_delete(t_arg **head);
void				arg_add(t_arg **head, t_arg *arg);
void				find_par(t_asm *env, unsigned char n_args, t_arg *ref_inst);
int					find_ins(t_asm *env, t_arg **ref_inst);
void				find_lab(t_asm *env);
void				copy_header(char *dst, t_asm *env, int i);
void				parse_instruction(t_asm *env);
int					is_in(const char *str, char letter);
void				jump_space(t_asm *env);
void				verif_name(t_asm *env, t_arg *arg);
int					cor_strlen(char *str);
int					verif_exist(t_arg *lst, char *str);
void				label_exist(t_asm *env);
void				good_order(t_asm *env);




extern t_op	g_op_tab[17];

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"


#endif
