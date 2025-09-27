# Student Marks Management (C)

A console-based application for teachers to record, display, and manage student marks for multiple tests.  
Built entirely in **C**, it demonstrates structured programming, file/console I/O, and a menu-driven user interface.

---

## Features

* **Dynamic Class Setup**
  * Up to **35 students**, each name up to **50 characters**.
  * Up to **10 tests** per student.

* **Main Menu**
  * **Enter Marks** – input marks (0–100) for a selected test. Teachers can review and correct marks before locking them.
  * **Display Marks** – print a table of marks for all tests entered so far with per-student averages.
  * **Supervisor Mode** – PIN-protected menu to:
    * Change the supervisor PIN.
    * Add a new student.
    * Correct a student’s name.
    * Change an individual student’s mark (even after a test is locked).

* **Input Validation & Locking**
  * Marks validated to 0–100.
  * Once confirmed, a test’s marks are locked to prevent accidental edits by teachers.

---

## Build

Use any C11-compatible compiler (e.g. GCC, Clang):

```bash
gcc -std=c11 -O2 -Wall -Wextra -o student_marks student_marks_improved.c
```

This creates an executable named `student_marks`.

---

## Run

```bash
./student_marks
```

1. Enter the number of students (1–35) and their names.
2. Use the menu to enter marks, display marks, or enter Supervisor Mode.
3. Supervisor Mode requires a **4-digit PIN** (default `3750`).

---

## Example Session

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

Check & correct any mark before locking.
Correct a mark? 1=Yes 2=No: 2
Confirm and lock Test marks? 1=Yes 2=No: 1
Test 1 marks locked.
```

---

## Repository Structure

```
├── student_marks_improved.c   # Complete C source code
├── student_management_mark.pdf # Full project design, screenshots, and evaluation
└── README.md
```

*The PDF report provides design rationale, screenshots of the program in action, testing evidence, and a written evaluation.*

[Full Project Report (PDF)](ActionOnWeight-Patient-System/hospitalproject.pdf)

---

## Skills Demonstrated

* **C Programming** – modular design, arrays, functions, and input validation.
* **Interactive Console UI** – menu-driven flow with real-time feedback.
* **Access Control** – PIN-protected supervisor features.
* **Software Engineering** – documented design, testing, and evaluation.

---

## Future Enhancements

* Persist data to disk (e.g. CSV or SQLite database).
* Replace global variables with encapsulated data structures.
* Expand input validation and error handling.
* Add unit tests and a Makefile or CI workflow.
* Improve security (hashed PIN, better memory management).

---

Developed by **Pritam Gurung**  
