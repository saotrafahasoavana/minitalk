FLAGS	=	-Wall -Wextra -Werror

all:
		@cd libft && make
		@cd printf && make
		@cc $(FLAGS) mandatory/server.c libft/libft.a printf/libftprintf.a -o server
		@cc $(FLAGS) mandatory/client.c libft/libft.a printf/libftprintf.a -o client

clean:
		@cd libft && make clean
		@cd printf && make clean
		@rm -f server
		@rm -f client

fclean:	clean
		@cd libft && make fclean
		@cd printf && make fclean

re:	fclean all

bonus:	fclean
		@cd libft && make
		@cd printf && make
		@cc $(FLAGS) bonus/server_bonus.c libft/libft.a printf/libftprintf.a -o server
		@cc $(FLAGS) bonus/client_bonus.c libft/libft.a printf/libftprintf.a -o client
