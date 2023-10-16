#include <stdio.h>
#include <stdlib.h>

#include "board.h"

int main(int argc, char *argv[]) {
  init_all();

  int index = 0;
  for (index = 0; index < BRD_SQ_NUM; ++index) {
    if (index % 10 == 0)
      printf("\n");
    printf("%5d", sq120tosq64[index]);
  }

  printf("\n\n");

  for (index = 0; index < 64; ++index) {
    if (index % 8 == 0)
      printf("\n");
    printf("%5d", sq64tosq120[index]);
  }

  return EXIT_SUCCESS;
}
