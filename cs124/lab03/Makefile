# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Mingyun Kim <mikim@student.42.us.org>      +#+  +:+       +#+         #
#    GitHub:  https://github.com/mikim42          +#+#+#+#+#+   +#+            #
#    Created: 2018/02/08 12:59:14 by Mingyun K         #+#    #+#              #
#    Updated: 2018/03/30 20:09:30 by mikim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.cpp\
	  abc.cpp\
	  readABCfile.cpp\
	  convertABCtoSOX.cpp\
	  createPlayCmd.cpp\
	  playSong.cpp\
	  myCreate.cpp\
	  myPush.cpp\
	  myPop.cpp\
	  myDestroy.cpp

OBJ = $(SRC:.cpp=.o)

SRCDIR = srcs
OBJDIR = objs

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(OBJ))

CATCH = catch/catch.o
HEADER = -I includes
LIB = 

CC = gcc
CXX = g++ -std=c++11
ASM = as
LINKER = ld

GFLAG = -g
CFLAG = -c
WFLAG = -Wall -Wextra -Werror
UNIT = -D UNIT_TEST

NAME = main
TEST = test
TEST_RE = test_re

.PHONY: all clean fclean re
.SUFFIXES: .s .o

all: $(NAME)

# compiling program
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	@$(CXX) $(CFLAG) $(WFLAG) $(HEADER) $< -o $@

$(NAME): $(OBJS)
	@$(CXX) $(OBJS) $(LIB) -o $@
	@echo "[$(@) Created]"

# compiling catch test
$(TEST): $(TEST_RE)
	@/bin/rm -f $@
	@$(CXX) $(WFLAG) $(UNIT) $(HEADER) $(LIB) $(CATCH) $(SRCS) -o $@
	@echo "[$(@) Created]"

$(TEST_RE):
	@/bin/rm -f $(TEST)

clean:
	@/bin/rm -rf $(OBJDIR)
	@echo "[Directory Cleaned]"

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(TEST)
	@echo "[$(NAME) - Deleted]"

re: fclean all
