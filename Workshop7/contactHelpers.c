

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the functions you prototyped
// in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:

#include "contactHelpers.h"
//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+


// Clear the standard input buffer
void clearKeyboard(void)
{
    while (getchar() != '\n')   ; // empty execution code block on purpose
}


// pause: function definition goes here:
void pause(void)
{
    printf("(Press Enter to Continue)");
    clearKeyboard();
        
}


// getInt: function definition goes here:
int getInt(void)
{
    int value;
    char NL = 'x';

    scanf("%d%c", &value, &NL);

    while (NL != '\n') {

        clearKeyboard();
        printf("*** INVALID INTEGER *** <Please enter an integer>: ");
        scanf("%d%c", &value, &NL);
    }
    return value;
}


// getIntInRange: function definition goes here:
int getIntInRange(int min, int max)
{
    int range = getInt();

    while (range < min || range > max) {

        printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
        range = getInt();
    }
    return range;
}


// yes:function definition goes here:
int yes(void)
{
    char null = 0, yes_no = 0;
    int input = 0;

    scanf("%c%c", &yes_no, &null);

    while (((yes_no != 'Y') && (yes_no != 'y') && (yes_no != 'n') && (yes_no != 'N')) || (null != '\n')) {

        clearKeyboard();
        printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
        scanf("%c%c", &yes_no, &null);


    }


    if ((yes_no == 'N') || (yes_no == 'n')) {
        input = 0;
    }


    else if ((yes_no == 'Y') || (yes_no == 'y')) {
        input = 1;
    }


    return input;
}


// menu:function definition goes here:
int menu(void)
{
    printf("Contact Management System\n");
    printf("-------------------------\n");
    printf("1. Display contacts\n");
    printf("2. Add a contact\n");
    printf("3. Update a contact\n");
    printf("4. Delete a contact\n");
    printf("5. Search contacts by cell phone number\n");
    printf("6. Sort contacts by cell phone number\n");
    printf("0. Exit\n");

    printf("\nSelect an option:> ");

    return getIntInRange(0, 6);
}


// contactManagerSystem: function definition goes here:
void contactManagerSystem(void)
{

    int selection;
    int select;

    do {

        selection = menu();

            if (selection == 0) {

                printf("\n");
                printf("Exit the program? (Y)es/(N)o: ");
                select = yes();
                printf("\n");
                    if (select == 1) {
                        printf("Contact Management System: terminated\n");
                        return;
                    }

            }

            else if (selection == 1) {
                printf("\n<<< Feature 1 is unavailable >>>\n");
                printf("\n");
                pause();
                printf("\n");
            }

            else if (selection == 2) {
                printf("\n<<< Feature 2 is unavailable >>>\n");
                printf("\n");
                pause();
                printf("\n");
            }

            else if (selection == 3) {
                printf("\n<<< Feature 3 is unavailable >>>\n");
                printf("\n");
                pause();
                printf("\n");
            }

            else if (selection == 4) {
                printf("\n<<< Feature 4 is unavailable >>>\n");
                printf("\n");
                pause();
                printf("\n");
            }

            else if (selection == 5) {
                printf("\n<<< Feature 5 is unavailable >>>\n");
                printf("\n");
                pause();
                printf("\n");
            }

            else if (selection == 6) {
                printf("\n<<< Feature 6 is unavailable >>>\n");
                printf("\n");
                pause();
                printf("\n");
            }

            else if ((selection < 0) || (selection > 6)) {
            printf("*** OUT OF RANGE *** <Enter a number between 0 and 6>: ");

            }


    } while (selection >= 0 || selection <= 6);

    return;

}
