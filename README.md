# Date-Converter
Program for reading, converting the format of, and storing dates. 

This program consists of two parts- a validator, and a converter. 
The validator reads a sequential list of dates from a file, "dates.dat"(File must be named "dates.dat,"
unless you have modified the code to change the input file name)

This validator program takes one argument from the command line as input. It takes a single integer, denoting
the number of dates that the user would like to print out. If the user would like to print ALL dates, they may input "0"

As the validator reads the dates, it checks to ensure that they are valid dates in the format MM/DD/YYYY.
For example, the date 13/5/2018 would be invalid, because '13' is not a valid month(There are only 12 months in a year).

If the date is valid, it will be printed into stdout(the screen). 

When the validator program has finished running, it will print a signal to indicate is finished. the signal is "Finished"
(Very creative, I know)

The second program, converter, converts the dates output by validator into a DD Month(Abbreviated) YYYY format.
For example, 12/10/2018 would be converted to 10 DEC 2018.

The converter program is designed to take input from the validator via a pipe. It outputs the converted dates into
an output file, "output.txt"

USAGE:

UNIX:
1. unzip all files into the same directory. 
2. Type: "make validator converter" into the command line(command line must be open in this directory)
3. type "./validator [number of dates to output] | converter"
