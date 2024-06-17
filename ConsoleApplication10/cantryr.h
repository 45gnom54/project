#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

struct Contact {
    string name;
    string phoneNumber;
};

void showAllContacts(const vector<Contact>& contacts) {
    cout << "Showing all contacts:\n";
    for (size_t i = 0; i < contacts.size(); ++i) {
        cout << "#" << i + 1 << ". Name: " << contacts[i].name << ", Phone: " << contacts[i].phoneNumber << endl;
    }
}

void addContact(vector<Contact>& contacts) {
    cout << "Adding a new contact:\n";
    Contact newContact;
    cout << "Enter name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    getline(cin, newContact.name);
    cout << "Enter phone number: ";
    getline(cin, newContact.phoneNumber);
    contacts.push_back(newContact);
}

void saveContactsToFile(const vector<Contact>& contacts, const string& filename) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const auto& contact : contacts) {
            outFile << contact.name << "," << contact.phoneNumber << endl;
        }
        cout << "Contacts saved to " << filename << endl;
        outFile.close();
    }
    else {
        cout << "Unable to open file " << filename << " for writing." << endl;
    }
}

void loadContactsFromFile(vector<Contact>& contacts, const string& filename) {
    ifstream inFile(filename);
    if (inFile.is_open()) {
        contacts.clear();
        string line;
        while (getline(inFile, line)) {
            stringstream ss(line);
            string name, phoneNumber;
            if (getline(ss, name, ',') && getline(ss, phoneNumber, ',')) {
                contacts.push_back({ name, phoneNumber });
            }
        }
        cout << "Contacts loaded from " << filename << endl;
        inFile.close();
    }
    else {
        cout << "Unable to open file " << filename << " for reading." << endl;
    }
}

void deleteContact(vector<Contact>& contacts) {
    cout << "Enter the number of the contact to delete: ";
    int index;
    cin >> index;

    if (cin.fail() || index < 1 || index > contacts.size()) {
        cout << "Invalid contact number. Please try again.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    else {
        contacts.erase(contacts.begin() + index - 1);
        cout << "Contact deleted.\n";
    }
}