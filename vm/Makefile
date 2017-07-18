# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/13 16:44:11 by tferrari          #+#    #+#              #
#    Updated: 2017/07/18 20:41:27 by dbischof         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: libft

NAME = corewar

SRC_DIR = src

SRC_FILE =	add.c aff.c and_ft.c battle.c debug.c fork.c getset_memory.c \
			intchar.c ld.c ldi.c lfork.c live.c lld.c lldi.c loadbots.c \
			loadfunc.c loadmemory.c main.c open.c or_ft.c print_memory.c \
			process.c st.c sti.c sub.c xor_ft.c zjmp.c check_ocp.c stun.c \
			view.c colorview.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILE))

OBJS_DIR = obj

OBJS = $(addprefix $(OBJS_DIR)/, $(SRC_FILE:.c=.o))

INC = -I../libft/includes -Iinclude

LFT = -L./../libft -lft

all : libft $(NAME)

$(NAME): $(OBJS)
	@gcc -Wall -Werror -Wextra $(LFT) -lncurses -o $(NAME) $(OBJS)
	@echo "\033[32mexecutable corewar(a.out) créé\033[0m"

libft:
	make -C ../libft/

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@gcc -Wall -Werror -Wextra $(INC) -o $@ -c $<
	@echo "Fichier" $< "recompilé."

clean:
	@rm -rf $(OBJS_DIR)
	@make -C ../Libft clean
	@echo "\033[31mFichier objet de corewar supprimé\033[0m"

fclean: clean
	@rm -f $(NAME)
	@rm -f ../libft/libft.a
	@echo "\033[31mLibft.a supprimé\033[0m"
	@echo "\033[31mcorewar supprimé\033[0m"

re: fclean all
