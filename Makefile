SRC_FILES = error.c atoi.c philo.c checks.c start.c init.c actions.c \
time.c display.c monitor.c free.c death.c
OBJS = $(patsubst %.c, %.o, $(SRC_FILES))
SRC_DIR = src/
OBJS_DIR = objs/
LIB = philo.a
PATH_FILES_C = $(addprefix $(SRC_DIR), $(SRC_FILES))
PATH_FILES_O = $(addprefix $(OBJS_DIR), $(OBJS))

all: $(LIB)

$(LIB): 
	@clang -g -Wall -Wextra -Werror -I include/ -c $(PATH_FILES_C)
	@ar rcs $(LIB) $(OBJS)
	@clang src/main.c -g -Wall -Wextra -Werror $(LIB) -I include/ -o philo -pthread
	@mv $(OBJS) $(OBJS_DIR)
clean:
	@rm -rf $(PATH_FILES_O)
fclean: clean
	@rm -rf $(LIB) philo
re: fclean all