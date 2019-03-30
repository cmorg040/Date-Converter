/*=============================================================================
 |   Source code:  validateMain.c
 |        Author:  Carrel Morgan
 |    Student ID:  3759826
 |    Assignment:  Program #5
 |
 |            Course:  COP 4338
 |           Section:  U05
 |        Instructor:  William Feild
 |        Due Date:  03/28/2019, at the beginning of class
 |
 |	I hereby certify that this collective work is my own
 |	and none of it is the work of any other person or entity.
 |	______________________________________ [Signature]
 |
 |     Language:  C
 |  Compile/Run:  Unzip all files.
 |				- type make validator converter
 |				- type ./validator [number of dates to print] | ./converter
 |
 |				Alternatively:
 |				-type gcc -o validator.c converter.c -I.
 |				-type ./validator [number of dates to print] | ./converter
 |
 |  +-----------------------------------------------------------------------------
 |
 |  Description:	Reads a set of dates from a data file.
 |					Validates those dates and prints them to stdout.
 |
 |
 |
 |
 |        Input:	Takes one command line arguments,
 |					-Number of dates to print.
 |
 |
 |
 |       Output:	The program outputs validated dates to stdout.
 |
 |     Process:
 |				1. Validate command line argument
 |				2. Read first date.
 |				3. Validate date.
 |				4. Print date it valid
 |				5. Loop.
 |
 |
 |
 |
 |
 |
 |   Required Features Not Included:
 |               	Program does not account for Leap Years.
 |
 |
 |
 |
 |
 |
 |   Known Bugs:  No known bugs at this time.
 |  *===========================================================================*/

#include "conversions.h"

int main(int argc, char *argv[])
{

	if (validateInput(argv[DATES]) != VALIDATION_SUCCESS)
		{
			return VALIDATION_FAILURE;
		}

	int datesToPrint = atoi(argv[DATES]);
	if (datesToPrint == 0)
		{
			datesToPrint = INT_MAX;
		}

	FILE *datesPtr = NULL;
	if ((datesPtr = fopen("dates.dat", "r")) == NULL)
		{
			printf("Failed top open file: '%s'\n", "dates.dat");
			printErrorMessage(FOPEN_FAILURE);
			return FOPEN_FAILURE;
		}

	printDates(datesPtr, datesToPrint);
	printf("%s", FINISHER);
	fclose(datesPtr);

	return EXIT_SUCCESS;
}

/*---------------------------- printDates ---------------------
 |  Function printDates
 |
 |  Purpose: Prints valid dates to stdout.
 |
 |  @param dates: A file pointer to the dates.dat file.
 |	@param numDates: The number of dates to be printed.
 |
 |  @return  none
 |
 *-------------------------------------------------------------------*/
void printDates(FILE *dates, int numDates)
{
	char tempDate[LINEBUFFER];
	char dateToPrint[LINEBUFFER];
	int dateCounter = 0;
	while (!feof(dates) && (dateCounter < numDates))
		{
			fgets(tempDate, LINEBUFFER, dates);
//			printf("Date to be validated: %s\n", tempDate);
			strcpy(dateToPrint, tempDate);
			if (validateDate(tempDate))
				{
					printf("%s\n", dateToPrint);
					dateCounter++;
				}
		}
}

/*---------------------------- validateDate ---------------------
 |  Function validateDate
 |
 |  Purpose: validates a single date.
 |
 |  @param dates: The date to be validated
 |
 |  @return true if the date is valid, false otherwise.
 |
 *-------------------------------------------------------------------*/
bool validateDate(char *date)
{

	char *month = strtok(date, DATE_DELIMITER);
	char *day = strtok(NULL, DATE_DELIMITER);
	char *year = strtok(NULL, DATE_DELIMITER);

	if (validateMonth(month) && validateYear(year)
			&& validateDay(day, month, year))
		{
			return true;
		}

	return false;
}

/*---------------------------- isInteger ---------------------
 |  Function isInteger
 |
 |  Purpose: Ensures that a string contains integer characters only.
 |
 |  @param dates: The string to be validated
 |
 |  @return true if the string is an integer, false otherwise.
 |
 *-------------------------------------------------------------------*/
bool isInteger(char *aString)
{

	int strIter = 0;
	bool validFlag = true;
	if (aString[strIter] == '-')
		{
			strIter++;
		}
	while (aString[strIter] != END_OF_STRING && aString[strIter] != NEWLINE)
		{
			if (aString[strIter] < ASCII_ZERO || aString[strIter] > ASCII_NINE)
				{
					validFlag = false;
				}
			strIter++;
		}
	return validFlag;
}

