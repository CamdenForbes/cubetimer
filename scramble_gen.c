#include "scramble_gen.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void genRandomState(char (*scramble)[2]) {
  char *notation[] = {"R ", "L ", "U ", "D ", "F ", "B "};
  char postfix[] = {' ', '2', '\''};
  srand(time(NULL));

  int rand_i = rand() % 6;
  int prev_i = rand() % 6;
  for (int i = 0; i < 20; i++) {
    while (prev_i == rand_i || prev_i % 2 == 0 && rand_i == prev_i + 1 ||
           prev_i % 2 != 0 && rand_i == prev_i - 1) {
      rand_i = rand() % 6;
    }
    strcpy(scramble[i], notation[rand_i]);
    prev_i = rand_i;
  }

  for (int i = 0; i < 20; i++) {
    rand_i = rand() % 3;
    scramble[i][1] = postfix[rand_i];
  }
}

void genScramble(char (*scramble)[2]) { genRandomState(scramble); }
