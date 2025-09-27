# Student Marks Management (C)

An interactive **C** program for recording, displaying, and managing classroom test marks.  
It supports up to **35 students** and **10 tests**, provides PIN‑protected supervisor features,  
and demonstrates structured C programming and input validation.

> **Note:** Data is stored in memory only; this is an educational project

---

## Features

* **Dynamic Class Setup**  
  * Prompt for number of students (1–35) and names (up to 50 chars).
  * Record marks for up to 10 tests per student.

* **Teacher Menu**  
  * **Enter Marks** – input marks 0–100, with a correction pass before locking each test.  
  * **Display Marks** – view a table of entered marks and running averages.

* **Supervisor Mode** (PIN‑protected, default `3750`)  
  * Change the supervisor PIN.  
  * Add a student (up to the 35‑student limit).  
  * Change an individual mark (even if locked).  
  * Correct a student name.

* **Data Validation & Locking**  
  * Marks validated to 0–100.  
  * Once confirmed, a test’s marks are locked for teachers (but editable by the supervisor).

---

## Build

Use any C11‑compatible compiler (e.g. GCC, Clang):

```bash
gcc -std=c11 -O2 -Wall -Wextra -o student_marks student_marks_improved.c
```

---

## Run

```bash
./student_marks
```

1. Enter the number of students and their names.  
2. Use the menu to enter marks, display marks, or access supervisor features.  
3. Enter the supervisor PIN (default **3750**) to unlock management functions.

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
├── student_marks_improved.c   # Complete, improved C source code
└── README.md
```


---

## Skills Demonstrated

* **C Programming** – modular functions, arrays, input validation, and interactive menus.
* **Access Control** – PIN‑protected supervisor features.
* **Software Engineering** – clear documentation, testing evidence, and maintainable structure.

---

## Future Enhancements

* Persistent storage (CSV or database) to retain data across runs.
* Stronger security (hashed PIN, encryption of saved data).
* Expanded input validation and error handling.
* Unit tests and a Makefile or CI workflow for automated builds.

---

Developed by **Pritam Gurung**  
