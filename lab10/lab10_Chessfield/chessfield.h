#ifndef C2026_2027_CHESSFIELD_H
#define C2026_2027_CHESSFIELD_H
#include <stdbool.h>
typedef struct Chessfield_ {
    char hor;
    char vert;
} Chessfield;
void printChessfield(Chessfield c);
bool inputChessfield(Chessfield *c);
bool queen_square_check(Chessfield *c);

#endif //C2026_2027_CHESSFIELD_H