#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int _putchar(char c);
int valid_integer(char *av);
char *check_if(int length);
void mul(char *av1, char *av2, int l1, int l2, char *total);
void insert(char *result, int x, int position);
#endif
