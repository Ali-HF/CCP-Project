#ifndef URDU_H
#define URDU_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int parhle(const char *prompt) {
    int x;
    printf("%s", prompt);
    scanf("%d", &x);
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    return x;
}

void parhle_str(const char *prompt, char *buf, int size) {
    printf("%s", prompt);
    if (fgets(buf, size, stdin) != NULL) {
        size_t len = strlen(buf);
        if (len > 0 && buf[len - 1] == '\n')
            buf[len - 1] = '\0';
    }
}

float parhle_float(const char *prompt) {
    float x;
    printf("%s", prompt);
    scanf("%f", &x);
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    return x;
}

double parhle_double(const char *prompt) {
    double x;
    printf("%s", prompt);
    scanf("%lf", &x);
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    return x;
}

void likhde(const char *text) {
    printf("%s", text);
}

void likhde_int(int n) {
    printf("%d", n);
}

void likhde_float(float n) {
    printf("%.2f", n);
}

void likhde_double(double n) {
    printf("%.2lf", n);
}

void likhde_line(const char *text) {
    printf("%s\n", text);
}

void likhde_int_line(int n) {
    printf("%d\n", n);
}

void likhde_float_line(float n) {
    printf("%.2f\n", n);
}

/* Control flow statements */
#define agr if
#define warna else
#define warna_agr else if

/* Switch statement aliases */
#define badal switch
#define surat case
#define warna_sab default
#define tor break

#define jab_tak(condition) while (condition)

/* do-while Urdu aliases: usage → karo { ... } jab_(condition); */
#define karo do
#define jab_(condition) while (condition)

#endif
