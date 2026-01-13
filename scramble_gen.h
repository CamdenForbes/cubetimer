#ifndef SCRAMBLE_GEN
#define SCRAMBLE_GEN
#include <stdbool.h>
void genScramble(char (*arr)[2]);
bool cleanScramble(int prev_prev_i, int prev_i, int rand_i);
void genMoves(char (*arr)[2]);

#endif
