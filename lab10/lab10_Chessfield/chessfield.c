#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "chessfield.h"

void printChessfield(Chessfield c) {
    if (c.vert==0||c.vert>8) {
        printf("incorrect vertical %hhu", c.vert);
    }
    c.hor=toupper(c.hor);
    if (c.hor<'A'||c.hor>'H') {
        printf("incorrect horizontal %c", c.hor);
    }
    else {
        printf("%c%hhu", c.hor, c.vert);
    }
}

bool inputChessfield(Chessfield *c) {
    printf("\nInput your field : ");
    char h;
    unsigned char v;
    int r=scanf(" %c%hhu", &h, &v);
    if (r!=2) {
        printf("incorrect format");
        return false;
    }
    if (v==0||v>8) {
        printf("incorrect vertical %hhu", v);
        return false;
    }
    h=toupper(h);
    if (h<'A'||h>'H') {
        printf("incorrect horizontal %c", h);
        return false;
    }
    c->hor=h;
    c->vert=v;
    return true;
}
bool queen_square_check(Chessfield *c) {
    Chessfield q;
    printf("\ninput the queen position (horizont and vertical): ");
    inputChessfield(&q);
    int row_diff = abs(q.vert - c->vert);
    int col_diff = abs(q.hor - c->hor);
    if (q.hor == c->hor || q.vert == c->vert || row_diff == col_diff) {
        return true;
    }
    return false;
}