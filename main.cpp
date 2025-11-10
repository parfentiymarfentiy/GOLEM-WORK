#include "Library.h"
#include "Admin.h"
#include <iostream>

using namespace std;

void clearScreen() {
    system("cls");
}

void waitForEnter() {
    cout << "Press Enter to continue...";
    cin.ignore();
}

void adminMenu(Admin& admin) {
    string choice;
    while (true) {
        clearScreen();
        cout << "=== ADMIN MENU ===" << endl;
        cout << "a -> Create test" << endl;
        cout << "b -> Show tests" << endl;
        cout << "c -> Delete test" << endl;
        cout << "d -> Exit to user selection" << endl;
        cout << "Choose: ";

        getline(cin, choice);

        if (choice == "a") {
            clearScreen();
            admin.create_test();
            waitForEnter();
        }
        else if (choice == "b") {
            clearScreen();
            admin.show_tests();
            waitForEnter();
        }
        else if (choice == "c") {
            clearScreen();
            admin.delete_test();
            waitForEnter();
        }
        else if (choice == "d") {
            break;
        }
    }
}

void guestMenu(Admin& admin) {
    string choice;
    while (true) {
        clearScreen();
        cout << "=== GUEST MENU ===" << endl;
        cout << "a -> Take test" << endl;
        cout << "b -> Show tests" << endl;
        cout << "c -> Exit to user selection" << endl;
        cout << "Choose: ";

        getline(cin, choice);

        if (choice == "a") {
            clearScreen();
            admin.start_test();
            waitForEnter();
        }
        else if (choice == "b") {
            clearScreen();
            admin.show_tests();
            waitForEnter();
        }
        else if (choice == "c") {
            break;
        }
    }
}

int main() {
    Admin admin;

    while (true) {
        clearScreen();
        cout << "=== USER SELECTION ===" << endl;
        cout << "1. Admin" << endl;
        cout << "2. Guest" << endl;
        cout << "3. Exit" << endl;
        cout << "Choose: ";

        string userType;
        getline(cin, userType);

        if (userType == "1") {
            clearScreen();
            cout << "Enter admin password: ";
            string password;
            getline(cin, password);

            if (password == "admin") {
                adminMenu(admin);
            }
            else {
                cout << "Invalid password!\n";
                waitForEnter();
            }
        }
        else if (userType == "2") {
            guestMenu(admin);
        }
        else if (userType == "3") {
            break;
        }
        else {
            cout << "Invalid choice!\n";
            waitForEnter();
        }
    }

    cout << "Good luck!\n";
    return 0;
}