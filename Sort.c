#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#include "Sort.h"


void qSort(void* arr, int beg, int ending, size_t el_size,
            int (*compare_func)(void* elem1, void* elem2)) {

    int left = beg, right = ending;

    int sr_elem = beg;

    void* pilot = (char*)arr + sr_elem*el_size;

    while(left <= right) {

        while(compare_func((char*)arr + left*el_size, (char*)pilot) < 0) {
            left++;
            printf("First str less\n");
        }

        while(compare_func((char*)arr + right*el_size,(char*)pilot) > 0) {
            right--;
            printf("Second str less\n");
        }

        if (left <= right) {
            SwapStr((char*)arr + left*el_size, (char*)arr + right*el_size);

            // printf("Строка %d: %s\nСтрока %d: %s\n\n", left, arr[left], right, arr[right]);
            left++;
            right--;
        }

    }

    if (beg < right) {
        qSort(arr, beg, right, el_size, compare_func);
    }

    if (ending > left) {
        qSort(arr, left, ending, el_size, compare_func);
    }
}

int CompareReverse(void* elem1, void* elem2) {      // change char* str2!

    struct TextSort struct1 = *((struct TextSort*)elem1);
    struct TextSort struct2 = *((struct TextSort*)elem2);

    int symb1 = 0, symb2 = 0;
    int counter_s1 = (struct1.sizes_of_str) - 1 , counter_s2 = struct2.sizes_of_str - 1;

    while (counter_s1 - symb1 >= 0 && counter_s2 - symb2 >= 0) {

        while(counter_s1 - symb1 >= 0 && IsChar((struct1.ind_mas)[counter_s1 - symb1], &symb1));
        while(counter_s2 - symb2 >= 0 && IsChar(struct2.ind_mas[counter_s2 - symb2], &symb2));
        if (counter_s1 - symb1 < 0 || counter_s2 - symb2 < 0) {
            return 0;
        } else {
            int c1 = toupper((struct1.ind_mas)[counter_s1 - symb1]);
            int c2 = toupper(struct2.ind_mas[counter_s2 - symb2]);

            printf("Number of char in str 1: %d\n",counter_s1 - symb1);
            printf("Number of char in str 2: %d\n",counter_s2 - symb2);
            printf("First char: %c\n", c1);
            printf("Second char: %c\n\n", c2);

            if ( CheckCondOfChar((struct1.ind_mas)[counter_s1 - symb1], struct2.ind_mas[counter_s2 - symb2]) ) {
                return (c1 - c2);
            }
        }

        --counter_s1;
        --counter_s2;

    }

    return ((struct1.ind_mas)[counter_s1 - symb1] - struct2.ind_mas[counter_s2 - symb2]);
}

int CompareStraight(void* elem1, void* elem2) {
    int symb = 0;
    int counter_s1 = 0, counter_s2 = 0;

    struct TextSort struct1 = *((struct TextSort*)elem1);
    struct TextSort struct2 = *((struct TextSort*)elem2);

    double minim = fmin(struct1.sizes_of_str, struct2.sizes_of_str);

    printf("\n\n");

    while (symb + counter_s1 <= minim && symb + counter_s2 <= minim) {

        while(IsChar(struct1.ind_mas[symb + counter_s1], &counter_s1));
        while(IsChar(struct2.ind_mas[symb + counter_s2], &counter_s2));

        int c1 = toupper((struct1.ind_mas)[symb + counter_s1]);
        int c2 = toupper(struct2.ind_mas[symb + counter_s2]);

        if ( CheckCondOfChar((struct1.ind_mas)[symb + counter_s1], struct2.ind_mas[symb + counter_s2]) ) {
            return (c1 - c2);
        }

        ++symb;

    }

    return ((struct1.ind_mas)[symb + counter_s1] - struct2.ind_mas[symb + counter_s2]);
}

void SwapStr(void* str1, void* str2) {
    struct TextSort swap_str = *((struct TextSort*)str2);
    *((struct TextSort*)str2) = *((struct TextSort*)str1);
    *((struct TextSort*)str1) = swap_str;
}

int CheckCondOfChar(char symb1, char symb2) {
     return (toupper(symb1) != toupper(symb2));
}

int IsChar(char symb, int* counter) {
    //printf("Поступающая буква: %c\n", symb);
    if((symb < 65 || symb > 122 || (symb >  90 && symb < 97)) && symb != '\0' ) {
        (*counter)++;
        return 1;
    }
    return 0;
}