// Defines header file if not already defined
#ifndef LAB4_H
#define LAB4_H

#endif

// Include for printing to the screen
#include <stdio.h>

// Macro for divider length
#define DIVIDER_LENGTH 110

// Macros for divider types
#define STAR '*'
#define DASH '-'

// Macros for standard header details
#define SCHOOL "Binghamton University\n"
#define LAB "Lab 4 - Playing With Numbers\n"
#define PROGRAMMER "Program Written by: Tate Wishrad\n"

// Macros for table header details
#define NUMBER "Current Number"
#define ODD_COUNTER "Odd Number Counter"
#define EVEN_COUNTER "Even Number Counter"
#define TOTAL_ODD_NUMBERS "Total Odd Number"
#define TOTAL_EVEN_NUMBER "Total Even Number"

// Prototypes listed below
void testStuff(FILE *pOutputFile);

void InitializeVariables(int *oddCounter, int *evenCounter, int *oddAccumulator, 
		int *evenAccumulator, int *counter);
		
void PrintDividerStar(int *counter, FILE *pOutputFile);

void PrintDividerDash(int *counter, FILE *pOutputFile);

void PrintHeader(FILE *pOutputFile);

void PrintTableHeader(FILE *pOutputFile);

void UpdateVariables(int *number, int *evenCounter, int *evenAccumulator,
		int *oddCounter, int *oddAccumulator, FILE *pInputFile, FILE *pOutputFile);
		
void PrintRowOfData(int *number, int *evenCounter, int *evenAccumulator,
		int *oddCounter, int *oddAccumulator, FILE *pInputFile, FILE *pOutputFile);
		
double CalculateAverage(int *counter, int *accumulator);

void PrintAverages(double *oAverage, double *eAverage, FILE *pOutputFile);
