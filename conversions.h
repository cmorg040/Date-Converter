//Header file for dateConversion

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

#define NUM_CMD_ARGS 2	//First arg is the execution command, second is the number of dates.

#define VALIDATION_SUCCESS 10
#define VALIDATION_FAILURE 11

#define FOPEN_SUCCESS 20
#define FOPEN_FAILURE 21

#define DATES 1

#define STRING_ZERO "0"
#define ASCII_ZERO '0'
#define ASCII_NINE '9'
#define END_OF_STRING '\0'
#define NEWLINE '\n'
#define FINISHER "Finished\n"

#define DATE_DELIMITER "/"

#define PRINT_ALL 0

#define MIN_NUM_DATES 0
#define MAX_NUM_DATES 1000	//arbitrary max number of dates. Change to a reasonable number.

#define ARGS_IN_DATE 3

#define MAX_YEAR INT_MAX	//Not sure what he wants here.
#define MIN_YEAR INT_MIN

#define MINMONTH 1
#define MAXMONTH 12

#define FIRST_DAY 1
#define TWENTY_EIGHT_DAYS 28
#define LEAP_YEAR_DAYS 29
#define THIRTY_DAYS 30
#define THIRTY_ONE_DAYS 31
#define LEAP_DAY 29

#define LINEBUFFER 100

enum months {
	January = 1,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	November,
	December
};

static char *MONTHSABV[13] =
	{ " ", "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV",
			"DEC" };

struct date {
	int day;
	int month;
	long year;
};
typedef struct date Date;

const int validateInput(char *datesToPrint);
void printDates(FILE *dates, int numDates);
const int openFile(FILE *fileToOpen, char *fileName);
bool validateDate(char *date);

bool isInteger(char *aString);
bool validateMonth(char *month);
bool validateDay(char *day, char *month, char *year);
bool validateYear(char *year);
bool checkCharacters(char *aString);

void printErrorMessage(int errorCode);

void waitForSignal();
void convertDate(char *date, FILE *outPtr);
