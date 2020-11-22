/**
 *  sharedData.h - ncurses-clock
 *
 *  This module defines functionality for program-integrated command line parser for
 *  several functionalities.
 *
 */

#ifndef SHARED_DATA_H
#define SHARED_DATA_H

#include <pthread.h>

pthread_mutex_t clock_suspend_mutex;
pthread_cond_t clock_resume_cond;
int clock_suspend_flag;

#endif