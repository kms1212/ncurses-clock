/**
 *  scanAndConfig.c - ncurses-clock
 *
 *  This module scans input arguments to produce a configuration struct
 *
 */

#include "scanAndConfig.h"

static void printUsage();
static void printHelp();
static ProgramConfig *initProgramConfig();
static void deleteProgramConfig(ProgramConfig *configRef);


/**
 * Scans program arguments and sets up the configuration struct
 */
ProgramConfig *scanArguments(int argc, char *argv[]) {
    ProgramConfig *config = initProgramConfig();

    config->use24h = false;
    config->secsOff = false;

    bool hourModeSet = false;
    bool hourModeConflict = false;
    bool secModeSet = false;
    bool secModeConflict = false;
    bool unknownArg = false;
			
	struct winsize wsize;
	
	if (argc < 2) {
		ioctl(STDOUT_FILENO, TIOCGWINSZ, &wsize);
		if (wsize.ws_col < 80) {
			hourModeSet = true;
			config->use24h = true;
		}
		if (wsize.ws_col < 55) {
			secModeSet = false;
			config->secsOff = true;
		}
		return config;
	}

    int i;
    for (i = 1; i < argc; i++) {
		if ((strcmp(argv[i], "--12h") == 0) || (strcmp(argv[i], "-t") == 0)) {
            if (hourModeSet && config->use24h) {
                hourModeConflict = true;
                break;
            } else {
                hourModeSet = true;
                config->use24h = false;
            }
        } else if ((strcmp(argv[i], "--24h") == 0) || (strcmp(argv[i], "-o") == 0)) {
            if (hourModeSet && !config->use24h) {
                hourModeConflict = true;
                break;
            } else {
                hourModeSet = true;
                config->use24h = true;
            }
        } else if ((strcmp(argv[i], "--secs=on") == 0) || (strcmp(argv[i], "-s") == 0)) {
            if (secModeSet && config->secsOff) {
                secModeConflict = true;
                break;
            } else {
                secModeSet = true;
                config->secsOff = false;
            }
        } else if ((strcmp(argv[i], "--secs=off") == 0) || (strcmp(argv[i], "-m") == 0)) {
            if (secModeSet && !config->secsOff) {
                secModeConflict = true;
                break;
            } else {
                secModeSet = true;
                config->secsOff = true;
            }
        } else if ((strcmp(argv[i], "--help") == 0) || (strcmp(argv[i], "-h") == 0)) {
            config->shouldExit = true;
            printHelp();
        } else if ((strcmp(argv[i], "--auto") == 0) || (strcmp(argv[i], "-a") == 0)) {
            config->use24h = false;
			config->secsOff = false;
		
			hourModeSet = false;
			hourModeConflict = false;
			secModeSet = false;
			secModeConflict = false;
			
			ioctl(STDOUT_FILENO, TIOCGWINSZ, &wsize);
			if (wsize.ws_col < 80) {
				hourModeSet = true;
				config->use24h = true;
			}
			if (wsize.ws_col < 55) {
				secModeSet = false;
				config->secsOff = true;
			}
        } else {
            unknownArg = true;
            break;
        }
    }

    if (unknownArg) {
        config->shouldExit = true;
        config->exitCode = 1;
        printUsage();
        fprintf(stderr, "clock: unrecognized option '%s'\n", argv[i]);
    } else if (hourModeConflict) {
        config->shouldExit = true;
        config->exitCode = 1;
        printUsage();
        fprintf(stderr, "clock: Conflicting arguments for time mode (12h, 24h)\n");
    } else if (secModeConflict) {
        config->shouldExit = true;
        config->exitCode = 1;
        printUsage();
        fprintf(stderr, "clock: Conflicting arguments for seconds display mode (12h, 24h)\n");
    }

    return config;
}

/**
 * Prints a usage of the program
 */
static void printUsage() {
    printf(
	"Usage : clock [--auto, -a] [--12h, -t] [--24h, -o] [--secs=on, -s] [--secs=off, -m] [--help, -h]"
	"\n"
	"\n"
	"For more information on available options see 'clock --help"
	"\n"
	);
}

/**
 * Prints a short description of the program and lists the usage options
 */
static void printHelp() {
    printf(
    "\n"
    "ncurses-clock -- draws a clock in the terminal window using the ncurses library\n"
    "\n"
	"Usage : clock [--auto, -a] [--12h, -t] [--24h, -o] [--secs=on, -s] [--secs=off, -m] [--help, -h]\n"
    "options supported:\n"
    "    --auto, -a         Display time with variable formats controlled by console size (default)\n"
	"                       (Other options are aborted if this option is set from command line)\n"
    "    --12h, -t          Use 12-hour clock mode\n"
    "    --24h, -o          Use 24-hour clock mode\n"
    "    --secs=on, -s      Display time including seconds\n"
    "    --secs=off, -m     Display time without seconds\n"
    "    --help, -h         Show this help message\n"
    "\n"
    );
}

/**
 * Intializes a program configuration struct
 */
static ProgramConfig *initProgramConfig() {
    ProgramConfig *config = malloc(sizeof(ProgramConfig));

    config->shouldExit = false;
    config->exitCode = 0;
    config->use24h = false;

    return config;
}

/**
 * Deletes a program configuration struct and frees memory
 */
static void deleteProgramConfig(ProgramConfig *config) {
	free(config);
	config = NULL;
}