#ifndef STRUCT_
#define STRUCT_

#include <stdio.h>

struct InfText {
    char* text;
    int str_count;
    unsigned long text_len;
};

struct TextSort 
{
    char* ind_mas;
    int sizes_of_str;
};


struct Text {    
    struct InfText orig_text;
    struct TextSort* text_compare;
};

#endif