#ifndef URDU_H
#define URDU_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int parhle_int(const char *prompt) {
    int x;
    printf("%s", prompt);
    scanf("%d", &x);
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    return x;
}

void parhle(const char *prompt, char *buf, int size) {
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

void likhde_harf(char ch) { printf("%c", ch); }
void likhde_harf_line(char ch) { printf("%c\n", ch); }

char* jodo(char* dest, const char* src) {
    char* ptr = dest;
    while (*ptr != '\0') {
        ptr++;
    }
    while (*src != '\0') {
        *ptr = *src;
        ptr++;
        src++;
    }
    *ptr = '\0';
    return dest;
}

char* nakal(char* dest, const char* src) {
    char* ptr = dest;
    while (*src != '\0') {
        *ptr = *src;
        ptr++;
        src++;
    }
    *ptr = '\0';
    return dest;
}

int muqabla(const char* s1, const char* s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return (unsigned char)*s1 - (unsigned char)*s2;
}

int lambai(const char* str) {
    int length = 0;
    while (*str != '\0') {
        length++;
        str++;
    }
    return length;
}

/* Conditional macros */
#define agr if
#define warna else
#define warna_agr else if

/* Switch macros */
#define badal switch
#define surat case
#define warna_sab default

/* Loops */
#define jab_tak(condition) while (condition)
#define karo do
#define jab_(condition) while (condition)

/* Flow control */
#define agay_chalo continue
#define ruk_jao break

/* File handling */
#define file_kholo(filename, mode) fopen(filename, mode)
#define file_band(stream) fclose(stream)
#define file_likho(stream, ...) fprintf(stream, __VA_ARGS__)
#define file_lo(stream, ...) fscanf(stream, __VA_ARGS__)
#define line_lo(str, size, stream) fgets(str, size, stream)
#define line_likho(str, stream) fputs(str, stream)

/* Character functions */
#define bara_karo(ch) toupper(ch)
#define chhota_karo(ch) tolower(ch)
#define kya_adad(ch) isdigit(ch)
#define kya_harf(ch) isalpha(ch)
#define kya_harfya_adad(ch) isalnum(ch)

#endif




