
# **************************************************************************** #
#                                    CONFIG                                    #
# **************************************************************************** #

NAME   = raycasting_engine
CC     = clang
CFLAGS = #-Wall -Wextra -Werror

INCS = -Iengine \
       -Iengine/assets \
       -Iengine/audio \
       -Iengine/comp \
       -Iengine/core \
       -Iengine/core/actions \
       -Iengine/core/events \
       -Iengine/gfx \
       -Iengine/platform \
       -Iengine/platform/input \
       -Iengine/raycast \
       -Iengine/utils \
       -Ilib/mlx \
       -Ilib/libft

LDFLAGS = -Llib/mlx -Llib/libft -lft -lX11 -lXext -lm

OBJDIR = object

LIBFT_DIR = lib/libft
MLX_DIR = lib/mlx

LIBFT_A   = $(LIBFT_DIR)/libft.a
MLX_A     = $(MLX_DIR)/libmlx_Linux.a

# **************************************************************************** #
#                                   MODULES                                    #
# **************************************************************************** #

ENGINE_SRCS = \
engine/engine.c \
\
engine/platform/platform.c \
engine/platform/window.c \
engine/platform/input/input.c \
engine/platform/input/helper.c \
\
engine/core/core.c \
engine/core/errors.c \
engine/core/log.c \
engine/core/loop.c \
engine/core/time.c \
\
engine/core/actions/actions.c \
engine/core/actions/queries.c \
engine/core/actions/utils.c \
\
engine/core/events/event.c \
\
engine/assets/file_io.c \
engine/assets/texture_xpm.c \
\
engine/audio/audio_module.c \
\
engine/gfx/gfx.c \
\
engine/raycast/rc_module.c \
engine/raycast/rc_map.c \
engine/raycast/rc_render.c \
engine/raycast/rc_sprite.c \
\
engine/comp/collision.c \
engine/comp/doors.c \
engine/comp/path_bfs.c \
engine/comp/triggers.c \
\
engine/utils/math.c \
engine/utils/mem.c \
engine/utils/rng.c \
engine/utils/str.c

GAME_SRCS = \
game/main.c

SRCS = $(ENGINE_SRCS) $(GAME_SRCS)

# --- Object files live under object/ mirroring the tree (explicit, no funcs) ---
ENGINE_OBJS = \
$(OBJDIR)/engine/engine.o \
\
$(OBJDIR)/engine/platform/platform.o \
$(OBJDIR)/engine/platform/window.o \
$(OBJDIR)/engine/platform/input/input.o \
$(OBJDIR)/engine/platform/input/helper.o \
\
$(OBJDIR)/engine/core/core.o \
$(OBJDIR)/engine/core/errors.o \
$(OBJDIR)/engine/core/log.o \
$(OBJDIR)/engine/core/loop.o \
$(OBJDIR)/engine/core/time.o \
\
$(OBJDIR)/engine/core/actions/actions.o \
$(OBJDIR)/engine/core/actions/queries.o \
$(OBJDIR)/engine/core/actions/utils.o \
\
$(OBJDIR)/engine/core/events/event.o \
\
$(OBJDIR)/engine/assets/file_io.o \
$(OBJDIR)/engine/assets/texture_xpm.o \
\
$(OBJDIR)/engine/audio/audio_module.o \
\
$(OBJDIR)/engine/gfx/gfx.o \
\
$(OBJDIR)/engine/raycast/rc_module.o \
$(OBJDIR)/engine/raycast/rc_map.o \
$(OBJDIR)/engine/raycast/rc_render.o \
$(OBJDIR)/engine/raycast/rc_sprite.o \
\
$(OBJDIR)/engine/comp/collision.o \
$(OBJDIR)/engine/comp/doors.o \
$(OBJDIR)/engine/comp/path_bfs.o \
$(OBJDIR)/engine/comp/triggers.o \
\
$(OBJDIR)/engine/utils/math.o \
$(OBJDIR)/engine/utils/mem.o \
$(OBJDIR)/engine/utils/rng.o \
$(OBJDIR)/engine/utils/str.o

GAME_OBJS = \
$(OBJDIR)/game/main.o

OBJS = $(ENGINE_OBJS) $(GAME_OBJS)

# **************************************************************************** #
#                                    RULES                                     #
# **************************************************************************** #

# Pattern rule to compile into object/ while mirroring folders
$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

all: $(NAME)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_A):
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJS) $(MLX_A) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_A) $(LIBFT_A) $(LDFLAGS) -o $(NAME)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: $(NAME)
	./$(NAME)

.PHONY: all clean fclean re run
