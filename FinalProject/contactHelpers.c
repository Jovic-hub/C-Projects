//==============================================
// Name:           Joao Victor Fernandes dos Santos
// Student Number: 155858194
// Email:          jvfernandes-dos-sant@myseneca.ca
// Section:        NZZ
// Date:           12/01/2020
//==============================================
// Assignment:     2
// Milestone:      4
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        contents below...                        |
// +-------------------------------------------------+

#include <stdio.h>
#include <string.h>
#include "contacts.h"
#include "contactHelpers.h"
#include <ctype.h>

#define MAXCONTACTS 5

void clearKeyboard(void)
{
    while (getchar() != '\n'); // empty execution code block on purpose
}


// pause: function definition goes here:
void pause(void)
{
    printf("(Press Enter to Continue)");
    clearKeyboard();
    printf("\n");

}


// getInt: function definition goes here:
int getInt(void)
{
    int value;
    char NL = 'x';
    int keep_trying = 1;
                                                                            // Hi moona, you said in the feedback that my GetInt was incomplete
                                                                            // I Tried my best to do it int the best way as possible
    do {                                                                    // if is wrong yet let me know, thank you.
        scanf("%d%c", &value, &NL);

        if (NL == '\n') {
            keep_trying = 0;
        } else {
            clearKeyboard();
            printf("*** INVALID INTEGER *** <Please enter an integer>: ");
        }
    } while (keep_trying == 1);

     


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
    char null = 0;
    char yes_no = 0;
    int input = 0;
    int keep_trying = 1;


    do{
        scanf("%c%c", &yes_no, &null);

        if ((yes_no == 'Y' || yes_no == 'y' || yes_no == 'N' || yes_no == 'n') && null == '\n') {
            keep_trying = 0;
        } else {
            clearKeyboard();
            printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
        }

    } while (keep_trying == 1);
     

    if ((yes_no == 'N') || (yes_no == 'n')) {
        input = 0;
    }
    else {
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

    struct Contact contacts[MAXCONTACTS]=

        { { { "Rick", {'\0'}, "Grimes" },
            { 11, "Trailer Park", 0, "A7A 2J2", "King City" },
            { "4161112222", "4162223333", "4163334444" } },
        {
            { "Maggie", "R.", "Greene" },
            { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
            { "9051112222", "9052223333", "9053334444" } },
        {
            { "Morgan", "A.", "Jones" },
            { 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
            { "7051112222", "7052223333", "7053334444" } },
        {
            { "Sasha", {'\0'}, "Williams" },
            { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
            { "9052223333", "9052223333", "9054445555" } },
        };

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
            
            displayContacts(contacts, MAXCONTACTS);
            printf("\n");
            pause();
        }

        else if (selection == 2) {
            addContact(contacts, MAXCONTACTS);
            pause();

        }

        else if (selection == 3) {

            updateContact(contacts, MAXCONTACTS);
            pause();

        }

        else if (selection == 4) {

            deleteContact(contacts, MAXCONTACTS);
            pause();

        }

        else if (selection == 5) {

            searchContacts(contacts, MAXCONTACTS);
            pause();

        }

        else if (selection == 6) {
            printf("\n<<< Feature to sort is unavailable >>>\n");
            printf("\n");
            pause();
        }

        else{
            getIntInRange(0, 6);

        }


    } while (selection >= 0 || selection <= 6);

    return;

}

void getTenDigitPhone(char phoneNum[])
{
    int i;
    scanf("%10s", phoneNum);
    clearKeyboard();

    for (i = 0; i < strlen(phoneNum); i++) {

        if (isdigit(phoneNum[i]) == 0 || strlen(phoneNum) != 10){
            
            printf("Enter a 10-digit phone number: ");
            scanf("%10s", phoneNum);
            clearKeyboard();

            i = -1;
        }

    }

}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{   
    int i;
    int find = -1;

    for (i = 0; i < size; i++) {

        if (strcmp(cellNum, contacts[i].numbers.cell) == 0) {
            find = i;
        }
    }

    return find;
}


// displayContactHeader
// Put empty function definition below:
void displayContactHeader(void)
{
    printf("\n");
    printf("+-----------------------------------------------------------------------------+\n");
    printf("|                              Contacts Listing                               |\n");
    printf("+-----------------------------------------------------------------------------+\n");
}


// displayContactFooter
// Put empty function definition below:
void displayContactFooter(int count)
{
    printf("+-----------------------------------------------------------------------------+\n");
    printf("Total contacts: %d", count);
    printf("\n");
}


// displayContact:
// Put empty function definition below:
void displayContact(const struct Contact* contact)
{

    printf(" %s ", contact->name.firstName);

    if (strlen(contact->name.middleInitial) != 0) {
        printf("%s ", contact->name.middleInitial);
    }


    printf("%s", contact->name.lastName);
    printf("\n");

    printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);


    printf("       %d %s, ", contact->address.streetNumber, contact->address.street);

    if (contact->address.apartmentNumber > 0) {
        printf("Apt# %d, ", contact->address.apartmentNumber);
    }

    printf("%s, %s\n", contact->address.city, contact->address.postalCode);

}
// displayContacts:
// Put empty function definition below:
void displayContacts(const struct Contact contacts[], int size)
{
    int i;
    int counter = 0;

    displayContactHeader();

    for (i=0; i < size ; i++)
    {
        if (strlen(contacts[i].numbers.cell) > 0)
        {
            displayContact(&contacts[i]);
            counter++;
        }

    }

    displayContactFooter(counter);

}


// searchContacts:
// Put empty function definition below:
void searchContacts(const struct Contact contacts[], int size)
{
    char phone[11];
    int found;

    printf("\n");
    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(phone);

    found = findContactIndex(contacts, sizeof(contacts), phone);

    if (found == -1)
    {
        printf("*** Contact NOT FOUND ***");
        printf("\n\n");

    }
    else
    {
        printf("\n");
        displayContact(&contacts[found]);
        printf("\n");
    }

}


// addContact:
// Put empty function definition below:
void addContact(struct Contact contacts[], int size)
{
    int i;

    for (i = 0; i < size; i++) {

        if (strlen(contacts[i].numbers.cell) == 0) {
            break;
        }
    }
    if (i == size) 
    {
        printf("\n");
        printf("*** ERROR: The contact list is full! ***\n");
        printf("\n");
    }
    else 
    {
        printf("\n");
        getContact(&contacts[i]);
        printf("--- New contact added! ---\n");
        printf("\n");

    }
}


// updateContact:
// Put empty function definition below:
void updateContact(struct Contact contacts[], int size)
{
    char phone[11];
    int found;

    
    printf("\n");
    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(phone);

    found = findContactIndex(contacts, MAXCONTACTS, phone);
    if (found == -1) {
        printf("*** Contact NOT FOUND ***\n");
        printf("\n");
    }
    else
    {
        printf("\n");
        printf("Contact found:");
        printf("\n");
        displayContact(&contacts[found]);
        printf("\n");

        printf("Do you want to update the name? (y or n): ");
        int select = yes();

        if (select == 1) {
            getName(&contacts[found].name);
        }
     
        printf("Do you want to update the address? (y or n): ");
        select = yes();
        if (select == 1) {
            getAddress(&contacts[found].address);
            clearKeyboard();
        }
        

        printf("Do you want to update the numbers? (y or n): ");
        select = yes();
        if (select == 1) {
            getNumbers(&contacts[found].numbers);
        }
    

        printf("--- Contact Updated! ---");
        printf("\n\n");
    }

}


// deleteContact:
// Put empty function definition below:
void deleteContact(struct Contact contacts[], int size)
{
    char phone[11];
    int found;

    printf("\n");
    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(phone);

    found = findContactIndex(contacts, sizeof(contacts), phone);
    if (found == -1) {
        printf("*** Contact NOT FOUND ***");
        printf("\n");
    }
    else {
        printf("\n");
        printf("Contact found:");
        printf("\n");

        displayContact(&contacts[found]);
        printf("\n");

        printf("CONFIRM: Delete this contact? (y or n): ");

        if (yes() == 1) {

            contacts[found].numbers.business[0] = '\0';
            contacts[found].numbers.cell[0] = '\0';
            contacts[found].numbers.home[0] = '\0';
            printf("--- Contact deleted! ---");
            printf("\n");
              
        }

        printf("\n");
    }

}


// sortContacts:
// Put empty function definition below:
void sortContacts(struct Contact contacts[], int size)
{
// i dont did the sort option;
}