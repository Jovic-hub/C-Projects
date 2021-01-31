//==============================================
// Name:           Joao Victor Fernandes dos Santos
// Student Number: 155858194
// Email:          jvfernandes-dos-sant@myseneca.ca
// Section:        NZZ
// Workshop:       5 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


// Define Number of Employees "SIZE" to be 2
#define SIZE 2

// Declare Struct Employee S
struct employee {
	int id;					//int id as requested
	int age;				// int age as requested
	double salary;			// salary in double as requested
};

/* main program */
int main(void)
{
	int i = 0;
	int option = 0;
	int current_employee = 0;


	// Declare a struct Employee array "emp" with SIZE elements 
	// and initialize all elements to zero
	struct employee emp[SIZE] = { {0} };

	printf("---=== EMPLOYEE DATA ===---\n\n");

	do
	{
		// Print the option list
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");

		// Capture input to option variable
		scanf("%d", &option);
		printf("\n");

		switch (option)
		{
		case 0:	// Exit the program
			break;
		case 1: // Display Employee Data
			// @IN-LAB
			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");

			for (i = 0; i <= SIZE; i++) {
				if (emp[i].id >= 0 && emp[i].age >= 0) { //print of printf"%6d%9d%11.2lf" as requested
					printf("%6d%9d%11.2lf\n", emp[i].id, emp[i].age, emp[i].salary); // printf statement to display
				}
			}
			printf("\n");
			break;
		case 2:	// Adding Employee
				// @IN-LAB
			printf("Adding Employee\n");
			printf("===============\n");

			if (current_employee >= SIZE) {
				printf("ERROR!!! Maximum Number of Employees Reached\n");
				printf("\n");
				break;
			}

			// Check for limits on the array and add employee 
			// data accordingly. 
			do {
				printf("Enter Employee ID: ");
				scanf("%d", &emp[current_employee].id);
			} while (emp[current_employee].id < 1);

			do {
				printf("Enter Employee Age: ");
				scanf("%d", &emp[current_employee].age);
			} while (emp[current_employee].age < 1);
			//%d for age and id and %lf for salary
			do {
				printf("Enter Employee Salary: ");
				scanf("%lf", &emp[current_employee].salary);
				printf("\n");
			} while (emp[current_employee].salary < 1);

			current_employee++;

			break;

		default:
			printf("ERROR: Incorrect Option: Try Again\n\n");
		}

	} while (option != 0); // while the user puts something differente than 0 the code will still running. 

	printf("Exiting Employee Data Program. Good Bye!!!");
	return 0;
}

//PROGRAM OUTPUT IS SHOW BELOW

/*
---=== EMPLOYEE DATA ===---

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 111
Enter Employee Age: 34
Enter Employee Salary: 78980.88

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 112
Enter Employee Age: 41
Enter Employee Salary: 65000

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
ERROR!!! Maximum Number of Employees Reached

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
   111       34   78980.88
   112       41   65000.00

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 0

Exiting Employee Data Program. Good Bye!!!

*/

