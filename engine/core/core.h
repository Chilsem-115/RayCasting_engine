
#ifndef CORE_H
#define CORE_H

# include "platform/platform.h"

struct s_context;
typedef struct s_context t_context;

void	platform_input_bind(t_platform *P);
void	core_run(t_context *ctx);

#endif
