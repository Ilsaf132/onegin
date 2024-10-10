#include <stdlib.h>
#include <stdio.h>
#include <sys\stat.h>
#include "Input.h"

void ReadText(struct Text* onegin) {
    struct stat buf;

    stat("text_onegin.txt", &(buf));

    (onegin -> orig_text).text_len = buf.st_size;
    printf("Size of file: %ld\n", buf.st_size);

    (onegin -> orig_text).text = (char*) calloc(buf.st_size + 2, sizeof(char));

    FILE *fp = fopen("text_onegin.txt", "rb");
    if(fp)
    {
        fread((onegin -> orig_text).text, (size_t)(onegin -> orig_text).text_len, 1, fp);

        CountStr(onegin);

        FullingMasAdr(onegin);

        fclose(fp);
    }

}

void CountStr(struct Text* onegin) {

    for (unsigned long symb = 0; symb < (onegin -> orig_text).text_len; ++symb) {

        if (((onegin -> orig_text).text)[symb] == '\r') {

            ((onegin -> orig_text).text)[symb] = '\0';
            (onegin -> orig_text).str_count++;

        } else if (symb == (onegin -> orig_text).text_len - 1 && ((onegin -> orig_text).text)[symb] != '\n') {
            printf("End of file\n");
            ((onegin -> orig_text).text)[symb + 1] = '\0';
            ((onegin -> orig_text).text)[symb + 2] = '\n';

            (onegin -> orig_text).text_len += 2;

            printf("Новая длина текста: %ld\n", (onegin -> orig_text).text_len);

            (onegin -> orig_text).str_count++;
        }

    }
    printf("Count of str: %d\n", (onegin -> orig_text).str_count);
}

void FullingMasAdr(struct Text* onegin) {
    size_t type = sizeof(struct TextSort);

    onegin -> text_compare  =  (struct TextSort*) calloc((onegin -> orig_text).str_count + 1, type);

    (onegin -> text_compare + 0*type) -> ind_mas = (onegin -> orig_text).text;

    int str = 1;
    for(unsigned long symb = 1; symb < (onegin -> orig_text).text_len ; ++symb) {
        if (((onegin -> orig_text).text)[symb] == '\n') {
            printf("symb == \\n(%d) \n", symb);

            if (symb != (onegin -> orig_text).text_len - 1) {
                printf("symb != ...\n");
                printf("str = %d\n", str);
                printf("str_count = %d\n", (onegin -> orig_text).str_count);

                (onegin -> text_compare[str]).ind_mas = &(((onegin -> orig_text).text)[symb]) + 1;
                printf("write ind_mass successfully!\n");
                (onegin -> text_compare[str-1]).sizes_of_str = (onegin -> text_compare[str]). ind_mas \
                                                             - (onegin -> text_compare[str-1]).ind_mas - 2;
                printf("write size of str successfully!\n");

                printf("Address of %d: %p\n", str, onegin -> text_compare[str].ind_mas);
                
                printf("Str len %d: %d\n\n", str-1, onegin -> text_compare[str-1].sizes_of_str); 
                str++;

            } else {

                onegin -> text_compare[str].ind_mas = &(((onegin -> orig_text).text)[symb]) - 2; //Адрес конца последней строки
                onegin -> text_compare[str-1].sizes_of_str = onegin -> text_compare[str].ind_mas - onegin -> text_compare[str-1].ind_mas + 1;

                printf("Str last len %d: %d\n\n", str-1, onegin -> text_compare[str-1].sizes_of_str);
            }
            printf("End processing \\n\n");

        }
    }

}