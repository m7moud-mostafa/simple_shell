#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
int _printf(const char *format, ...);
void handle_specifier(char specifier, va_list args, int *len);
void c_handler(char c, int *len);
void s_handler(char *str, int *len);
void i_handler(int num, int *len);
void u_handler(unsigned int num, int *len);

unsigned int _strlen(char *str);
int power(int base, int exponent);
#endif
