# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/13 16:44:11 by tferrari          #+#    #+#              #
#    Updated: 2017/08/01 16:06:52 by tferrari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM = r_asm

VM = vm

all :
	@make -C $(VM)
	@make -C $(ASM)
	@cp $(VM)/corewar ./
	@cp $(ASM)/asm ./

clean:
	@make -C $(VM) clean
	@make -C $(ASM) clean

fclean: clean
	@make -C $(VM) fclean
	@make -C $(ASM) fclean
	@rm -f corewar
	@rm -f asm

re: fclean all
