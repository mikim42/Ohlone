# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Mingyun Kim <mikim@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/06 09:36:55 by Mingyun K         #+#    #+#              #
#    Updated: 2018/02/06 09:43:38 by Mingyun K        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = mkimgdbtest.s

OBJ = $(SRC:.s=.o)

SRCDIR = srcs
OBJDIR = objs

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(OBJ))

ASM = as
LINKER = ld
FLAG = -g
HEADER =
LIB = 

NAME = mkimgdbtest

.PHONY: all clean fclean re
.SUFFIXES: .s .o

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.s
	@mkdir -p $(OBJDIR)
	@$(ASM) $(FLAG) $(HEADER) $< -o $@

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
