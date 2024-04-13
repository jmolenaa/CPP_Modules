RED=\033[1;31m
GREEN=\033[1;32m
YELLOW=\033[1;33m
BLUE=\033[1;34m
MAGENTA=\033[1;35m
CYAN=\033[1;36m
END=\033[0m

# variables

NAME = iter
HEADER_FILES  = Fixed.hpp iter.hpp
SRC_FILES = main.cpp Fixed.cpp
OBJ_FILES = $(SRC_FILES:%.cpp=obj/%.o)
HEADERS = $(HEADER_FILES:%=incs/%)
OBJ_DIR = obj

# compilation variables

CC = c++
INCLUDES = -I incs
CFLAGS = -Wall -Werror -Wextra -std=c++11
ifdef DEBUG
CFLAGS += -g -fsanitize=address
endif

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@echo "${MAGENTA}Creating $@${END}"
	@$(CC) $(INCLUDES) $(CFLAGS) -o $@ $(OBJ_FILES)
	@echo "${GREEN}Done!${END}"

obj/%.o: src/%.cpp $(HEADERS) | $(OBJ_DIR)
	@echo "${BLUE}Compiling $<${END}"
	@$(CC) $(INCLUDES) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

clean:
	@echo "${RED}Removing objs${END}"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "${RED}Removing ${NAME} ${END}"
	@rm -rf $(NAME)

d:
	@$(MAKE) DEBUG=1 all

re: fclean all
