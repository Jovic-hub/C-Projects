
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Define Number of Employees "SIZE" to be 4
#define SIZE 4

// Declare Struct Employee S
struct employee {
	int id;
	int age;
	double salary;
};

/* main program */
int main(void)
{
	int i = 0;
	int option = 0;
	int current_employee = 0;
	int employee_count = 0;
	int search_id = 0; // int to search the id as the name says.
	int found = -1; // int to save the found results.
	int found_index = 0; 

	// Declare a struct Employee array "emp" with SIZE elements 
	// and initialize all elements to zero
	struct employee emp[SIZE] = { {0} };

	printf("---=== EMPLOYEE DATA ===---\n\n");

	do
	{
		// Print the option list
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("3. Update Employee\n");				// case 3 and 4 .
		printf("4. Remove Employee\n");
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
				if (emp[i].id > 0 && emp[i].age > 0) {
					printf("%6d%9d%11.2lf\n", emp[i].id, emp[i].age, emp[i].salary); // printf statement to display
				}
			}
			printf("\n");
			break;
		case 2:	// Adding Employee
				// @IN-LAB
			printf("Adding Employee\n");
			printf("===============\n");

			if (current_employee >= SIZE || employee_count >= SIZE) {
				printf("ERROR!!! Maximum Number of Employees Reached\n"); // when users puts more employees than 4 this message will appear.
				printf("\n");
				break;
			}

			// Check for limits on the array and add employee 
			// data accordingly. 
			do {
				printf("Enter Employee ID: ");					// asking to the user puts the employee id to register.
				scanf("%d", &emp[current_employee].id);
			} while (emp[current_employee].id < 1);

			do {
				printf("Enter Employee Age: ");					// askikng to the user puts the employee age to register.
				scanf("%d", &emp[current_employee].age);
			} while (emp[current_employee].age < 1);

			do {
				printf("Enter Employee Salary: ");				// askikng to the user puts the employee salary to register.
				scanf("%lf", &emp[current_employee].salary);
				printf("\n");
			} while (emp[current_employee].salary < 1);

			current_employee++;

			if (employee_count <= SIZE) {				// I created the employee_count variable to keep tracking the number of the employees in the company.
				employee_count++;						// if the number of employees surpasses the variable size, the message error will appear,
			}											// when you try to add a new employee if the max number is already reached.

			break;

		case 3:  
			
			printf("Update Employee Salary\n");		//printf of the message of the update of the salary
			printf("======================\n");

			do {  
				printf("Enter Employee ID: ");  // The user right here needs to put an employee that he registered before in the case 2
				scanf("%d", &search_id);		// if he puts a employee that is not registered a message error will appear.
	
				for (i = 0; i < SIZE; i++) { 
					if (emp[i].id == search_id) {  
						found = i;  
						found_index = i;  
					}   
				}  

				if (found >= 0) { 
					printf("The Current Salary is: %.2lf", emp[found_index].salary);		// print of the current salary of the employee that he puts.
					printf("\n");
					printf("Enter Employee New Salary: ");				// asking for the user the new salary to sucefully update the employee salary.
					scanf("%lf", &emp[found_index].salary);  
					printf("\n");
					found = -1;								// important to use found = 0 and found_index = 0 to our finding tool don't accumulate numbers and no problem happen
					found_index = 0;  
					break;  
				}
				else {  
					printf("***ERROR: Employee ID not found!***");  // error message.
					printf("\n");   
				}  
			} while (found == -1); 

			break;   

		case 4:

			printf("Remove Employee\n");		// print of the message of the remove of the employee
			printf("===============\n");

			do {  
				printf("Enter Employee ID: ");  // asking for the user the ID of the employee that he wants to remove.
				scanf("%d", &search_id);  

				for (i = 0; i < SIZE; i++) {  
					if (emp[i].id == search_id) {  
						found = i;  
						found_index = i;  
					}  
				}  

				if (found >= 0) {   
					printf("Employee %d will be removed", search_id);  
					printf("\n");  
					printf("\n");

					emp[found_index].id = 0;		//The way that I'm using to remove the employee is deleting his informations 
					emp[found_index].age = 0;		//in the previous cases, so is putting everything in 0
					emp[found_index].salary = 0;	//in this way he will be completely removed from the list.
					found = -1; 
					current_employee = found_index;
					found_index = 0; 
					employee_count --;
					
					break;  
				}
				else {  
					printf("***ERROR: Employee ID not found!***");	// if the user puts a ID that don't exists this error message will appear.
					printf("\n"); 
				}  
			} while (found == -1); 

		

			break;

		default:
			printf("ERROR: Incorrect Option: Try Again\n\n"); // if the user puts something outside from the options 0 to 4 will appear this error message.
		}

	} while (option != 0);

	printf("Exiting Employee Data Program. Good Bye!!!"); // if users puts the option 0 the program will finish.
	return 0;
}




// PROGRAM OUTPUT IS SHOW BELOW

/*
---=== EMPLOYEE DATA ===---

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 5

ERROR: Incorrect Option: Try Again

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 222
Enter Employee Age: 22
Enter Employee Salary: 22222.22

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 333
Enter Employee Age: 33
Enter Employee Salary: 33333.33

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 444
Enter Employee Age: 44
Enter Employee Salary: 44444.44

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 555
Enter Employee Age: 55
Enter Employee Salary: 55555.55

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
ERROR!!! Maximum Number of Employees Reached

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
222       22   22222.22
333       33   33333.33
444       44   44444.44
555       55   55555.55

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 3

Update Employee Salary
======================
Enter Employee ID: 123
*** ERROR: Employee ID not found! ***
Enter Employee ID: 321
*** ERROR: Employee ID not found! ***
Enter Employee ID: 333
The current salary is 33333.33
Enter Employee New Salary: 99999.99

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
222       22   22222.22
333       33   99999.99
444       44   44444.44
555       55   55555.55

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 4

Remove Employee
===============
Enter Employee ID: 789
*** ERROR: Employee ID not found! ***
Enter Employee ID: 987
*** ERROR: Employee ID not found! ***
Enter Employee ID: 333
Employee 333 will be removed

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
222       22   22222.22
444       44   44444.44
555       55   55555.55

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 666
Enter Employee Age: 66
Enter Employee Salary: 66666.66

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
222       22   22222.22
666       66   66666.66
444       44   44444.44
555       55   55555.55

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 0

Exiting Employee Data Program. Good Bye!!!

*/
