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
  int prev_prev_i = rand() % 12;
  int rand_i;
  for (int i = 0; i < 20; i++) {
    rand_i = rand() % 12;
    while (cleanScramble(prev_prev_i, prev_i, rand_i)) {
      rand_i = rand() % 12;
    }

    strcpy(scramble[i], notation[rand_i]);
    prev_i = rand_i;
  }
}

bool cleanScramble(int prev_prev_i, int prev_i, int rand_i) {
  char *notation[] = {"R ", "R'", "L ", "L'", "U ", "U'",
                      "D ", "D'", "B ", "B'", "F ", "F'"};
  // Prevent Cancelling Moves
  if ((rand_i % 2 == 1 && rand_i == prev_i + 1) ||
      (rand_i % 2 == 0 && rand_i == prev_i - 1)) {
    return true;
  }
  // Prevent Moves That Convert to '
  if (prev_prev_i == prev_i && prev_i == rand_i) {

    return true;
  }
  // Prevent Back To Back Opposite Rotation
  if ((rand_i == 0 || rand_i == 1 || rand_i == 4 || rand_i == 5 ||
       rand_i == 8 || rand_i == 9) &&
      (prev_i == rand_i + 2)) {
    return true;
  } else if ((rand_i == 2 || rand_i == 3 || rand_i == 6 || rand_i == 7 ||
              rand_i == 10 || rand_i == 11) &&
             (prev_i == rand_i - 2)) {
    return true;
  }
  return false;
}
void genScramble(char (*scramble)[2]) { genMoves(scramble); }
