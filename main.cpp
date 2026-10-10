#include <iostream>
#include <stdexcept>
#include "EventSystem.h"

using namespace std;

int main()
{
    EventSystem system;

    int choice;

    do
    {
        cout << "\n========================================" << endl;
        cout << "   COLLEGE EVENT MANAGEMENT SYSTEM" << endl;
        cout << "========================================" << endl;

        cout << "1. Add Record" << endl;
        cout << "2. Display Records" << endl;
        cout << "3. Search Event" << endl;
        cout << "4. Update Event" << endl;
        cout << "5. Delete Event" << endl;
        cout << "6. Main Transaction / Process" << endl;
        cout << "7. Generate Report" << endl;
        cout << "8. Demonstrate Polymorphism" << endl;
        cout << "9. Save / Load Data" << endl;
        cout << "10. Exit" << endl;

        cout << "\nEnter your choice: ";

        // Exception Handling for Main Menu Input
        try
        {
            if (!(cin >> choice))
            {
                throw invalid_argument(
                    "Invalid input! Please enter a number.");
            }
        }
        catch (const invalid_argument &e)
        {
            cout << e.what() << endl;

            cin.clear();
            cin.ignore(10000, '\n');

            continue;
        }

        switch (choice)
        {
        case 1:
        {
            int addChoice;

            cout << "\n===== ADD RECORD =====" << endl;
            cout << "1. Add Event" << endl;
            cout << "2. Add Participant" << endl;
            cout << "3. Back to Main Menu" << endl;

            cout << "\nEnter your choice: ";
            cin >> addChoice;

            switch (addChoice)
            {
            case 1:
                system.addEvent();
                break;

            case 2:
                system.addParticipant();
                break;

            case 3:
                cout << "Returning to main menu..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
            }

            break;
        }

        case 2:
        {
            int displayChoice;

            cout << "\n===== DISPLAY RECORDS =====" << endl;
            cout << "1. Display Events" << endl;
            cout << "2. Display Participants" << endl;
            cout << "3. Display Registrations" << endl;
            cout << "4. Back to Main Menu" << endl;

            cout << "\nEnter your choice: ";
            cin >> displayChoice;

            switch (displayChoice)
            {
            case 1:
                system.displayEvents();
                break;

            case 2:
                system.displayParticipants();
                break;

            case 3:
                system.displayRegistrations();
                break;

            case 4:
                cout << "Returning to main menu..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
            }

            break;
        }

        case 3:
            system.searchEvent();
            break;

        case 4:
            system.updateEvent();
            break;

        case 5:
            system.deleteEvent();
            break;

        case 6:
        {
            int transactionChoice;

            cout << "\n===== MAIN TRANSACTION =====" << endl;
            cout << "1. Register Participant for Event" << endl;
            cout << "2. Cancel Registration" << endl;
            cout << "3. Back to Main Menu" << endl;

            cout << "\nEnter your choice: ";
            cin >> transactionChoice;

            switch (transactionChoice)
            {
            case 1:
                system.registerParticipant();
                break;

            case 2:
                system.cancelRegistration();
                break;

            case 3:
                cout << "Returning to main menu..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
            }

            break;
        }

        case 7:
            system.generateReport();
            break;

        case 8:
            system.demonstratePolymorphism();
            break;

        case 9:
        {
            int fileChoice;

            cout << "\n===== SAVE / LOAD DATA =====" << endl;
            cout << "1. Save Data" << endl;
            cout << "2. Load Data" << endl;
            cout << "3. Back to Main Menu" << endl;

            cout << "\nEnter your choice: ";
            cin >> fileChoice;

            switch (fileChoice)
            {
            case 1:
                system.saveData();
                break;

            case 2:
                system.loadData();
                break;

            case 3:
                cout << "Returning to main menu..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
            }

            break;
        }

        case 10:
            cout << "\nThank you for using College Event Management System!" << endl;
            break;

        default:
            cout << "\nInvalid choice! Please try again." << endl;
        }

    } while (choice != 10);

    return 0;
}