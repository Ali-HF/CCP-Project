#ifndef URDU_H
#define URDU_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stddef.h> 

/* --- Input/Output Functions (Parhle/Likhde) --- */

int parhle_int(const char *prompt) {
    int x;
    printf("%s", prompt);
    scanf("%d", &x);
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // Clear buffer
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

/* --- String Manipulation Functions --- */

// Lambai (Length) - Equivalent to strlen
int lambai(const char* str) {
    int length = 0;
    while (*str != '\0') {
        length++;
        str++;
    }
    return length;
}

// Nakal (Copy) - Equivalent to strcpy
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

// Jodo (Concatenate) - Equivalent to strcat
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

// Muqabla (Compare) - Equivalent to strcmp
int muqabla(const char* s1, const char* s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return (unsigned char)*s1 - (unsigned char)*s2;
}

// Ulta Karde (Reverse) - Reverses the string 'str' in place.
char* ulta_karde(char* str) {
    int len = lambai(str); 
    char* start = str;
    char* end = str + len - 1;
    char temp;

    while (end > start) {
        temp = *start;
        *start = *end;
        *end = temp;
        
        start++;
        end--;
    }
    return str;
}

// Harf Dhundo (Find Character) - Equivalent to strchr
char* harf_dhundo(const char* str, int ch) {
    while (*str != '\0') {
        if (*str == (char)ch) {
            return (char*)str;
        }
        str++;
    }
    if (*str == (char)ch) {
        return (char*)str;
    }
    return NULL;
}

// Hissa Nakal (Substring Copy) - Equivalent to strncpy
char* hissa_nakal(char* dest, const char* src, size_t n) {
    char* ptr = dest;
    size_t count = 0;

    while (count < n && *src != '\0') {
        *ptr = *src;
        ptr++;
        src++;
        count++;
    }

    while (count < n) {
        *ptr = '\0';
        ptr++;
        count++;
    }
    
    return dest;
}

// Lafz Dhundo (Find Substring) - Equivalent to strstr
char* lafz_dhundo(const char* haystack, const char* needle) {
    if (*needle == '\0') {
        return (char*)haystack;
    }

    while (*haystack != '\0') {
        const char* h = haystack;
        const char* n = needle;
        
        while (*n != '\0' && *h == *n) {
            h++;
            n++;
        }
        
        if (*n == '\0') {
            return (char*)haystack;
        }

        haystack++;
    }

    return NULL;
}

// Bara Karde (Make Upper) - Converts all alphabetic characters in 'str' to uppercase in place.
char* bara_karde(char* str) {
    char* ptr = str;
    while (*ptr != '\0') {
        *ptr = toupper(*ptr); 
        ptr++;
    }
    return str;
}

// Chhota Karde (Make Lower) - Converts all alphabetic characters in 'str' to lowercase in place.
char* chhota_karde(char* str) {
    char* ptr = str;
    while (*ptr != '\0') {
        *ptr = tolower(*ptr); 
        ptr++;
    }
    return str;
}


/* --- Time Functions --- */
void abhi_ka_time(char *buffer, int size) {
    time_t abhi = time(NULL);
    struct tm *local = localtime(&abhi);
    strftime(buffer, size, "%c", local);
}

void aaj_ki_tareekh(char *buffer, int size) {
    time_t abhi = time(NULL);
    struct tm *local = localtime(&abhi);
    strftime(buffer, size, "%d-%m-%Y", local);
}

void abhi_ka_wakt(char *buffer, int size) {
    time_t abhi = time(NULL);
    struct tm *local = localtime(&abhi);
    strftime(buffer, size, "%H:%M:%S", local);
}

void ruk_jana(int seconds) {
    time_t start = time(NULL);
    while (difftime(time(NULL), start) < seconds);
}

void likhde_abhi_ka_time() {
    time_t abhi = time(NULL);
    printf("%s", ctime(&abhi)); // ctime already includes a newline
}

/* --- Character Functions (Macros) --- */
#define bara_karo(ch) toupper(ch)
#define chhota_karo(ch) tolower(ch)
#define kya_adad(ch) isdigit(ch)
#define kya_harf(ch) isalpha(ch)
#define kya_harfya_adad(ch) isalnum(ch)

/* --- Conditional Macros --- */
#define agr if
#define warna else
#define warna_agr else if

/* --- Switch Macros --- */
#define badal switch
#define surat case
#define warna_sab default

/* --- Loop Macros --- */
#define jab_tak(condition) while (condition)
#define karo do
#define jab_(condition) while (condition)

/* --- Flow Control Macros --- */
#define agay_chalo continue
#define ruk_jao break

/* --- File Handling Macros --- */
#define file_kholo(filename, mode) fopen(filename, mode)
#define file_band(stream) fclose(stream)
#define file_likho(stream, ...) fprintf(stream, __VA_ARGS__)
#define file_lo(stream, ...) fscanf(stream, __VA_ARGS__)
#define line_lo(str, size, stream) fgets(str, size, stream)
#define line_likho(str, stream) fputs(str, stream)

#endif // URDU_H

