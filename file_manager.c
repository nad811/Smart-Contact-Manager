#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/file_manager.h"

void saveContacts(Contact *head)
{
    FILE *fp = fopen("data/contacts.txt", "w");
    if (!fp) return;

    Contact *temp = head;

    while (temp)
    {
        fprintf(fp, "%s,%s,%s\n",
                temp->name,
                temp->phone,
                temp->email);
        temp = temp->next;
    }

    fclose(fp);
}

void loadContacts(Contact **head)
{
    FILE *fp = fopen("data/contacts.txt", "r");
    if (!fp) return;

    char name[NAME_LEN], phone[PHONE_LEN], email[EMAIL_LEN];

    while (fscanf(fp, " %[^,],%[^,],%[^\n]\n",
                  name, phone, email) == 3)
    {
        Contact *newNode = malloc(sizeof(Contact));

        strcpy(newNode->name, name);
        strcpy(newNode->phone, phone);
        strcpy(newNode->email, email);

        newNode->next = NULL;

        if (*head == NULL)
            *head = newNode;
        else
        {
            Contact *temp = *head;
            while (temp->next)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    fclose(fp);
}
