#ifndef SORT_
#define SORT_

#include <sys\stat.h>
#include "Struct.h"

void qSort(void* arr, int beg, int ending, size_t el_size,
            int (*compare_func)(void* elem1, void* elem2));
int CompareStraight(void* elem1, void* elem2);
int CompareReverse(void* elem1, void* elem2);
int CheckCondOfChar(char symb1, char symb2);
int IsChar(char symb, int* counter);
void SwapStr(void* str1, void* str2);


#endif 