/**
 *  font.h - ncurses-clock
 *
 *  This module defines font data for clock.
 *
 */

#ifndef SHARED_DATA_H
#define SHARED_DATA_H

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const size_t LETTER_HEIGHT = 7;
static const size_t LETTER_WIDTH  = 7;
static const size_t INTER_LETTER_SPACE = 1;

typedef char GlyphMatrix[7][7];

GlyphMatrix BLOCK_LETTER_A;
GlyphMatrix BLOCK_LETTER_B;
GlyphMatrix BLOCK_LETTER_C;
GlyphMatrix BLOCK_LETTER_D;
GlyphMatrix BLOCK_LETTER_E;
GlyphMatrix BLOCK_LETTER_F;
GlyphMatrix BLOCK_LETTER_G;
GlyphMatrix BLOCK_LETTER_H;
GlyphMatrix BLOCK_LETTER_I;
GlyphMatrix BLOCK_LETTER_J;
GlyphMatrix BLOCK_LETTER_K;
GlyphMatrix BLOCK_LETTER_L;
GlyphMatrix BLOCK_LETTER_M;
GlyphMatrix BLOCK_LETTER_N;
GlyphMatrix BLOCK_LETTER_O;
GlyphMatrix BLOCK_LETTER_P;
GlyphMatrix BLOCK_LETTER_Q;
GlyphMatrix BLOCK_LETTER_R;
GlyphMatrix BLOCK_LETTER_S;
GlyphMatrix BLOCK_LETTER_T;
GlyphMatrix BLOCK_LETTER_U;
GlyphMatrix BLOCK_LETTER_V;
GlyphMatrix BLOCK_LETTER_W;
GlyphMatrix BLOCK_LETTER_X;
GlyphMatrix BLOCK_LETTER_Y;
GlyphMatrix BLOCK_LETTER_Z;
GlyphMatrix BLOCK_LETTER_SA;
GlyphMatrix BLOCK_LETTER_SB;
GlyphMatrix BLOCK_LETTER_SC;
GlyphMatrix BLOCK_LETTER_SD;
GlyphMatrix BLOCK_LETTER_SE;
GlyphMatrix BLOCK_LETTER_SF;
GlyphMatrix BLOCK_LETTER_SG;
GlyphMatrix BLOCK_LETTER_SH;
GlyphMatrix BLOCK_LETTER_SI;
GlyphMatrix BLOCK_LETTER_SJ;
GlyphMatrix BLOCK_LETTER_SK;
GlyphMatrix BLOCK_LETTER_SL;
GlyphMatrix BLOCK_LETTER_SM;
GlyphMatrix BLOCK_LETTER_SN;
GlyphMatrix BLOCK_LETTER_SO;
GlyphMatrix BLOCK_LETTER_SP;
GlyphMatrix BLOCK_LETTER_SQ;
GlyphMatrix BLOCK_LETTER_SR;
GlyphMatrix BLOCK_LETTER_SS;
GlyphMatrix BLOCK_LETTER_ST;
GlyphMatrix BLOCK_LETTER_SU;
GlyphMatrix BLOCK_LETTER_SV;
GlyphMatrix BLOCK_LETTER_SW;
GlyphMatrix BLOCK_LETTER_SX;
GlyphMatrix BLOCK_LETTER_SY;
GlyphMatrix BLOCK_LETTER_SZ;
GlyphMatrix BLOCK_LETTER_0;
GlyphMatrix BLOCK_LETTER_1;
GlyphMatrix BLOCK_LETTER_2;
GlyphMatrix BLOCK_LETTER_3;
GlyphMatrix BLOCK_LETTER_4;
GlyphMatrix BLOCK_LETTER_5;
GlyphMatrix BLOCK_LETTER_6;
GlyphMatrix BLOCK_LETTER_7;
GlyphMatrix BLOCK_LETTER_8;
GlyphMatrix BLOCK_LETTER_9;
GlyphMatrix BLOCK_LETTER_PERIOD;
GlyphMatrix BLOCK_LETTER_COMMA;
GlyphMatrix BLOCK_LETTER_COLON;
GlyphMatrix BLOCK_LETTER_EXCL;
GlyphMatrix BLOCK_LETTER_SPACE;
GlyphMatrix BLOCK_LETTER_ERROR;

#endif