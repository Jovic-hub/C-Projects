//==============================================
// Name:           Joao Victor Fernandes dos Santos
// Student Number: 155858194
// Email:          jvfernandes-dos-sant@myseneca.ca
// Section:        NZZ
// Workshop:       4 (at-home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// Place your code below

int main(void)
{
	
	double mean;  //high and low with array 10, cause 10 is the biggest number as possible that the user can put, i did 20 in the lab part, but doesn't matter.
	int high[10], low[10], i, nums, highest, lowest, l_day, h_day, l_total, h_total, day;
	highest = 0;
	lowest = 0;



	printf("---=== IPC Temperature Calculator V2.0 ===---\n");                   //print of the first message

	printf("Please enter the number of days, between 3 and 10, inclusive: ");			//asking for the user to put the number of days that he want
	scanf("%d", &nums);  //scanf of the number of days
	printf("\n");

	while (nums < 3 || nums > 10) {

		printf("Invalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &nums);  //while the user don't put a number inside of the range, this error message will appear

	}

	printf("\n");
	for (i = 0; i < nums; i++) {
		printf("Day %d - High: ", i + 1);
		scanf("%d", &high[i]);				//first loop asking for the user every temperature that he wants to put
		printf("Day %d - Low: ", i + 1);	// i + 1 only visual tool for the terminal to get the correct number
		scanf("%d", &low[i]);
	}

	printf("\n");
	printf("Day  Hi  Low\n");
	for (i = 0; i < nums; i++) {
		printf("%d", i + 1);			//print of the vertical days and temperatures that the user puts
		printf("    %d", high[i]);
		printf("    %d\n", low[i]);

	}
	printf("\n");


	for (i = 0; i < nums; i++) {

		if (highest <= high[i]) {
			highest = high[i];
			h_day = i + 1;				//lowest and highest temperature, getting the day and the biggest number that the user puts 

		}
		else if(lowest >= low[i]){
			lowest = low[i];
			l_day = i + 1;
		}

	}
	printf("The highest temperature was %d, on day %d\n", highest, h_day);	
	//printf of the lowest and highest and what day is it
	printf("The lowest temperature was %d, on day %d\n", lowest, l_day);		

	printf("\n");

	do {			//asking for the user the number based on the number of days that he put, so if he puts 5 days temperature will be 1 to 5 days that he needs to put here.
		printf("Enter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", nums);
		scanf("%d", &day);
		printf("\n");					//printf and scanf of the number 1 to %d that the user puts

		if (day < 0) {						// if the user put a negative number the goodbye will be printed and the program will finish.

			printf("Goodbye!\n");
			break;					//break to get out of the do while loop.

		}
		
		while (day > nums || day == 0) {		//while the user put something outside of the range the invalid entry message will appear
			printf("Invalid entry, please enter a number between 1 and %d, inclusive: ", nums);
			scanf("%d", &day);
			printf("\n");
		}  

		h_total = 0;			// we need this to the number don't accumulate
		l_total = 0;

		for(i = 0; i < day; i++){
			h_total += high[i];						//getting the highest and lowest number of that day and dividing by the day and multiplying by 2
			l_total += low[i];						// *2 is used cause we are using two different numbers

		}
		
		mean = (double) (h_total + l_total) / (day * 2); // average/mean calculator


		printf("The average temperature up to day %d is: %.2lf\n", day, mean);
		printf("\n");			//printf of the mean of the temperature. %.2lf cause mean is in double and we need more than decimal numbers.
		


	} while (day <= nums && day > 0);				//finish of the loop
	


	return 0;			
}