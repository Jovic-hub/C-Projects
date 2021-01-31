//==============================================
// Name:           Joao Victor Fernandes dos Santos
// Student Number: 155858194
// Email:          jvfernandes-dos-sant@myseneca.ca
// Section:        NZZ
// Workshop:       2 (at-home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Paste your in-lab code below and upgrade it to the at-home specifications

#include <stdio.h>
int main(void)
{
	int money, loonies, quarters, dimes, nickles, pennies;				                     //integer variables									     
	double amount, GST;																		 //double variables and the amount as double as requested
	float  amountowing;																	     //Balance owing variable

	printf("Please enter the amount to be paid: $");										//print of the first message

	(void)scanf("%lf", &amount);														  	//scanf for the total amount without GST, lf for double.																													
	GST = amount * .13 + .005;																//calculation for GST as requested
	amountowing = amount + GST;																//amountowing calculation
	money =  amountowing * 100 + 0.5;													  
	

	printf("GST: %.2f\n", GST);
	printf("Balance owing: $%.2f\n", amountowing);											//print of the GST value and amountowing


	loonies = money / 100;
	money = money  % 100;
	printf("Loonies required: %d, balance owing $%.2f\n", loonies, money / 100.0);         //calculation and print of the loonies

	quarters = money / 25;																  
	money = money % 25;
	printf("Quarters required: %d, balance owing $%.2f\n", quarters, money / 100.0);	  //calculation and print of the quarters

	dimes =  money / 10;
	money = money % 10;
	printf("Dimes required: %d, balance owing $%.2f\n", dimes, money / 100.0);			  //calculation and print of the dimes

	nickles =   money / 5;
	money = money % 5;
	printf("Nickels required: %d, balance owing $%.2f\n", nickles, money / 100.0);		  //calculation and print of the nickles

	pennies =   money / 1;
	money = money % 1;
	printf("Pennies required: %d, balance owing $%.2f\n", pennies, money / 100.0);        //calculation and print of the pennies

	return 0;																			  //return control to the operational system.

}
