/*=============================================================================
 |   Source code:  converterMain.c
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
 |				Note: "-I" flag included for header compatitbility.
 |
 |  +-----------------------------------------------------------------------------
 |
 |  Description:	Reads a set of dates from stdin
 |					converts the dates, then prints them to an output file.
 |
 |
 |
 |
 |        Input:	Input piped from validateMain.c
 |
 |
 |
 |       Output:	The program outputs converted dates to output.txt
 |
 |     Process:
 |				1. Read date from stdin
 |				2. convert date
 |				3. write date to output.txt
 |				4. repeat until FINISHER is reached.
 |
 |
 |
 |
 |
 |
 |   Required Features Not Included:
 |               	All required featuers should be included.
 |
 |
 |
 |
 |
 |
 |   Known Bugs:  No known bugs at this time.
 |  *===========================================================================*/

#include "conversions.h"

int main(void)
{
	FILE *outPtr = NULL;
	if ((outPtr = fopen("output.txt", "w")) == NULL)
		{
			printf("Failed top open file: '%s'\n", "dates.dat");
			return FOPEN_FAILURE;
		}
	char readDate[LINEBUFFER];
	fgets(readDate, LINEBUFFER, stdin);
	while (strcmp(readDate, FINISHER) != 0) //While nextLine is not equal to finisher
		{
			convertDate(readDate, outPtr);
			fgets(readDate, LINEBUFFER, stdin);
		}
	fclose(outPtr);
}

/*---------------------------- convertDate ---------------------
 |  Function convertDate
 |
 |  Purpose: COnverts an input date into DAY MONTH YEAR
 |
 |  @param date: The date to be converted.
 |
 |  @return  none
 |
 *-------------------------------------------------------------------*/
void convertDate(char *date, FILE *outFile)
{
	if (date[0] != NEWLINE && (strcmp(date, FINISHER) != 0))
		{
			char *month = strtok(date, DATE_DELIMITER);
			char *day = strtok(NULL, DATE_DELIMITER);
			char *year = strtok(NULL, DATE_DELIMITER);
			fprintf(outFile, "%s ", day);
			fprintf(outFile, "%s ", MONTHSABV[atoi(month)]);
			fprintf(outFile, "%s\n", year);

		}
}
