/**
 *  clockWindow.c - ncurses-clock
 *
 *  This module defines functionality for the ncurses window that draws the clock.
 *  This is the View portion of the MVC pattern. See dateTimeModel for Model and main for
 *  Controller.
 *
 */

#include "clockWindow.h"

static int row, col;                // Dimensions of the window

static void printTime(BlockString *currentTime);
static void printDate(char *currentDate);
static void printUptime(struct timespec* currentUptime);
static void printTimezone();
static int timeOffset();
static void printCommand();

void suspendClock();
void resumeClock();
void clockWait();

/**
 * Initialize the ncurses window for displaying the clock
 */
void initClockWindow() {
    WINDOW *window = initscr();
    start_color();

    //bool hasColors = has_colors();
    //bool canChangeColors = can_change_color();

    init_pair(COLOR_PAIR_WHITE, COLOR_WHITE, COLOR_BLACK);
    init_pair(COLOR_PAIR_GREEN, COLOR_GREEN, COLOR_GREEN);
    wbkgd(window, COLOR_PAIR(COLOR_PAIR_WHITE));

    cbreak();
    noecho();
	curs_set(0);

    clear();
	refresh();
}

/**
 * Clear the window contents and reset the dimensions to handle resizing 
 */
void resetClockWindow() {
	endwin();
    clear();
    getmaxyx(stdscr, row, col);
}

static int timeOffset()
{
    const time_t epoch_plus_11h = 60 * 60 * 11;
	const int local_time = localtime(&epoch_plus_11h)->tm_hour;
	const int gm_time = gmtime(&epoch_plus_11h)->tm_hour;
	const int tz_diff = local_time - gm_time;
	
	return tz_diff;
}

/**
 * Draw the current state of the window 
 */
void updateClockWindow(char *timeBuffer, char *dateBuffer) {
	clockWait();
	struct timespec currentuptime;
    BlockString *testString = initBlockString(timeBuffer);
	
	printTime(testString);
    deleteBlockString(&testString);

    printDate(dateBuffer);
	
	clock_gettime(CLOCK_UPTIME, &currentuptime);
	printUptime(&currentuptime);
	
	printTimezone();
	printCommand();
	
    refresh();
}

/**
 * Delete the window and clean up
 */
void deleteClockWindow() {
	// TODO: add free()?
    curs_set(1);
    clear();
    endwin();
}

/**
 * Prints the current time from the currentTime BlockString
 */ 
static void printTime(BlockString *currentTime) {
    BlockLetter *letter = currentTime->head;
    int x = (col - currentTime->width) / 2 ;

    while (letter != NULL) {
        for (int i=0; i < LETTER_HEIGHT; i++) {
            int y = row / 2 - LETTER_HEIGHT + i;
            char *line = (*letter->glyph)[i];
			int j = 0;
			while ((char)line[j] != 0) {
				if ((char)line[j] != ' ') {
					attron(COLOR_PAIR(COLOR_PAIR_GREEN));
					mvaddch(y, x + j, (char)line[j]);
					attroff(COLOR_PAIR(COLOR_PAIR_GREEN));
				}
				j++;
			}
        }
        x += letter->width + INTER_LETTER_SPACE;
        letter = letter->next;
    }
}

/**
 * Prints the current date from the buffer
 */
static void printDate(char *currentDate) {
    attron(COLOR_PAIR(COLOR_PAIR_WHITE));
    mvprintw(row / 2 + 1, (col - strlen(currentDate)) / 2, "%s", currentDate);
    attroff(COLOR_PAIR(COLOR_PAIR_WHITE));
}

/**
 * Prints the current uptime from the timespec struct
 */
static void printUptime(struct timespec* currentUptime) {
    attron(COLOR_PAIR(COLOR_PAIR_WHITE));
	char buf[64];
	char printtext[64] = "";
	int ut_sec, ut_min, ut_hour, ut_day, n = currentUptime->tv_sec;
	
	ut_day = n / (24 * 3600); 
    n = n % (24 * 3600); 
    ut_hour = n / 3600; 
    n %= 3600; 
    ut_min = n / 60 ; 
    n %= 60; 
    ut_sec = n; 
	
	if (ut_day > 1)
		strcat(printtext, "Uptime %ddays");
	else 
		strcat(printtext, "Uptime %dday");
	if (ut_hour > 1)
		strcat(printtext, " %dhours");
	else 
		strcat(printtext, " %dhour");
	if (ut_min > 1)
		strcat(printtext, " %dmins");
	else
		strcat(printtext, " %dmin");
	if (ut_sec > 1)
		strcat(printtext, " %dsecs");
	else
		strcat(printtext, " %dsec");
	
	snprintf(buf, sizeof(buf), printtext, ut_day, ut_hour, ut_min, ut_sec);
    mvprintw(row / 2 + 3, (col - strlen(buf)) / 2, buf);
    attroff(COLOR_PAIR(COLOR_PAIR_WHITE));
}

/**
 * Prints the current timezone
 */
static void printTimezone() {
    attron(COLOR_PAIR(COLOR_PAIR_WHITE));
    mvprintw(row - 1, col - 6, "GMT+%d", timeOffset());
    attroff(COLOR_PAIR(COLOR_PAIR_WHITE));
}

/**
 * Prints the command line
 */
static void printCommand() {
    attron(COLOR_PAIR(COLOR_PAIR_WHITE));
    mvprintw(row - 1, 0, "Type 'q' to quit, 'c' to type command");
    attroff(COLOR_PAIR(COLOR_PAIR_WHITE));
}

void suspendClock()
{ // tell the thread to suspend
    pthread_mutex_lock(&clock_suspend_mutex);
    clock_suspend_flag = 1;
    pthread_mutex_unlock(&clock_suspend_mutex);
}
void resumeClock()
{ // tell the thread to resume
    pthread_mutex_lock(&clock_suspend_mutex);
    clock_suspend_flag = 0;
    pthread_cond_broadcast(&clock_resume_cond);
    pthread_mutex_unlock(&clock_suspend_mutex);
}
void clockWait()
{ // if suspended, suspend until resumed
    pthread_mutex_lock(&clock_suspend_mutex);
    while (clock_suspend_flag != 0) pthread_cond_wait(&clock_resume_cond, &clock_suspend_mutex);
    pthread_mutex_unlock(&clock_suspend_mutex);
}