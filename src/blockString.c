/**
 *  asciiArtString.c - ncurses-clock
 *
 *  This module creates and manages strings of ASCII art block letters
 *
 */

#include "blockString.h"

/**
 * Initializes a BlockLetter struct that includes an ASCII art glyph representation of the input char.
 * A string of BlockLetters can be formed by linking as linked list.
 */
BlockLetter *initBlockLetter(char inputLetter, BlockLetter *next){
    BlockLetter *blockLetter = malloc(sizeof(BlockLetter));

    blockLetter->height = LETTER_HEIGHT;
    blockLetter->width = LETTER_WIDTH - 1;
    blockLetter->next = next;

    switch (inputLetter) {
        case 'A':
            blockLetter->glyph = &BLOCK_LETTER_A;
            break;
		case 'B':
            blockLetter->glyph = &BLOCK_LETTER_B;
            break;
		case 'C':
            blockLetter->glyph = &BLOCK_LETTER_C;
            break;
		case 'D':
            blockLetter->glyph = &BLOCK_LETTER_D;
            break;
		case 'E':
            blockLetter->glyph = &BLOCK_LETTER_E;
            break;
		case 'F':
            blockLetter->glyph = &BLOCK_LETTER_F;
            break;
		case 'G':
            blockLetter->glyph = &BLOCK_LETTER_G;
            break;
		case 'H':
            blockLetter->glyph = &BLOCK_LETTER_H;
            break;
		case 'I':
            blockLetter->glyph = &BLOCK_LETTER_I;
            break;
		case 'J':
            blockLetter->glyph = &BLOCK_LETTER_J;
            break;
		case 'K':
            blockLetter->glyph = &BLOCK_LETTER_K;
            break;
		case 'L':
            blockLetter->glyph = &BLOCK_LETTER_L;
            break;
        case 'M':
            blockLetter->glyph = &BLOCK_LETTER_M;
            break;
        case 'N':
            blockLetter->glyph = &BLOCK_LETTER_N;
            break;
        case 'O':
            blockLetter->glyph = &BLOCK_LETTER_O;
            break;
        case 'P':
            blockLetter->glyph = &BLOCK_LETTER_P;
            break;       
        case 'Q':
            blockLetter->glyph = &BLOCK_LETTER_Q;
            break;
        case 'R':
            blockLetter->glyph = &BLOCK_LETTER_R;
            break;
        case 'S':
            blockLetter->glyph = &BLOCK_LETTER_S;
            break;
        case 'T':
            blockLetter->glyph = &BLOCK_LETTER_T;
            break;
        case 'U':
            blockLetter->glyph = &BLOCK_LETTER_U;
            break;
        case 'V':
            blockLetter->glyph = &BLOCK_LETTER_V;
            break;
        case 'W':
            blockLetter->glyph = &BLOCK_LETTER_W;
            break;
        case 'X':
            blockLetter->glyph = &BLOCK_LETTER_X;
            break;
        case 'Y':
            blockLetter->glyph = &BLOCK_LETTER_Y;
            break;
        case 'Z':
            blockLetter->glyph = &BLOCK_LETTER_Z;
            break;
		case 'a':
            blockLetter->glyph = &BLOCK_LETTER_SA;
            break;
		case 'b':
            blockLetter->glyph = &BLOCK_LETTER_SB;
            break;
		case 'c':
            blockLetter->glyph = &BLOCK_LETTER_SC;
            break;
		case 'd':
            blockLetter->glyph = &BLOCK_LETTER_SD;
            break;
		case 'e':
            blockLetter->glyph = &BLOCK_LETTER_SE;
            break;
		case 'f':
            blockLetter->glyph = &BLOCK_LETTER_SF;
            break;
		case 'g':
            blockLetter->glyph = &BLOCK_LETTER_SG;
            break;
		case 'h':
            blockLetter->glyph = &BLOCK_LETTER_SH;
            break;
		case 'i':
            blockLetter->glyph = &BLOCK_LETTER_SI;
            break;
		case 'j':
            blockLetter->glyph = &BLOCK_LETTER_SJ;
            break;
		case 'k':
            blockLetter->glyph = &BLOCK_LETTER_SK;
            break;
		case 'l':
            blockLetter->glyph = &BLOCK_LETTER_SL;
            break;
        case 'm':
            blockLetter->glyph = &BLOCK_LETTER_SM;
            break;
        case 'n':
            blockLetter->glyph = &BLOCK_LETTER_SN;
            break;
        case 'o':
            blockLetter->glyph = &BLOCK_LETTER_SO;
            break;
        case 'p':
            blockLetter->glyph = &BLOCK_LETTER_SP;
            break;       
        case 'q':
            blockLetter->glyph = &BLOCK_LETTER_SQ;
            break;
        case 'r':
            blockLetter->glyph = &BLOCK_LETTER_SR;
            break;
        case 's':
            blockLetter->glyph = &BLOCK_LETTER_SS;
            break;
        case 't':
            blockLetter->glyph = &BLOCK_LETTER_ST;
            break;
        case 'u':
            blockLetter->glyph = &BLOCK_LETTER_SU;
            break;
        case 'v':
            blockLetter->glyph = &BLOCK_LETTER_SV;
            break;
        case 'w':
            blockLetter->glyph = &BLOCK_LETTER_SW;
            break;
        case 'x':
            blockLetter->glyph = &BLOCK_LETTER_SX;
            break;
        case 'y':
            blockLetter->glyph = &BLOCK_LETTER_SY;
            break;
        case 'z':
            blockLetter->glyph = &BLOCK_LETTER_SZ;
            break;
        case '0':
            blockLetter->glyph = &BLOCK_LETTER_0;
            break;
        case '1':
            blockLetter->glyph = &BLOCK_LETTER_1;
            break;
        case '2':
            blockLetter->glyph = &BLOCK_LETTER_2;
            break;
        case '3':
            blockLetter->glyph = &BLOCK_LETTER_3;
            break;
        case '4':
            blockLetter->glyph = &BLOCK_LETTER_4;
            break;
        case '5':
            blockLetter->glyph = &BLOCK_LETTER_5;
            break;
        case '6':
            blockLetter->glyph = &BLOCK_LETTER_6;
            break;
        case '7':
            blockLetter->glyph = &BLOCK_LETTER_7;
            break;
        case '8':
            blockLetter->glyph = &BLOCK_LETTER_8;
            break;
        case '9':
            blockLetter->glyph = &BLOCK_LETTER_9;
            break;
        case '.':
            blockLetter->glyph = &BLOCK_LETTER_PERIOD;
            break;
		case ',':
            blockLetter->glyph = &BLOCK_LETTER_COMMA;
            break;
        case ':':
            blockLetter->glyph = &BLOCK_LETTER_COLON;
            break;
        case '!':
            blockLetter->glyph = &BLOCK_LETTER_EXCL;
            break;
        case ' ':
            blockLetter->glyph = &BLOCK_LETTER_SPACE;
            break;
        default:
            blockLetter->glyph = &BLOCK_LETTER_ERROR;
    }

    return blockLetter;
}

/**
 * Delete a BlockLetter and free the associated memory
 */
void deleteBlockLetter(BlockLetter **letterRef) {
    free(*letterRef);
    *letterRef = NULL;
}

/**
 * Initialize a BlockString struct. Produces a linked list of BlockLetters based on the input string.
 */
BlockString *initBlockString(char *inputString) {
    BlockString *newString = malloc(sizeof(BlockString));

    newString->height = 0;
    newString->width = 0;
    BlockLetter *current = NULL;
    char c;

    int len = strlen(inputString) - 1;
    for (int i = len; i >= 0; i--) {
        c = inputString[i];
        current = initBlockLetter(c, current);
        newString->width += current->width + INTER_LETTER_SPACE;
    }

    newString->head = current;
    return newString;    
}

/**
 * Delete a BlockString and free the associated memory
 */
void deleteBlockString(BlockString **stringRef) {
    BlockString *string = *stringRef;

    BlockLetter *toDelete = string->head;
    BlockLetter *current = string->head->next;
    if (toDelete != NULL) {
        deleteBlockLetter(&toDelete);
    }

    while(current != NULL) {
        toDelete = current;
        current = current->next;
        deleteBlockLetter(&toDelete);
    }

    free(string);
    string = NULL;
}

