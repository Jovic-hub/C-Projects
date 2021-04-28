
#define _CRT_SECURE_NO_WARNINGS

// Put your code below:
#define NUMS 4
#include <stdio.h>
int main(void)
{
	int high, low, i, h_day, l_day, highest, lowest;								//Every int that i used to do the code
	float mean, low_mean, high_mean;																//floats that i used.
																									
	l_day = 0;
	h_day = 0;
	lowest = 41;												//Value for the variables, lowest and highest to get the biggest temperatures.
	highest = -41;
	high = 0;
	low = 0;
	mean = 0;
	low_mean = 0;
	high_mean = 0;
	
	printf("---=== IPC Temperature Analyzer ===---");		// print of the first message						

	for (i = 1; i <= NUMS; i++) {									//to start the loop using for		

		do {
			printf("\nEnter the high value for day %d: ", i);							
			scanf("%d", &high);

			printf("\nEnter the low value for day %d: ", i);							
			scanf("%d", &low);

			if (high >= 41 || low <= -41 || high < low) {		//defining the range of high and low

				printf("\nIncorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");
				//if user put something outside of this range, this messa will appear.
			}		
		} while (high >= 41 || low <= -41 || high < low); //while means the final of the loop, if he got the enough results the loop is done.

		if (highest < high) {
			h_day = i;
			highest = high;
		}				// Calculation of the highest and lowest temperature, this means getting the biggest high and lowest low and founding which day this is.
		if (lowest > low) {
			l_day = i;
			lowest = low;			//
		}

		low_mean = low_mean + low;			//I created low mean and high mean to do the calculation of the average only of the low, equal as int mean, but with only one number.
		high_mean = high_mean + high;
		mean = mean + (high + low);	 // mean is the all average, getting low and high together.
		

	}low_mean = low_mean / (NUMS); // calculation of the low_mean, basically all of the lows divided by the number of days, the same i did with high_mean.
	printf("\nThe average (mean) LOW temperature was: %.2f\n", low_mean);

	high_mean = high_mean / (NUMS);
	printf("The average (mean) HIGH temperature was: %.2f\n", high_mean);
	
	mean = mean / (NUMS * 2);	//calculation of the total mean, this means low + high, after divided by the number of days is necessary to multiply by two cause we are using two differente numbers.
	printf("The average (mean) temperature was: %.2f\n", mean);			

	printf("The highest temperature was %d, on day %d\n", highest, h_day);
	printf("The lowest temperature was %d, on day %d", lowest, l_day);
	//print of the highest and lowest temperature.
	return 0;
}
