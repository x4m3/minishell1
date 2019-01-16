##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## man man
##

BINARY = mysh
BUILD_DIR = build

CFLAGS += -Wall -Wextra -Iinclude
LDFLAGS +=
CC = cc

INC = include/mysh.h include/library.h include/config.h include/colors.h
OBJ = $(SRC:%.c=$(BUILD_DIR)/%.o)
SRC = source/mysh.c \
      library/len_str.c \
      library/putput.c \
      library/putput_err.c \
      library/str_to_word_array.c \

all: options $(BINARY)

$(BUILD_DIR)/%.o: %.c $(INC)
	@mkdir -p $(@D)
	@echo "  CC       $<"
	@$(CC) $(CFLAGS) -c $< -o $@

options:
	@echo "  CC       $(CC)"
	@echo "  CLFAGS   $(CFLAGS)"
	@echo "  LDFLAGS  $(LDFLAGS)"

$(BINARY): $(OBJ)
	@echo "  BUILD    $@"
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS)

clean:
	@echo "  RM       $(BUILD_DIR)"
	@rm -rf $(BUILD_DIR)

fclean: clean
	@echo "  RM       $(BINARY)"
	@rm -f $(BINARY)

re:
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) all --no-print-directory

.PHONY: all options clean fclean re
