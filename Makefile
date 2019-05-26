# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jochang <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/18 16:19:50 by jochang           #+#    #+#              #
#    Updated: 2019/05/19 22:06:45 by jochang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf_unit_test

SRC =	all_pass \
		main_header \
		main \
		capture \

TESTS = test_percent \
		test_d \
		test_i \
		test_u \
		test_f \
		test_uf \
		test_e \
		test_ue \
		test_g \
		test_ug \
		test_x \
		test_ux \
		test_o \
		test_s \
		test_c \
		test_p \
		test_a \
		test_ua \
		test_n \
		test_minus \
		test_plus \
		test_space \
		test_zero \
		test_sharp \
		test_width \
		test_precision \
		test_length \
		test_mix \
		test_star \

INC =	-I inc \
		-I ft_printf/ \
		-I libunit/inc \

LIB =	-L libunit -lunit \
		-L ft_printf -lftprintf \

VPATH = src:tests
OBJ_DIR = obj

OBJ  = $(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(SRC)))
OBJ += $(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(TESTS)))

DEP = $(OBJ:%.o=%.d)

CC = gcc
CFLAGS = -Wall -Wextra -Werror $(INC)
MAKEOPTS = -j4

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@printf "\033[32mmaking test objects...\033[0m\n"
	@mkdir -p $(OBJ_DIR)

-include $(DEP)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@printf "\e[32mCompiling: \e[0m%s\n" $<
	@$(CC) $(CFLAGS) -MMD -c $< -o $@

$(NAME): $(OBJ)
	@make -C ft_printf
	@make -C libunit
	@printf "\e[32mCompiling: %s...\e[0m\n" $(NAME)
	@$(CC) $^ -o $@ $(LIB)

clean:
	@make -C ft_printf clean
	@make -C libunit clean
	@printf "\e[33mremoving test objects...\e[0m\n"
	@rm -f $(OBJ)

fclean: clean
	@make -C ft_printf fclean
	@make -C libunit fclean
	@printf "\e[33mremoving test executable...\e[0m\n"
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR)

re: fclean all

test: all
	@./$(NAME)

log: all
	@./$(NAME) > log.txt

.PHONY: all clean fclean re test log
