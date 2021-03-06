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

DEBUG ?= 0
ifeq ($(DEBUG), 1)
    CFLAGS += -g
endif

INC = include/mysh.h \
      include/library.h \
      include/colors.h \
      include/builtins.h
OBJ = $(SRC:%.c=$(BUILD_DIR)/%.o)
SRC = source/mysh.c \
      source/init_t_colors.c \
      source/prompt.c \
      source/exec.c \
      source/path.c \
      source/builtins/builtins.c \
      source/builtins/exit.c \
      source/builtins/cd.c \
      source/builtins/env.c \
      source/builtins/setenv.c \
      source/builtins/unsetenv.c \
      source/builtins/help.c \
      library/len_str.c \
      library/putput.c \
      library/putput_err.c \
      library/str_to_word_array.c \
      library/free_char_arr.c \
      library/str_compare.c \
      library/gnl_stdin.c \
      library/dup_char_arr.c \
      library/str_n_compare.c \
      library/str_copy.c \
      library/str_dup.c \

all: options $(BINARY)

$(BUILD_DIR)/%.o: %.c $(INC)
	@mkdir -p $(@D)
	@echo "  CC       $<"
	@$(CC) $(CFLAGS) -c $< -o $@

options:
	@echo "  CC       $(CC)"
	@echo "  CFLAGS   $(CFLAGS)"
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
