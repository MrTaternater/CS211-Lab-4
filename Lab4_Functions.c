// Includes header details in header file
#include "Lab4.h"

//-----------------------------------------------------------------------------
// Function Name: InitializeVariables
// Description: Obtains all integer variables from the main and initializes
// them as 0.
//
//-----------------------------------------------------------------------------
void InitializeVariables(int *oddCounter, int *evenCounter, int *oddAccumulator, 
		int *evenAccumulator, int *counter)
{
	// Initialize data
    *oddCounter = 0;
    *evenCounter = 0;
    *oddAccumulator = 0;
    *evenAccumulator = 0;

    // Initialize LCV (Loop Control Variable) to 0
	*counter = 0;
}

//-----------------------------------------------------------------------------
// Function Name: PrintDividerStar
// Description: Prints a line of 110 stars as a divider to the screen.
//
//
//-----------------------------------------------------------------------------
void PrintDividerStar(int *counter, FILE *pOutputFile)
{
	// Initialize LCV (Loop Control Variable) to 0
	*counter = 0;
	
	// Print a bunch of symbols across the screen
	while (*counter < DIVIDER_LENGTH)
	{
		// Print one character to the screen
		fprintf(pOutputFile, "%c", STAR);

		// Increment counter
		(*counter)++;
	}
	// Move the cursor down to the next line
	fprintf(pOutputFile, "\n");
}

//-----------------------------------------------------------------------------
// Function Name: PrintDividerDash
// Description: Prints a line of 110 dashes as a divider to the screen.
//
//
//-----------------------------------------------------------------------------
void PrintDividerDash(int *counter, FILE *pOutputFile)
{
	// Initialize LCV (Loop Control Variable) to 0
	*counter = 0;
	
	// Print a bunch of symbols across the screen
	while (*counter < DIVIDER_LENGTH)
	{
		// Print one character to the screen
		fprintf(pOutputFile, "%c", DASH);

		// Increment counter
		(*counter)++;
	}
	
	// Move the cursor down to the next line
	fprintf(pOutputFile, "\n");
}

//-----------------------------------------------------------------------------
// Function Name: PrintHeader
// Description: Prints the standard header, including the school name, lab name 
// and programmer name to the screen.
//
//-----------------------------------------------------------------------------
void PrintHeader(FILE *pOutputFile)
{
	// Print header to the screen
    fprintf(pOutputFile, SCHOOL);
    fprintf(pOutputFile, LAB);
    fprintf(pOutputFile, PROGRAMMER);
}

//-----------------------------------------------------------------------------
// Function Name: PrintTableHeader
// Description: Prints the table header, including the current number, number 
// counters and accumulator numbers to the screen.
//
//-----------------------------------------------------------------------------
void PrintTableHeader(FILE *pOutputFile)
{
	// Print Header to the screen
	fprintf(pOutputFile, "%18s%22s%22s%22s%22s\n", NUMBER, ODD_COUNTER, EVEN_COUNTER, 
				TOTAL_ODD_NUMBERS, TOTAL_EVEN_NUMBER);
}

//-----------------------------------------------------------------------------
// Function Name: UpdateVariables
// Description: Collects data from each row of the number file and changes the
// counters and accumulators to match. Then calls function to print data.
//
//-----------------------------------------------------------------------------
void UpdateVariables(int *number, int *evenCounter, int *evenAccumulator,
		int *oddCounter, int *oddAccumulator, FILE *pInputFile, FILE *pOutputFile)
{
	while (fscanf(pInputFile, "%d", &(*number)) == 1)
    {
        // Check to see if number is even
        if ((*number % 2) == 0)
        {
            // Increase evenCounter by 1
            (*evenCounter)++;

            // Add number to the even accumulator
            (*evenAccumulator) += *number; 
        }
        else
        {
            // Increase oddCounter by 1
            (*oddCounter)++;

            // Add number to the odd accumulator 
            (*oddAccumulator) += *number;
        }
		PrintRowOfData(number, evenCounter, evenAccumulator,
			oddCounter, oddAccumulator, pInputFile, pOutputFile);
    }
}

//-----------------------------------------------------------------------------
// Function Name: PrintRowOfData
// Description: Prints the updated data of the program's variables for a single
// line of the number file.
//
//-----------------------------------------------------------------------------
void PrintRowOfData(int *number, int *evenCounter, int *evenAccumulator,
		int *oddCounter, int *oddAccumulator, FILE *pInputFile, FILE *pOutputFile)
{
        // Print one row of data
		fprintf(pOutputFile, "%18d%22d%22d%22d%22d\n", *number, *oddCounter, 
					*evenCounter, *oddAccumulator, *evenAccumulator);
}

//-----------------------------------------------------------------------------
// Function Name: CalculateAverage
// Description: Calculates the average value of numbers given the counter and
// accumulator of either odd or even numbers.
//
//-----------------------------------------------------------------------------
double CalculateAverage(int *counter, int *accumulator)
{
	// Set the default value for the average
    double average = 0;
	
    if (counter != 0)
    {
		// Calculate average
		// Cast the accumulator to a double to retain decimals
		average = (double)*accumulator / *counter;
    }
	
	return average;
}

//-----------------------------------------------------------------------------
// Function Name: PrintAverages
// Description: Prints the average values for both the odd and even numbers.
//
//
//-----------------------------------------------------------------------------
void PrintAverages(double *oAverage, double *eAverage, FILE *pOutputFile)
{
	// Print the odd average to the screen
	fprintf(pOutputFile, "Average odd number: %0.2lf\n", *oAverage);
	
	// Print the even average to the screen
	fprintf(pOutputFile, "Average even number: %0.2lf\n", *eAverage);
}

