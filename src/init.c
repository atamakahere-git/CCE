#ifndef INIT_C
#define INIT_C

#include "board.h"

int sq120tosq64[BRD_SQ_NUM];
int sq64tosq120[64];

void init_sq120tosq64() {
  int index = 0;
  int file = FILE_A;
  int rank = RANK_1;
  int sq = A1;
  int sq64 = 0;

  for (index = 0; index < BRD_SQ_NUM; ++index) {
    sq120tosq64[index] = 65;
  }

  for (index = 0; index < 120; ++index) {
    sq64tosq120[index] = 120;
  }

  for (rank = RANK_1; rank <= RANK_8; ++rank) {
    for (file = FILE_A; file <= FILE_H; ++file) {
      sq = FR2SQ(file, rank);
      sq64tosq120[sq64] = sq;
      sq120tosq64[sq] = sq64;
      sq64++;
    }
  }
}

void init_all() { init_sq120tosq64(); }

#endif /* ifndef INIT_C */
