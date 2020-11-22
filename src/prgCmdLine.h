/**
 *  prgCmdLine.h - ncurses-clock
 *
 *  This module defines functions for program-integrated command line parser for
 *  several functionalities.
 *
 */

#ifndef PRG_CMD_LINE_H
#define PRG_CMD_LINE_H

#include <assert.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ncurses.h>
#include "clockWindow.h"
#include "dateTimeModel.h"
#include "scanAndConfig.h"

#include "sharedData.h"

#define		CMD_MAXLEN	0x100

/**
 * list add "foo" 0		message set "bar"	time 10		message delete	list del 0	exit		NOP		NOP
 * CMD_ADDLST			CMD_SETMSG			CMD_TIME	CMD_UNSTMSG		CMD_DELLST	CMD_TERM	CMD_NOP	CMD_NOP
 * 0x01					0x11				0x21		0x12			0x02		0xF0		0xFF	0xFF
 * 
 * uint64_t{0xFFFFF00212211101} cmdLineParser(char* /command/, void*[8] {struct listItem* {int {0}, char* {"foo"}}, char* {"bar"}, int* {&10}, NULL, int* {&0}, NULL, NULL, NULL} );
 * 
 * uint64_t cmdLineParser(char* command, void* args[8]);
 */
#define 	CMD_NOP		0x00
#define 	CMD_ERR		0x0E
#define 	CMD_TERM	0x0F

#define		CMD_SETMSG	0x11
#define		CMD_UNSTMSG	0x12

#define		CMD_SETTIME	0x21
#define		CMD_ADDTIME	0x22
#define		CMD_REDTIME	0x23

#define 	CMD_ADDLST	0x31
#define		CMD_DELLST	0x32

/**
 * Reads command line and returns opcode-like return value and args.
 */
uint64_t cmdLineParser(char* command, void* args[8]);

/**
 * Implements ncurses-compatible input control.
 */
void cmdline();

#endif 
