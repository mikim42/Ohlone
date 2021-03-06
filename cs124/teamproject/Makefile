# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/11 16:30:24 by mikim             #+#    #+#              #
#    Updated: 2018/05/11 16:31:34 by mikim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                               Mingyun Kim    #
#                                            https://www.github.com/mikim42    #
# **************************************************************************** #

SRC = main.cpp

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
FLTK = -I ~/fltk-1.3.3 `fltk-config --cxxflags --ldflags --use-cairo`

NAME = main
TEST = test
TEST_RE = test_re
GUI = gui
GUI_RE = gui_re

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

# compiling gui
$(GUI): $(GUI_RE)
	@$(CXX) $(FLTK) $(HEADER) $(LIB) $(SRCS) -o $(NAME)
	@echo "[$@ Created]"

$(GUI_RE):
	@/bin/rm -f $(GUI)

clean:
	@/bin/rm -rf $(OBJDIR)
	@echo "[Directory Cleaned]"

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(TEST)
	@echo "[$(NAME) - Deleted]"

re: fclean all
