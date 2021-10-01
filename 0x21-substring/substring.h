#ifndef _SUBSTR_H
#define _SUBSTR_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int *find_substring(char const *s, char const **words, int nb_words, int *n);
int comp_twovalues(const void *x, const void *z);
int continus(int *aux_indx, int wordlen, int idx_len);
int *finding(char const *s, char const **words, int nb_words);
#endif
