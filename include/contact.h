#ifndef CONTACT_H
#define CONTACT_H

#define NAME_LEN 50
#define PHONE_LEN 15
#define EMAIL_LEN 50

typedef struct Contact
{
    char name[NAME_LEN];
    char phone[PHONE_LEN];
    char email[EMAIL_LEN];
    struct Contact *next;
} Contact;

/* Core operations */
void addContact(Contact **head);
void displayContacts(Contact *head);
void searchContact(Contact *head);
void deleteContact(Contact **head);
void sortContacts(Contact *head);
void freeContacts(Contact *head);

#endif
