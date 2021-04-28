

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "contacts.h"
#include "contactHelpers.h"

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        function definitions below...            |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// +-------------------------------------------------+

void getName(struct Name *name)
{
    int select;

    printf("Please enter the contact's first name: ");
    scanf("%[^\n]40s", name->firstName);
    clearKeyboard();

    printf("Do you want to enter a middle initial(s)? (y or n): ");
    select = yes();

    if (select == 0)
    {
        name->middleInitial[0] = '\0';
    }
    else {
        printf("Please enter the contact's middle initial(s): ");
        scanf("%6[^\n]", name->middleInitial);
        clearKeyboard();
    }
    printf("Please enter the contact's last name: ");
    scanf("%[^\n]", name->lastName);

    clearKeyboard();
}

// getAddress:
void getAddress(struct Address *address)
{
    char yesNo;

     printf("Please enter the contact's street number: ");
     address->streetNumber = getInt();

     
     if (address->streetNumber <= 0){
       
     printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
     address->streetNumber = getInt();


    } while (address->streetNumber < 1);



    printf("Please enter the contact's street name: ");
    scanf("%[^\n]40s", address->street);

    printf("Do you want to enter an apartment number? (y or n): ");
    scanf("\n%c", &yesNo);

    if (yesNo == 'y' || yesNo == 'Y')
    {
        do
        {
            printf("Please enter the contact's apartment number: ");
            scanf("%d", &address->apartmentNumber);

            if (address->apartmentNumber < 1);
                printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
                scanf("%d", &address->apartmentNumber);
    
        } while (address->apartmentNumber < 1);
        
    }

    clearKeyboard();
    printf("Please enter the contact's postal code: ");
    scanf("%7[^\n]", address->postalCode);

    clearKeyboard();

    printf("Please enter the contact's city: ");
    scanf("%[^\n]40s", address->city);
}

// getNumbers:
void getNumbers(struct Numbers* numbers)
{
    int select;

    clearKeyboard();

    printf("Please enter the contact's cell phone number: ");
    scanf("%10[^\n]", numbers->cell);

    clearKeyboard();

    printf("Do you want to enter a home phone number? (y or n): ");
    select = yes();

    if (select == 0)
    {
        numbers->home[0] = '\0';
    }
    else {
        printf("Please enter the contact's home phone number: ");
        scanf("%10[^\n]", numbers->home);

    }



    printf("Do you want to enter a business phone number? (y or n): ");
    select = yes();

    if (select == 0)
    {
        numbers->business[0] = '\0';
    }
    else {
        printf("Please enter the contact's business phone number: ");
        scanf("%10[^\n]", numbers->business);

    }
}
// +-------------------------------------------+
// | ====== Assignment 2 | Milestone 1 ======= |
// +-------------------------------------------+

// getContact:
void getContact(struct Contact *contact)
// Define Empty function definition below:
{
    struct Contact contact_get;
    getName(&contact_get.name);
    getAddress(&contact_get.address);
    getNumbers(&contact_get.numbers);

    *contact = contact_get;
}
