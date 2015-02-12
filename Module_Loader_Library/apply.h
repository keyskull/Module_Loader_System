
#ifndef APPLY_H
#define APPLY_H

#include "terminal.h"
#define Not_Init_Apply -1
#define Initialized_Apply ((void *)-1)
#define Terminal_error -3
#define Not_Found_Terminal ((void *)-4)
#if defined(__cplusplus)
extern "C"
{
#endif                          /* __cplusplus */
int Apply_repl(const Terminal_data *terminal);
#if defined(__cplusplus)
}                               /* End of extern "C" */
#endif                          /* __cplusplus */

#endif