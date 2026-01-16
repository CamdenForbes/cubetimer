#include "scramble_gen.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  printf("SCRAMBLE: ");

  char scramble[30][2];
  genScramble(scramble);
  for (int i = 0; i < 20; i++) {
    printf("[");
    for (int j = 0; j < 2; j++) {
      printf("%c", scramble[i][j]);
    }
    printf("]");
  }
  printf("\n");
  return 0;
}
