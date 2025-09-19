
#include "engine.h"
#include "core/core.h"
#include "platform/platform.h"
#include "config.h"
#include "platform/window.h"

void    engine_push_frame(t_context *ctx, int index)
{
	t_platform	*P;

	if (!ctx)
		return ;
	P = &ctx->platform;
    if (index < 0 || index >= P->window_count)
        return ;
	push_frame(P->mlx, &P->windows[index]);
}

static int	init_context(t_context *ctx)
{
	ft_memset(ctx, 0, sizeof(*ctx));
	if (!platform_init(&ctx->platform, DEFAULT_WIDTH, DEFAULT_HEIGHT, DEFAULT_TITLE))
		return (0);
	platform_input_bind(&ctx->platform);
	return (1);
}

int	engine_runtime(void)
{
	t_context	ctx;

	if (!init_context(&ctx)
			return (1);
	core_run(&ctx);
	platform_shutdown(&ctx.platform);
	return (0);
}
