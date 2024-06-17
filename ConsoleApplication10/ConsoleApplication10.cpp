#include "cantryr.h"

int main() {
    vector<Contact> contacts;
    int menu;

    loadContactsFromFile(contacts, "contacts.txt");

    do {
        cout << "++++++++++++++++++++++++++++++++\n";
        cout << "         PHONEBOOK MENU\n";
        cout << "++++++++++++++++++++++++++++++++\n";
        cout << "0. Exit\n";
        cout << "1. Show all contacts\n";
        cout << "2. Add a new contact\n";
        cout << "3. Save contacts to file\n";
        cout << "4. Delete a contact\n";
        cin >> menu;
    //.
        switch (menu) {
        case 0:
            cout << "Exiting...\n";
            break;
        case 1:
            showAllContacts(contacts);
            break;
        case 2:
            addContact(contacts);
            break;
        case 3:
            saveContactsToFile(contacts, "contacts.txt");
            break;
        case 4:
            deleteContact(contacts);
            saveContactsToFile(contacts, "contacts.txt");
            break;
        default:
            cout << "Invalid option. Please try again.\n";
        }
    } while (menu != 0);

    return 0;
}
