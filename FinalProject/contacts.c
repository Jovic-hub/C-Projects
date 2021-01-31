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
// |        source code below...                     |
// +-------------------------------------------------+

#include <stdio.h>
#include <string.h>
#include "contacts.h"
#include "contactHelpers.h"

void getName(struct Name* name)
{

    printf("Please enter the contact's first name: ");
    scanf("%[^\n]40s", name->firstName);
    clearKeyboard();

    printf("Do you want to enter a middle initial(s)? (y or n): ");
    int select = yes();

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
void getAddress(struct Address* address)
{

    printf("Please enter the contact's street number: ");
    address->streetNumber = getInt();


    if (address->streetNumber <= 0) {

        printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
        address->streetNumber = getInt();


    } while (address->streetNumber < 1);



    printf("Please enter the contact's street name: ");
    scanf("%[^\n]40s", address->street);
    clearKeyboard();

    printf("Do you want to enter an apartment number? (y or n): ");
    int select = yes();
    
    if (select == 0)
    {
        address->apartmentNumber = '\0';
    }
    else {
        printf("Please enter the contact's apartment number: ");
        address->apartmentNumber = getInt();
        if (address->apartmentNumber <= 0) {

            printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
            address->apartmentNumber = getInt();
        }
    }

    printf("Please enter the contact's postal code: ");
    scanf("%7[^\n]", address->postalCode);

    clearKeyboard();

    printf("Please enter the contact's city: ");
    scanf("%[^\n]40s", address->city);
}

// getNumbers:
void getNumbers(struct Numbers* numbers)
{


    printf("Please enter the contact's cell phone number: ");
    getTenDigitPhone(numbers->cell);


    printf("Do you want to enter a home phone number? (y or n): ");
    int select = yes();

    if (select == 0)
    {
        numbers->home[0] = '\0';
    }
    else {
        printf("Please enter the contact's home phone number: ");
        getTenDigitPhone(numbers->home);

    }

    

    printf("Do you want to enter a business phone number? (y or n): ");
    select = yes();

    if (select == 0)
    {
        numbers->business[0] = '\0';
    }
    else {
        printf("Please enter the contact's business phone number: ");
        getTenDigitPhone(numbers->business);

    }
}
// getContact:
void getContact(struct Contact* contact)

{
    struct Contact contact_get;
    getName(&contact_get.name);
    getAddress(&contact_get.address);
    getNumbers(&contact_get.numbers);

    *contact = contact_get;
}