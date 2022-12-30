#include "cmocka_platform.h"
#include <setjmp.h>
#ifdef __cplusplus
extern "C"
{
    void siglongjmp(jmp_buf env, int val);
    int sigsetjmp(jmp_buf env, int savemask);
}
#endif
void siglongjmp(jmp_buf env, int val)
{
    longjmp(env, val);
}
int sigsetjmp(jmp_buf env, int savemask)
{
    return setjmp(env);
}
#include <stdlib.h>
#include <stdio.h>

FILE *const stdin = NULL;
FILE *const stdout = NULL;
FILE *const stderr = NULL;

void (*signal(int sig, void (*func)(int)))(int)
{
    return NULL;
}