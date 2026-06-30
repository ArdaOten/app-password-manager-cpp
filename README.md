# Password Manager (C++)

A console-based password manager built in C++ with user authentication, 
XOR encryption, and admin panel functionality.

## Features
- User registration and login system
- XOR-based password encryption
- Per-user encrypted credential storage
- Admin panel for user management
- Add, search, list, and delete saved credentials
- Persistent file-based storage

## Admin Panel
The application includes a separate admin panel accessible with admin 
credentials. Admins can:
- View all registered users
- Select a specific user account
- Add, search, view, or delete that user's saved credentials
- Delete a user and all their associated data permanently

## Tech Stack
- C++ (OOP: classes, structs)
- File I/O (fstream)
- STL Vectors

## What I Learned
This project helped me practice file handling, basic encryption logic, 
vector-based data management, and designing a multi-class system with 
clear separation of concerns (account management, data storage, admin operations).

## How to Run
Compile with any C++ compiler (e.g., g++) and run the executable.

