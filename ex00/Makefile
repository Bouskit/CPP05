# ─── CONFIGURATION ───────────────────────────────────────────────────────

NAME      := exec
CC        := c++
CPPFLAGS  := -Wall -Wextra -Werror -std=c++98 -Iinc

SRC_DIR   := srcs
OBJ_DIR   := objs

# ─── SOURCES & OBJETS ────────────────────────────────────────────────────

SRC_NAMES := main.cpp Bureaucrat.cpp
SRC       := $(addprefix $(SRC_DIR)/, $(SRC_NAMES))
OBJ       := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

# ─── COULEURS POUR TERMINAL ──────────────────────────────────────────────

GREEN := \033[1;32m
YELLOW := \033[1;33m
RESET := \033[0m

# ─── COMMANDES PRINCIPALES ───────────────────────────────────────────────

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(YELLOW)[Linking]$(RESET) -> $(NAME)"
	@$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	@echo "$(GREEN)[Compiling]$(RESET) -> \$<"
	@$(CC) $(CPPFLAGS) -c \$< -o \$@

clean:
	@echo "$(YELLOW)[Cleaning]$(RESET) object files..."
	@$(RM) $(OBJ)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(YELLOW)[Cleaning]$(RESET) binary..."
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
