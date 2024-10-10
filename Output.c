#include "Output.h"

void IterationOfOutput(struct Text onegin, const char output_mode[],
                        void (*Output)(struct Text onegin, FILE* fp)) {

    static int iteration_out = 0;

    if (iteration_out == 0) {
        FILE* fp = fopen("onegin_result.txt", "wb");

        fputs(output_mode, fp);
        Output(onegin, fp);

        ++iteration_out;

    } else {
        FILE* fp = fopen("onegin_result.txt", "ab");

        fputs(output_mode, fp);
        Output(onegin, fp);
    }
}

// void OutputColor(struct Text onegin, int middle) {
//     for(int str = 0; str < (onegin -> text_compare).str_count; ++str) {
//         if (str < middle) {
//             txSetConsoleAttr(FOREGROUND_GREEN);
//         } else if (str == middle) {
//             txSetConsoleAttr(FOREGROUND_YELLOW);
//         } else {
//             txSetConsoleAttr(FOREGROUND_RED);
//         }
//         puts((onegin -> text_compare).ind_mas[str]);
//     }
//     txSetConsoleAttr(FOREGROUND_WHITE);
// }

void OutputWithProcessing(struct Text onegin, FILE* fp) {
    if(fp) {
        for(int str = 0; str < (onegin.orig_text).str_count; ++str) {
            fputs(onegin.text_compare[str].ind_mas, fp);
            fputs("\n", fp);
        }
        fputs("\n", fp);
    }
    fclose(fp);
}

void OutputText(struct Text onegin, FILE* fp) {
    if(fp) {
        fwrite((const char*)(onegin.orig_text).text, onegin.orig_text.text_len, 1, fp);
    }
    fclose(fp);
}