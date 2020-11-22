/**
 *  prgCmdLine.c - ncurses-clock
 *
 *  This module defines functionality for program-integrated command line parser for
 *  several functionalities.
 *
 */
 
#include "prgCmdLine.h"

uint64_t cmdLineParser(char* command, void* args[8]);
char** str_split(char* a_str, const char a_delim, int* count);
void trimblank(char* str);
void freestrlist(char** strlist);
void str2lc(char* str);
void cmdline();

uint64_t cmdLineParser(char* command, void* args[8]) {
	char** commands;
	uint64_t opcode = 0;
	int cmdcount = 0;
	
	str2lc(command);
	
	if (strcmp(command, "") != 0) {
		
		commands = str_split(command, ';', &cmdcount);
		
		for (int i = 0; i < cmdcount; i++) {
			if (commands[i] != NULL) {
				trimblank(commands[i]);
				
				int subcmdcount = 0;
				char** subcommands = NULL;
				subcommands = str_split(commands[i], ' ', &subcmdcount);
				
				if (strcmp(subcommands[0], "list") == 0) {
					if (strcmp(subcommands[1], "add") == 0) {
						mvprintw(1, i * 8, "ADDLST");
						opcode = opcode << 8;
						opcode += CMD_ADDLST;
					} else if (strcmp(subcommands[1], "del") == 0) {
						mvprintw(1, i * 8, "DELLST");
						opcode = opcode << 8;
						opcode += CMD_DELLST;
					} else {
						mvprintw(1, i * 8, "ERR");
						opcode = opcode << 8;
						opcode += CMD_ERR;
					}
				} else if (strcmp(subcommands[0], "message") == 0) {
					if (strcmp(subcommands[1], "set") == 0) {
						mvprintw(1, i * 8, "SETMSG");
						opcode = opcode << 8;
						opcode += CMD_SETMSG;
					} else if (strcmp(subcommands[1], "unset") == 0) {
						mvprintw(1, i * 8, "UNSTMSG");
						opcode = opcode << 8;
						opcode += CMD_UNSTMSG;
					} else {
						mvprintw(1, i * 8, "ERR");
						opcode = opcode << 8;
						opcode += CMD_ERR;
					}
				} else if (strcmp(subcommands[0], "timer") == 0) {
					if (strcmp(subcommands[1], "set") == 0) {
						mvprintw(1, i * 8, "SETTIME");
						opcode = opcode << 8;
						opcode += CMD_SETTIME;
					} else if (strcmp(subcommands[1], "add") == 0) {
						mvprintw(1, i * 8, "ADDTIME");
						opcode = opcode << 8;
						opcode += CMD_ADDTIME;
					} else if (strcmp(subcommands[1], "reduce") == 0) {
						mvprintw(1, i * 8, "REDTIME");
						opcode = opcode << 8;
						opcode += CMD_REDTIME;
					} else {
						mvprintw(1, i * 8, "ERR");
						opcode = opcode << 8;
						opcode += CMD_ERR;
					}
				} else if (strcmp(subcommands[0], "exit") == 0) {
					mvprintw(1, i * 8, "TERM");
					opcode = opcode << 8;
					opcode += CMD_TERM;
				} else {
					mvprintw(1, i * 8, "ERR");
					opcode = opcode << 8;
					opcode += CMD_ERR;
				}
				freestrlist(subcommands);
			}
		}
		freestrlist(commands);
	}
		
	mvprintw(2, 0, "\nReturned : 0x%016lX\n", opcode);
	
	return opcode;
}

void str2lc(char* str) {
	for(char *p = str; *p; ++p)
		*p = *p > 0x40 && *p < 0x5b ? *p | 0x60 : *p;
}

void trimblank(char* str) {
	int blankcount = 0;
	
	while(str[blankcount] == ' ') {
		blankcount++;
	}
	
	for (int i = blankcount; i < strlen(str) + 1; i++) {
		str[i - blankcount] = str[i];
	}
	
	blankcount = 0;
	
	while(str[strlen(str) - blankcount - 1] == ' ') {
		blankcount++;
	}
	
	str[strlen(str) - blankcount] = 0;
}

void freestrlist(char** strlist) {
	free(strlist[0]);
	free(strlist);
}

char** str_split(char* a_str, const char a_delim, int* count)
{
    char** result    = 0;
	char* modstr = malloc((strlen(a_str) + 1) * sizeof(char));
	int delimcount = 0;

    strcpy(modstr, a_str);
	
	for (int i = 0; i != strlen(modstr); i++) {
		if (modstr[i] == a_delim) 
			delimcount++;
	}
	
	delimcount++;
	
	result = malloc(delimcount * sizeof(char*));
	result[0] = modstr;
	
	for (int j = 1, i = 0; i != strlen(a_str); i++) {
		if (modstr[i] == a_delim) {
			modstr[i] = 0;
			result[j] = &modstr[i + 1];
			j++;
		}
	}
	
	
	*count = delimcount;

    return result;
}

void cmdline() {	
	suspendClock();
	attron(COLOR_PAIR(COLOR_PAIR_WHITE));
	
	clear();
	curs_set(1);
	echo();
	
	
	char* command = malloc(CMD_MAXLEN * sizeof(char));
	memset(command, 0, CMD_MAXLEN * sizeof(char));
	
	if (getnstr(command, CMD_MAXLEN - 1) == OK ) {
		cmdLineParser(command, NULL);
	}
	refresh();
	sleep(10);
	
	free(command);
	noecho();
	curs_set(0);
	attroff(COLOR_PAIR(COLOR_PAIR_WHITE));
	resumeClock();
	return;
}

