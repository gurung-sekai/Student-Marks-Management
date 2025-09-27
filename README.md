# Hospital Record Encryption – Student Marks Management (C)

A command-line program to manage and securely store student marks (or hospital-style records) with a simple **educational encryption** layer.

> **Important:**  
> This project uses a basic Caesar-style cipher for learning purposes only.  
> It is **not** suitable for real patient or student data in production.

---

## Overview
This system allows a teacher or administrator to:

* Create a class roster (up to **35 students**, each with a name of up to **50 characters**).
* Record marks for up to **10 tests** per student.
* View all marks in a tabular format with automatic per-student averages.
* Enter a **Supervisor Mode** (PIN-protected) to:
  * Change the supervisor PIN.
  * Add new students.
  * Correct a student’s name.
  * Edit or lock individual marks.

It demonstrates **structured C programming**, **file/console I/O**, basic **data security concepts**, and an interactive menu-driven interface.

---

## Features
* **Array-based data storage** for student names and marks.
* **Lockable tests**: once confirmed, marks for a test are read-only unless changed by a supervisor.
* **Input validation** for numeric ranges and string lengths.
* Clear, user-friendly console menus.

---

## Build

Compile with any C11-compatible compiler (GCC/Clang/MSVC).  
Example with GCC:

```bash
gcc -std=c11 -O2 -Wall -Wextra -o student_marks student_marks_improved.c
```

---

## Run

```bash
./student_marks
```

You will be guided to:
1. Enter the number of pupils and their names.
2. Use the menu to enter marks, display marks, or enter Supervisor Mode.

---

## Sample Session

```
Welcome to the Student Marks System
Enter number of pupils (1..35): 3
Enter the names of the pupils:
  Pupil 1 name: Alice
  Pupil 2 name: Bob
  Pupil 3 name: Charlie

Main Menu
 1) Enter marks
 2) Display marks
 3) Supervisor mode
 4) Exit program
Choose: 1

Enter test number (1..10): 1
Entering marks for Test 1 (0 if no mark):
  Alice: 90
  Bob: 85
  Charlie: 78
Confirm and lock Test marks? 1=Yes 2=No: 1
Test 1 marks locked.
```

Supervisor Mode requires a PIN (default **3750**) and offers options to add students, change a mark, correct names, or change the PIN.

---

---

## File Structure
```
├─ student_marks_improved.c    # Complete C source code
├─ student_management_mark.pdf # Full project report and testing evidence
└─ README.md
```

---

## Future Enhancements
* Replace the educational cipher with strong encryption (e.g., libsodium).
* Persist data to disk between runs (CSV or SQLite).
* Add automated unit tests and a Makefile or CI workflow.
* Harden input validation and error handling.

---

Developed by **Pritam Gurung** to demonstrate C programming, basic security concepts, and user-friendly console application. 
