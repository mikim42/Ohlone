# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Mingyun Kim <mikim@student.42.us.org>      +#+  +:+       +#+         #
#    GitHub:  https://github.com/mikim42          +#+#+#+#+#+   +#+            #
#    Created: 2018/02/15 10:09:55 by Mingyun K         #+#    #+#              #
#    Updated: 2018/02/20 11:11:07 by Mingyun K        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = mkimarray.s

OBJ = $(SRC:.s=.o)

SRCDIR = srcs
OBJDIR = objs

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(OBJ))

CATCH = 
HEADER =
LIB = 

CC = gcc
CXX = g++ -std=c++11
ASM = as
LINKER = ld

GFLAG = -g
CFLAG = -c
WFLAG = -Wall -Wextra -Werror
UNIT = -D UNIT_TEST

NAME = mkimarray

.PHONY: all clean fclean re
.SUFFIXES: .s .o

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.s
	@mkdir -p $(OBJDIR)
	@$(ASM) $(GFLAG) $(HEADER) $< -o $@

$(NAME): $(OBJS)
	@$(LINKER) $(OBJS) $(LIB) -o $@
	@echo "[$(NAME) Created]"

clean:
	@/bin/rm -rf $(OBJDIR)
	@echo "[Directory Cleaned]"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "[$(NAME) - Deleted]"

re: fclean all