/*---------------------------- validateMonth ---------------------
 |  Function validateMonth
 |
 |  Purpose: Ensures that a month string is valid.
 |
 |  @param month: The month to be validated
 |
 |  @return true if the month is valid, false otherwise.
 |
 *-------------------------------------------------------------------*/
bool validateMonth(char *month)
{
	if (month == NULL)
		{
			return false;
		}

	int monthInt = 0;
	if (isInteger(month))
		{
			monthInt = atoi(month);
		}
	else
		{
			return false;
		}
	if (monthInt < January || monthInt > December)
		{
			return false;
		}
	return true;
}

/*---------------------------- validateYear ---------------------
 |  Function validateYear
 |
 |  Purpose: Ensures that a year string is valid.
 |
 |  @param year: The year to be validated
 |
 |  @return true if the year is valid, false otherwise.
 |
 *-------------------------------------------------------------------*/
bool validateYear(char *year)
{
	if (year == NULL)
		{
			return false;
		}

	long yearLong = 0;
	if (isInteger(year))
		{
			sscanf(year, "%ld", &yearLong);
		}
	else
		{
			return false;
		}
	if (yearLong < MIN_YEAR || yearLong > MAX_YEAR)
		{
			return false;
		}
	return true;
}

/*---------------------------- validateDay ---------------------
 |  Function validateDay
 |
 |  Purpose: Ensures that a day string is valid.
 |
 |  @param day: The day to be validated
 |  @param month: the month of the year, to determine the day's range.
 |  @param year: The year, to check for possible leap years.
 |
 |  @return true if the day is valid, false otherwise.
 |
 *-------------------------------------------------------------------*/
bool validateDay(char *day, char *month, char *year)
{
	int monthInt = atoi(month);
	int yearInt = atoi(year);
	if (day == NULL)
		{
			return false;
		}
	int dayInt = 0;
	if (isInteger(day))
		{
			sscanf(day, "%d", &dayInt);
		}
	else
		{
			return false;
		}
	if (monthInt == January || monthInt == March || monthInt == May
			|| monthInt == July || monthInt == August || monthInt == October
			|| monthInt == December)
		{
			if (dayInt >= FIRST_DAY && dayInt <= THIRTY_ONE_DAYS)
				{
					return true;
				}
		}
	else if (monthInt == April || monthInt == June || monthInt == September
			|| monthInt == November)
		{
			if (dayInt >= FIRST_DAY && dayInt <= THIRTY_DAYS)
				{
					return true;
				}
		}
	else if (monthInt == February)
		{
			if (dayInt == LEAP_DAY)
				{
					if ((yearInt % 4 == 0) && ((yearInt % 400 == 0)
							|| (yearInt % 100 != 0)))
						{

						}
				}
			if (dayInt >= FIRST_DAY && dayInt <= TWENTY_EIGHT_DAYS)
				{
					return true;
				}
		}
	return false;
}

/*---------------------------- validateInput ---------------------
 |  Function validateInput
 |
 |  Purpose: Validates user command line input.
 |
 |  @param datesToPrint: The number of dates the progrma should print.
 |
 |  @return returns an error or success code.
 |
 *-------------------------------------------------------------------*/
const int validateInput(char *datesToPrint)
{
	if (strcmp(datesToPrint, STRING_ZERO) == 0)
		{
			return VALIDATION_SUCCESS;
		}

	int stringIterator = 0;
	while (datesToPrint[stringIterator] != END_OF_STRING)
		{
			if (datesToPrint[stringIterator] < ASCII_ZERO
					|| datesToPrint[stringIterator] > ASCII_NINE)
				{
					printErrorMessage(VALIDATION_FAILURE);
					return VALIDATION_FAILURE;
				}
			stringIterator++;
		}

	int input = 0;
	input = atoi(datesToPrint);

	if (input == 0)
		{
			return VALIDATION_FAILURE;
		}
	else
		{
			return VALIDATION_SUCCESS;
		}
}

/*---------------------------- printErrorMessage ---------------------
 |  Function printErrorMessage
 |
 |  Purpose: Prints an appropriate error message based on received code.
 |
 |  @param errorCode: An integer value to determine what type of error occurred.
 |
 |  @return none
 |
 *-------------------------------------------------------------------*/
void printErrorMessage(int errorCode)
{
	if (errorCode == VALIDATION_FAILURE)
		{
			puts("Validation failure.\n");
			puts(
					"Please input a non-negative integer number of dates to print.");
			printf("\nTo print ALL dates, input %d\n", PRINT_ALL);
		}
	if (errorCode == FOPEN_FAILURE)
		{
			puts("Failed to open file");
		}
}

