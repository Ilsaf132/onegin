#ifndef OUTPUT_
#define OUTPUT_

#include <stdio.h>

#include "Struct.h"

const char output_straight[] = "Normal output\n";
const char output_reverse[] = "Reverse output\n";
const char output_text[] = "Original Text\n";

void OutputText(struct Text onegin, FILE* fp);
void OutputWithProcessing(struct Text onegin, FILE* fp);
void IterationOfOutput(struct Text onegin, const char output_mode[],
                        void (*Output)(struct Text onegin, FILE* fp));

#endif