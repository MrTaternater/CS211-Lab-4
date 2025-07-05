// Includes header details in header file
#include "Lab4.h"

int main(void)
{
 
	// Declares all program int variables
    int number;
    int oddCounter;
    int evenCounter;
    int oddAccumulator;
    int evenAccumulator;
    int counter;

	// Declares all program double variables
    double oddAverage;
	double evenAverage;

	// Creates an input and output file
    FILE * pInputFile;
    FILE * pOutputFile;

    // Open the files
    pInputFile = fopen("Numbers.txt", "r");
    pOutputFile = fopen("Lab4Output.txt", "w");
	
	// Runs the InitializeVariables function to initialize all variables
	InitializeVariables(&oddCounter, &evenCounter, &oddAccumulator, 
		&evenAccumulator, &counter);

    // Print Star Divider
	PrintDividerStar(&counter, pOutputFile);

	// Print standard header to the screen
	PrintHeader(pOutputFile);

	// Print a bunch of symbols across the screen
	PrintDividerStar(&counter, pOutputFile);
	
	// Print table header to the screen
	PrintTableHeader(pOutputFile);
 
    // Primer for file processing loop and prints data to output file
	UpdateVariables(&number, &evenCounter, &evenAccumulator,
		&oddCounter, &oddAccumulator, pInputFile, pOutputFile);
		
	// Print a bunch of symbols across the screen
	PrintDividerDash(&counter, pOutputFile);
	
	// Calculate the average for the odd numbers
	oddAverage = CalculateAverage(&oddCounter, &oddAccumulator);

	// Calculate the average for the even numbers
    evenAverage = CalculateAverage(&evenCounter, &evenAccumulator);
	
	// Print result for both average numbers
	PrintAverages(&oddAverage, &evenAverage, pOutputFile);
	
	// Print a bunch of symbols across the screen
	PrintDividerDash(&counter, pOutputFile);

    // Close files
    fclose(pInputFile);
	fclose(pOutputFile);

	// Returns 0 to end main
	return 0;

}

