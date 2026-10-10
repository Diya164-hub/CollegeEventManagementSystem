COLLEGE EVENT MANAGEMENT SYSTEM
C++ Console-Based OOP Project

==================================================
1. PROJECT OVERVIEW
==================================================

The College Event Management System is a console-based
C++ application designed to manage college events,
participants, and event registrations.

The system allows users to add, display, search, update,
and delete event records. It also supports participant
management, event registration, cancellation, report
generation, and file-based data storage.

==================================================
2. PROJECT OBJECTIVES
==================================================

1. To manage college event records.
2. To maintain participant information.
3. To register participants for events.
4. To search, update, and delete event records.
5. To generate reports.
6. To save and load data using files.
7. To demonstrate Object-Oriented Programming concepts
   in C++.

==================================================
3. TECHNOLOGIES USED
==================================================

Programming Language: C++
Compiler: GCC / MinGW g++
Editor: Visual Studio Code
Application Type: Console-Based Application
Data Storage: Text Files
Compilation Command: g++ main.cpp Event.cpp Participant.cpp Organizer.cpp Person.cpp 
 Registration.cpp EventSystem.cpp FileManager.cpp -o CollegeEventManagementSystem.exe
Program Execution Command: .\CollegeEventManagementSystem.exe

==================================================
4. MAIN FEATURES
==================================================

1. Add Event
2. Add Participant
3. Display Events
4. Display Participants
5. Display Registrations
6. Search Event
7. Update Event
8. Delete Event
9. Register Participant
10. Cancel Registration
11. Generate Report
12. Demonstrate Runtime Polymorphism
13. Save and Load Data

==================================================
5. PROJECT FILES
==================================================

main.cpp              - Main menu and program execution
Event.h               - Event class declaration
Event.cpp             - Event class implementation
Participant.h         - Participant class declaration
Participant.cpp       - Participant implementation
Organizer.h           - Organizer class declaration
Organizer.cpp         - Organizer implementation
Person.h              - Abstract base class
Person.cpp            - Person class implementation
Registration.h        - Registration class declaration
Registration.cpp      - Registration implementation
EventSystem.h         - EventSystem class declaration
EventSystem.cpp       - Event management operations
FileManager.h         - FileManager class declaration
FileManager.cpp       - File storage and retrieval

Data/                 - Stores application data
Diagrams/             - Contains UML diagrams

==================================================
6. OOP CONCEPTS
==================================================

The project demonstrates the following concepts:

1. Classes and Objects
2. Encapsulation
3. Constructors and Destructors
4. Inheritance
5. Runtime Polymorphism
6. Dynamic Memory Allocation
7. File Handling
8. Exception Handling
9. Input Validation

==================================================
7. HOW TO COMPILE
==================================================

Open the project folder in Visual Studio Code.

Open the terminal in the project directory.

Compile all source files using:

g++ main.cpp Event.cpp Participant.cpp Organizer.cpp
Person.cpp Registration.cpp EventSystem.cpp
FileManager.cpp -o CollegeEventManagementSystem.exe

If compilation is successful, an executable file will
be created.

==================================================
8. HOW TO RUN
==================================================

On Windows PowerShell, execute:

.\CollegeEventManagementSystem.exe

The main menu will appear.

Enter the required menu number and follow the
instructions displayed by the application.

==================================================
9. DATA STORAGE
==================================================

The application stores event, participant, and
registration information in text files inside the
Data folder.

Use the Save / Load Data menu to save records and
load previously saved records.

==================================================
10. UML DIAGRAMS
==================================================

The Diagrams folder contains:

1. Use Case Diagram
2. Class Diagram
3. Sequence Diagram 1 - Event Registration
4. Sequence Diagram 2 - Event Search

==================================================
11. PROJECT LIMITATIONS
==================================================

The application currently uses a console-based
interface and a limited number of records.

Data is stored in text files rather than a database.

==================================================
12. FUTURE SCOPE
==================================================

1. Develop a graphical user interface.
2. Integrate a database.
3. Add user authentication.
4. Support online event registration.
5. Add email notifications.

==================================================
13. CONCLUSION
==================================================

The College Event Management System demonstrates
how C++ and Object-Oriented Programming concepts
can be applied to a practical college management
application.

The system provides basic event and participant
management, registration processing, report generation,
and file-based data persistence.