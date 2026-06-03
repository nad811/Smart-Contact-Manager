#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/contact.h"

void addContact(Contact **head)
{
    Contact *newNode = (Contact *)malloc(sizeof(Contact));

    printf("Enter Name: ");
    scanf(" %[^\n]", newNode->name);

    printf("Enter Phone: ");
    scanf("%s", newNode->phone);

    printf("Enter Email: ");
    scanf("%s", newNode->email);

    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    Contact *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void displayContacts(Contact *head)
{
    if (!head)
    {
        printf("No contacts found.\n");
        return;
    }

    Contact *temp = head;

    while (temp)
    {
        printf("\nName  : %s\n", temp->name);
        printf("Phone : %s\n", temp->phone);
        printf("Email : %s\n", temp->email);
        temp = temp->next;
    }
}

void searchContact(Contact *head)
{
    char name[NAME_LEN];
    printf("Enter name: ");
    scanf(" %[^\n]", name);

    Contact *temp = head;

    while (temp)
    {
        if (strcmp(temp->name, name) == 0)
        {
            printf("\nFound Contact\n");
            printf("Name  : %s\n", temp->name);
            printf("Phone : %s\n", temp->phone);
            printf("Email : %s\n", temp->email);
            return;
        }
        temp = temp->next;
    }

    printf("Contact not found.\n");
}

void deleteContact(Contact **head)
{
    char name[NAME_LEN];
    printf("Enter name to delete: ");
    scanf(" %[^\n]", name);

    Contact *temp = *head;
    Contact *prev = NULL;

    while (temp)
    {
        if (strcmp(temp->name, name) == 0)
        {
            if (!prev)
                *head = temp->next;
            else
                prev->next = temp->next;

            free(temp);
            printf("Deleted successfully.\n");
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("Contact not found.\n");
}

void sortContacts(Contact *head)
{
    if (!head) return;

    int swapped;
    Contact *ptr;
    Contact temp;

    do
    {
        swapped = 0;
        ptr = head;

        while (ptr->next)
        {
            if (strcmp(ptr->name, ptr->next->name) > 0)
            {
                temp = *ptr;
                *ptr = *(ptr->next);
                *(ptr->next) = temp;

                Contact *t = ptr->next->next;
                ptr->next->next = ptr;
                ptr->next = t;

                swapped = 1;
            }
            ptr = ptr->next;
        }
    } while (swapped);
}

void freeContacts(Contact *head)
{
    Contact *temp;
    while (head)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}
