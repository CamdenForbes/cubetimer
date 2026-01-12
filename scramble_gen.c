#include "scramble_gen.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void genMoves(char (*scramble)[2]) {
  char *notation[] = {"R ", "R'", "L ", "L'", "U ", "U'",
                      "D ", "D'", "B ", "B'", "F ", "F'"};
  srand(time(NULL));
  int prev_i = rand() % 12;
  int rand_i;
  for (int i = 0; i < 30; i++) {
    rand_i = rand() % 12;
    while ((rand_i % 2 == 1 && rand_i == prev_i + 1) ||
           (rand_i % 2 == 0 &&
            rand_i == prev_i - 1)) { // prevent moves that cancel
      rand_i = rand() % 12;
    }

    strcpy(scramble[i], notation[rand_i]);
    prev_i = rand_i;
  }
}

void cleanScramble(char (*scramble)[2]) {}

void genScramble(char (*scramble)[2]) { genMoves(scramble); }
