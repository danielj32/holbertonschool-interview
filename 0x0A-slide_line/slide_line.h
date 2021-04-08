#ifndef SLIDE_LINE
#define SLIDE_LINE
#define SLIDE_LEFT 99
#define SLIDE_RIGHT 66
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

void slide__left(int *line, size_t size);
void slide_right(int *line, size_t size);
void second_left(int *line, size_t size);
void second_right(int *line, size_t size);
int slide_line(int *line, size_t size, int direction);

#endif
