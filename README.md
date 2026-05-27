# Library Management System

### Archive Note (1st Semester Project)
> **Note:** This repository is part of my foundational academic archive, originally developed **approximately 2 years ago during my 1st semester**. It showcases my early exploration of procedural programming, custom structural logic, and persistent local data streams.
>
> *More advanced architectural and algorithmic projects from my current 5th semester are being curated and will be live on this profile shortly.*

---

## About the Project
This project is a CLI-based Library Management System built in C++. It simulates a real-world library environment by managing distinct administrative and member access privileges, backed by flat-file data persistence.

### Key Technical Implementations:
* **File Handling (`fstream`):** Implements localized data persistence for user credentials, book transaction records, donation details, and pending returns.
* **Role-Based Authentication:** Distinct operational flows for Admins (record checking, pending lists) and Users (sign-up, personalized search, book borrowing loops).
* **System State Formatting:** Leverages `<windows.h>` utilities for customized console UI elements and display rendering resets (`system("CLS")`).

## Repository Architecture
* `LibraryManagement.cpp` — Core engine containing authentication, menu loops, and transactional logic.
* `Library Management.pptx` — Project overview and architecture documentation.

## How to Compile & Run
Ensure you are compiling on a Windows environment (due to the `<windows.h>` header dependencies):

```bash
g++ LibraryManagement.cpp -o LibrarySystem
./LibrarySystem
