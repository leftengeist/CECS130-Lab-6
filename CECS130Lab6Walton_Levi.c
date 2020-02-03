#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
Program creates a phone book that uses memory allocation
Walton Levi
Section 1
*/

typedef struct phoneBook
{
    char cFirstName[10];
    char cLastName[10];
    char cPhoneNumber[10];
} pb;

void iAddContact(pb*, int);
int iRemoveContact(pb*, int);
void iShowPhoneBook(pb*, int);

int main()
{
    pb *contact;
    int iIndex=0;
    int iSelection;
    contact = calloc(1, 5*sizeof(pb));

    while(iSelection != 4)
    {
        printf("Phone Book Application");
        printf("\n1) Add Contact");
        printf("\n2) Remove Contact");
        printf("\n3) Show Phone Book");
        printf("\n4) Exit");
        printf("\nSelection: ");
        scanf("%d", &iSelection);

        switch(iSelection)
        {
            case 1:
                contact = realloc(contact, (iIndex+1)*sizeof(pb));
                iAddContact(contact, iIndex);
                iIndex++;
                break;

            case 2:
                if(iRemoveContact(contact, iIndex))
                {
                    iIndex--;
                    contact = realloc(contact, (iIndex)*sizeof(pb));
                }
                break;

            case 3:
                iShowPhoneBook(contact, iIndex);
                break;
            case 4:
                free(contact);
                break;
        }
    }
    return 0;
}

void iAddContact(pb* contact, int c)
{
    printf("First Name: ");
    scanf("%s", &contact[c].cFirstName);
    printf("Last Name: ");
    scanf("%s", &contact[c].cLastName);
    printf("Phone Number: ");
    scanf("%s", &contact[c].cPhoneNumber);
}

int iRemoveContact(pb* contact, int c)
{
    int v = 0;
    int i=0;
    char fn[15];
    char ln[15];
    printf("First Name: ");
    scanf("%s", &fn);
    printf("Last Name: ");
    scanf("%s", &ln);

    for (i = 0; i < c; i++)
    {
        if(!strcmp(contact[i].cFirstName, fn) && !strcmp(contact[i].cLastName, ln) && v == 0)
        {
            v++;
        }
        if(v)
        {
            contact[i] = contact[i+1];
        }
    }
    printf("Record Deleted");
    return v;
}

void iShowPhoneBook(pb* contact, int c)
{
    int v=0;
    printf("\nPhone Book Contacts");
    for(v = 0; v < c; v++)
    {
        printf("\n%s %s %s\n\n", &contact[v].cFirstName, &contact[v].cLastName, &contact[v].cPhoneNumber);
    }
}
