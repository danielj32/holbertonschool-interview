#ifndef SLIDE_LINE
#define SLIDE_LINE
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

int slide_line(int *line, size_t size, int direction);
void jump_it(int *l, size_t size, int nxt);

#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1

#endif
