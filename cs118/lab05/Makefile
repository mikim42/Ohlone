# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/08 08:21:29 by mikim             #+#    #+#              #
#    Updated: 2018/03/15 14:19:17 by mikim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#
#	Mingyun Kim
#	https://www.github.com/mikim42
#

SRC = mkimfuns.s

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

NAME = mkimfuns

.PHONY: all clean fclean re
.SUFFIXES: .s .o

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.s
	@mkdir -p $(OBJDIR)
	@$(ASM) $(GFLAG) $(HEADER) $< -o $@

$(NAME): $(OBJS)
	@$(LINKER) $(OBJS) $(LIB) -o $@
	@echo "[$(@) Created]"

clean:
	@/bin/rm -rf $(OBJDIR)
	@echo "[Directory Cleaned]"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "[$(NAME) - Deleted]"

re: fclean all
