# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: shorwood <shorwood@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/07/16 12:26:44 by shorwood     #+#   ##    ##    #+#        #
#    Updated: 2019/04/18 19:25:30 by shorwood    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

#--- Initialize compilation/linkeage parameters.
NAME	= fillit
CFLAGS	= -Wall -Werror -Wextra
LDFLAGS	= -lft -Llibft/lib
IFLAGS	= -Ilibft/include

#--- Pass debug directive.
ifdef NDEBUG
    CFLAGS += -DNDEBUG -g
endif

#--- Set source project dependencies.
SRC	= fillit.c flt_import.c flt_print.c flt_solve.c
INC	= fillit.h

# **************************************************************************** #

all: $(NAME)

$(NAME): $(SRC)
	@make -C libft
	@$(CC) $^ -o $@ $(LDFLAGS) $(IFLAGS) $(CFLAGS) -O3
	@echo "\r\033[K• Binary '$(notdir $@)' compiled"

# **************************************************************************** #

clean:
	-@rm *.o 2> /dev/null || true
	@echo "• Deleted '$(NAME)' object files"
	@make -C libft clean

fclean: clean
	@rm -f $(NAME) 2> /dev/null || true
	@rm -rf $(NAME).dSYM 2> /dev/null || true
	@echo "• Deleted '$(NAME)' binaries"
	@make -C libft fclean

re: fclean all

.PHONY: clean fclean all re
