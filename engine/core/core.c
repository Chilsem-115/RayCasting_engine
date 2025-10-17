
#include "core.h"
#include "mlx.h"
#include "platform/input/input.h"
#include "engine.h"

static int	on_destroy(void *param)
{
	t_platform	*P;

	P = (t_platform *)param;
	mlx_loop_end(P->mlx);
	return (0);
}

void	platform_input_bind(t_platform *P)
{
	mlx_hook(P->windows[0].handle, 17, 0, &on_destroy, P);
}

static int	core_on_frame(void *ud)
{
	t_context	*ctx;

	ctx = (t_context *)ud;
	input_frame_begin(&ctx->platform.input);
	engine_push_frame(ctx, ctx->platform.main_index);
	return (0);
}

void	core_run(t_context *ctx)
{
	mlx_loop_hook(ctx->platform.mlx, &core_on_frame, ctx);
	mlx_loop(ctx->platform.mlx);
}
