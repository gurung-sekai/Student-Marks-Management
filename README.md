# Student-Marks-Management
C console program for recording, displaying, and managing student test marks with a PIN-protected supervisor mode.

# Student Marks Management System (C)

A console-based C application for teachers to **record, display and manage student
test marks**.  
This repository contains my **improved code** and a detailed PDF report of the
original coursework, design, testing, and evaluation.

---

## Overview
The program allows a teacher to maintain up to **35 students** and **10 tests**.
It provides a simple text-menu interface with the following options:

1. **Enter marks** – input marks for a chosen test for all or some students.
2. **Display marks** – show a table of marks and each student’s running average.
3. **Supervisor mode** – protected by a PIN; allows privileged actions:
   * change the supervisor PIN
   * change an individual mark
   * add a new student
   * correct a student’s name
4. **Exit program**

All user input is validated and data is stored in memory using arrays for
efficient access.

---

## Key Features
* **Improved Codebase**
  * Cleaner function separation and shorter, clearer comments.
  * Consistent 2-space indentation and style.
  * Better input validation and error handling.
* **User-Friendly Menus**
  * Clear instructions and feedback for every action.
  * Easy navigation between options.
* **Configurable Constants**
  * `STUDENTS`, `TESTS`, and default `PIN` defined with `#define` for simple
    configuration.

---

## Repository Structure

├── student_marks_improved.c # Improved and fully commented source code
├── student_marks_original.c # Original coursework code in pdf 
├── pdf # Full report with design, testing & evaluation
└── README.md

---

## Build & Run
Compile with a standard C compiler:
```bash
gcc student_marks_improved.c -o student_marks
./student_marks
