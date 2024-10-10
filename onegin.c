#include <stdio.h>
#include <stdlib.h>
#include "Sort.h"
#include "Output.h"
#include "Input.h"
#include "Struct.h"

int main() {
    struct Text onegin = {};

    ReadText(&onegin);

    qSort(onegin.text_compare, 0, onegin.orig_text.str_count -1, sizeof(struct TextSort), CompareStraight);
    IterationOfOutput(onegin, output_straight, OutputWithProcessing);   //Сортировка по алфавиту

    printf("\n\n\n");

    qSort(onegin.text_compare, 0, onegin.orig_text.str_count -1, sizeof(struct TextSort), CompareReverse);
    IterationOfOutput(onegin, output_reverse, OutputWithProcessing);  // Сортировка по алфавиту с конца строки

    IterationOfOutput(onegin, output_text, OutputText); // Вывод оригинального текста

    free(onegin.text_compare);
    free(onegin.orig_text.text);

    printf("End program!\n");
}

