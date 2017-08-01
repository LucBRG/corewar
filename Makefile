# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/13 16:44:11 by tferrari          #+#    #+#              #
#    Updated: 2017/08/01 17:18:26 by dbischof         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: libft

ASM = r_asm

VM = vm

all : libft
	@make -C $(VM)
	@make -C $(ASM)

libft:
	@make -C libft
	@printf "$(GREEN)[/!\ libft READY /!\]$(NO_C)"

clean:
	@make -C libft clean
	@make -C $(VM) clean
	@make -C $(ASM) clean

fclean: clean
	@make -C libft fclean
	@make -C $(VM) fclean
	@make -C $(ASM) fclean

re: fclean all

norme:
	@make norme -C libft
	@make norme -C $(ASM)
	@make norme -C $(VM)
