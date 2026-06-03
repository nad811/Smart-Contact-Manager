#include <stdio.h>
#include "../include/contact.h"
#include "../include/file_manager.h"

int main()
{
    Contact *head = NULL;
    int choice;

    loadContacts(&head);

    do
    {
        printf("\n--- Contact Manager ---\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Sort Contacts\n");
        printf("6. Save\n");
        printf("7. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: addContact(&head); break;
        case 2: displayContacts(head); break;
        case 3: searchContact(head); break;
        case 4: deleteContact(&head); break;
        case 5: sortContacts(head); break;
        case 6: saveContacts(head); break;
        case 7: saveContacts(head); freeContacts(head); break;
        default: printf("Invalid choice\n");
        }

    } while (choice != 7);

    return 0;
}
