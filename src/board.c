/* Copyright Tanveer Raza
 *
 * Chess Board representation:
 *
 *        a   b   c   d   e   f   g   h
 *      ________________________________
 *    1|  21  22  23  24  25  26  27  28
 *    2|  31  32  33  34  35  36  37  38
 *    3|  41  42  43  44  45  46  47  48
 *    4|  51  52  53  54  55  56  57  58
 *    5|  61  62  63  64  65  66  67  68
 *    6|  71  72  73  74  75  76  77  78
 *    7|  81  82  83  84  85  86  87  88
 *    8|  91  92  93  94  95  96  97  98
 *
 * The board representation ranges between 0-119, the above shown positions
 * represents position on board while others are overflow. All pieces after one
 * move will end up either on legal board position or overflow square.
 *
 *
 *
 *
 *
 *
 *
 *
 */

#ifndef BOARD_H
#define BOARD_H

#include <stdint.h>

#define NAME "CCE 0.1"
// Number of squares in board (including overflow)
#define BRD_SQ_NUM 120

// Maximum number of moves allowed per game
// 2048 half-moves(1024 full moves) should be enough to hold the game.
#define MAXGAMEMOVES 2048

// Represents a single square in board
typedef int brd_sq;
typedef uint64_t piece_pos;
// TODO(tanveerraza789): replace with std impl in C23
typedef _Bool bool;
typedef int64_t ccint;
typedef uint64_t ccuint;

// Uppercase means white, lowercase means black.
// P: Pawn
// N: Knight
// B: Bishop
// R: Rook
// Q: Queen
// K: King
enum cce_piece { EMPTY, P, N, B, R, Q, K, p, n, b, r, q, k };

// Files
enum cce_file {
  FILE_A,
  FILE_B,
  FILE_C,
  FILE_D,
  FILE_E,
  FILE_F,
  FILE_G,
  FILE_H,
  FILE_NONE
};

// Ranks
enum cce_rank {
  RANK_1,
  RANK_2,
  RANK_3,
  RANK_4,
  RANK_5,
  RANK_6,
  RANK_7,
  RANK_8,
  RANK_NONE
};

// Colors
enum cce_color { WHITE, BLACK };

// Castling permission
enum cce_castling {
  // White King castling, King side
  WKCA = 1,
  // White King castling, Queen side
  WQCA = 2,
  // Black King castling, King side
  BKCA = 4,
  // Black King castling, Queen side
  BQCA = 8,
};

// Board address to number mapping
enum cce_board {
  A1 = 21,
  B1,
  C1,
  D1,
  E1,
  F1,
  G1,
  H1,
  A2 = 31,
  B2,
  C2,
  D2,
  E2,
  F2,
  G2,
  H2,
  A3 = 41,
  B3,
  C3,
  D3,
  E3,
  F3,
  G3,
  H3,
  A4 = 51,
  B4,
  C4,
  D4,
  E4,
  F4,
  G4,
  H4,
  A5 = 61,
  B5,
  C5,
  D5,
  E5,
  F5,
  G5,
  H5,
  A6 = 71,
  B6,
  C6,
  D6,
  E6,
  F6,
  G6,
  H6,
  A8 = 81,
  B8,
  C8,
  D8,
  E8,
  F8,
  G8,
  H8,
  NO_SQ,
};

enum { FALSE, TRUE };

typedef struct {
  ccint move;
  ccint castle_perm;
  ccint en_pas;
  ccint fifty_moves;
  ccuint pos_key;
} CCE_UNDO;

// Representation of a board
typedef struct {
  // All pieces on the board
  brd_sq pieces[BRD_SQ_NUM];

  // Position of WHITE, BLACK, BOTH color pawns on board, one u64 holds all
  // pawns positions (makes calc easier)
  // 0: white, 1: Black, 2: Both
  piece_pos pawns[3];

  // Position of kings
  piece_pos kings[2];

  // True for white, False for black. Which side change is it?
  bool side;

  // Any en passant active on the board?
  piece_pos enPas;

  // Keep track of no. of moves, game draws after 50 moves.
  ccint fifty_moves;

  // Check for castling permission
  ccint catle_perm;

  // Current move number
  ccint ply;

  // Last move number
  ccint his_ply;

  // Unique key generated for each position
  ccuint pos_key;

  // Number of pieces of each type from Type enum
  ccint piece_num[13];

  // Number of big pieces (Anything other than pawns)
  // 0: white, 1: Black, 2: Both
  ccint big_piece[3];

  // Number of major pieces (Rooks and Queens)
  // 0: white, 1: Black, 2: Both
  ccint maj_pieces[3];

  // Number of minor pieces (Bishops and Knights)
  // 0: white, 1: Black, 2: Both
  ccint min_pieces[3];

  // Preserve history!
  CCE_UNDO history[MAXGAMEMOVES];
} CCE_BOARD;

#endif /* ifndef BOARD_H */
