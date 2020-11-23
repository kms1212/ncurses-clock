/**
 *  clockWindow.h - ncurses-clock
 *
 *  This module defines functionality for the ncurses window that draws the clock.
 *  This is the View portion of the MVC pattern. See dateTimeModel for Model and main for
 *  Controller.
 *
 */

#ifndef CLOCK_WINDOW_H
#define CLOCK_WINDOW_H

#include <string.h>
#include <ncurses.h>
#include <pthread.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include "blockString.h"
#include "prgCmdLine.h"

#include "sharedData.h"

#define _POSIX_C_SOURCE 199309L

static int row, col;

extern pthread_mutex_t clock_suspend_mutex;
extern pthread_cond_t clock_resume_cond;
extern int clock_suspend_flag;

static const enum ColorPairType {   // Pairs of colors available for drawing
    COLOR_PAIR_WHITE = 0,
    COLOR_PAIR_GREEN = 1
} ColorPairs;        

/**
 * Initialize the ncurses window for displaying the clock
 */
void initClockWindow();

/**
 * Clear the window contents and reset the dimensions to handle resizing 
 */
void resetClockWindow();

/**
 * Draw the current state of the window 
 */
void updateClockWindow(char *timeBuffer, char *dateBuffer);

/**
 * Delete the window and clean up
 */
void deleteClockWindow();

void suspendClock();
void resumeClock();
void clockWait();

#endif 
