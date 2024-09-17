NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror
GREEN   = "\\033[32m"
YELLOW	= "\\033[33m"
NC      = "\\033[0m"

LIBFT_DIR = ./libft
PRINTF_DIR= ./libft/ft_printf
GNL_DIR = get_next_line
MINILIBX_DIR = ./minilibx-linux
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a
MINILIB = $(MINILIBX_DIR)/libmlx.a
INCLUDES = -I ./inc -I $(LIBFT_DIR) -I $(PRINTF_DIR) -I $(GNL_DIR) -I $(MINILIBX_DIR)

SRC_DIR = src/
OBJ_DIR = obj/

# Define GNL_SRCS and GNL_OBJS for get_next_line separately
GNL_SRCS = $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c
GNL_OBJS = $(patsubst $(GNL_DIR)/%.c,$(OBJ_DIR)$(GNL_DIR)/%.o,$(GNL_SRCS))

# Source files from the src directory
SRCS =  src/Main.c \
	src/errors.c \
	src/parse_map.c \
	src/colors.c \
	src/utils.c \
	src/utils2.c \
	src/draw_map.c \
	src/keys.c \
	src/set_colors.c \
	src/end_of_program.c

# Object files: combine normal objects and GNL objects
OBJS =  $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)$(SRC_DIR)%.o, $(SRCS)) $(GNL_OBJS)

TOTAL_FILES := $(words $(SRCS) $(GNL_SRCS))
CURRENT_FILE := 0

define progress_bar
	@$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE) + 1))))
	@printf "\r$(YELLOW)Compiling fdf... [%-$(TOTAL_FILES)s] %d/%d $(NC)" \
	$$(for i in $$(seq 1 $(CURRENT_FILE)); do printf "#"; done) $(CURRENT_FILE) $(TOTAL_FILES)
	@if [ $(CURRENT_FILE) -eq $(TOTAL_FILES)  ]; then echo ""; fi
endef

# Rule for normal src files
$(OBJ_DIR)src/%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	$(call progress_bar)

# Rule for get_next_line files
$(OBJ_DIR)get_next_line/%.o: $(GNL_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	$(call progress_bar)

FDF_LOGO = "\033[0;35m\
███████╗██████╗ ███████╗     \n\
██╔════╝██╔══██╗██╔════╝     \n\
█████╗  ██║  ██║█████╗       \n\
██╔══╝  ██║  ██║██╔══╝       \n\
██║     ██████╔╝██║          \n\
╚═╝     ╚═════╝ ╚═╝          \n\
\033[0m"


all: $(LIBFT) $(PRINTF) $(MINILIB) $(NAME)

$(NAME): $(OBJS)
	@printf "\n"
	@printf $(FDF_LOGO)
	@echo "$(GREEN)Linking objects to create executable...$(NC)"
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -L$(PRINTF_DIR) -L$(MINILIBX_DIR) -lft -lftprintf -lmlx -lX11 -lXext -lm -o $(NAME)
	@echo "$(GREEN)Executable $(NAME) created!$(NC)"

$(LIBFT):
	@make -C $(LIBFT_DIR) -s

$(PRINTF):
	@make -C $(PRINTF_DIR) -s

clean:
	@rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean --no-print-directory
	@make -C $(PRINTF_DIR) clean --no-print-directory

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean --no-print-directory
	@make -C $(PRINTF_DIR) fclean --no-print-directory

re: fclean all

.PHONY: all clean fclean re
