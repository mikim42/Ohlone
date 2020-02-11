# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/30 19:53:28 by mikim             #+#    #+#              #
#    Updated: 2018/04/07 12:37:46 by mikim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                               Mingyun Kim    #
#                                            https://www.github.com/mikim42    #
# **************************************************************************** #

SRC = arrive_cb.cpp\
	  draw_background.cpp\
	  draw_cb.cpp\
	  draw_drive.cpp\
	  llqueue.cpp\
	  load_cars.cpp\
	  load_drive.cpp\
	  main.cpp\
	  rbqueue.cpp\
	  redraw_cb.cpp

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
CAIROFLAG = -I ~/fltk-1.3.3 `fltk-config --cxxflags --ldflags --use-cairo`

NAME = main
TEST = test
TEST_RE = test_re
CAIRO = cairo
CAIRO_RE = cairo_re

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

# compiling cairo
$(CAIRO): $(CAIRO_RE)
	@$(CXX) $(WFLAG) $(CAIROFLAG) $(HEADER) $(LIB) $(SRCS) -o $(NAME)
	@echo "[$@ Created]"

$(CAIRO_RE):
	@/bin/rm -f $(CAIRO)

clean:
	@/bin/rm -rf $(OBJDIR)
	@echo "[Directory Cleaned]"

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(TEST)
	@echo "[$(NAME) - Deleted]"

re: fclean all
