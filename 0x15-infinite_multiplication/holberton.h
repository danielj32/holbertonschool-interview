#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int _putchar(char c);
int valid_integer(char *argv);
char *check_if_result(int length);
void mul(char *argv1, char *argv2, int l1, int l2, char *result);
void insert(char *result, int x, int position);
#endif
