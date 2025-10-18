#ifndef URDU_IO_H
#define URDU_IO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static int parhle(const char *prompt) {
    int x;
    printf("%s", prompt);
    scanf("%d", &x);
    return x;
}

static void parhle_str(const char *prompt, char *buf, int size) {
    printf("%s", prompt);
    fflush(stdin);
    fgets(buf, size, stdin);
    size_t len = strlen(buf);
    if (len > 0 && buf[len - 1] == '\n')
        buf[len - 1] = '\0';
}


static void likhde(const char *text) {
    printf("%s", text);
}

static void likhde_int(int n) {
    printf("%d", n);
}

#endif
