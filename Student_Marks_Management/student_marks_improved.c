/******************************************************************************/
 /* Student Marks Management (C)
  * - Up to 35 students, up to 10 tests, marks out of 100
  * - Main menu: Enter marks / Display marks / Supervisor mode / Exit
  * - Supervisor mode: change PIN, change a mark, add student, correct name
  * - Once a test's marks are confirmed, teacher cannot change them (locked)
  * - Average column shows each student's mean over tests entered so far
  */
/******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define STUDENTS 35
#define TESTS 10
#define STUDENT_MAX_NAME_LENGTH 50
#define PIN_DEFAULT 3750

/* global state */
static int marks[TESTS][STUDENTS];     /* 0..100; teacher uses 0 if no mark */
static int test_locked[TESTS];          /* 1 once teacher confirms all marks */
static int tests_entered[TESTS];        /* 1 if a test has any entry/was processed */
static char studentNames[STUDENTS][STUDENT_MAX_NAME_LENGTH];
static int currentStudents = 0;
static int currentPIN = PIN_DEFAULT;

/* --- small utilities --- */
static void clear_stdin(void) { int c; while ((c = getchar()) != '\n' && c != EOF) {} }

static int read_int_bounded(const char *prompt, int min, int max) {
  int v, ok = 0;
  do {
    printf("%s", prompt);
    if (scanf("%d", &v) == 1 && v >= min && v <= max) { ok = 1; }
    clear_stdin();
    if (!ok) printf("Please enter a number between %d and %d.\n", min, max);
  } while (!ok);
  return v;
}

static void read_line(const char *prompt, char *buf, size_t n) {
  printf("%s", prompt);
  if (fgets(buf, (int)n, stdin)) {
    size_t L = strlen(buf);
    if (L && (buf[L-1] == '\n' || buf[L-1] == '\r')) buf[L-1] = '\0';
  } else {
    buf[0] = '\0';
  }
}

/* --- initial setup: number of students + names --- */
static void initializeStudentNames(void) {
  currentStudents = read_int_bounded("Enter number of pupils (1..35): ", 1, STUDENTS);
  printf("Enter the names of the pupils:\n");
  for (int i = 0; i < currentStudents; ++i) {
    char tmp[STUDENT_MAX_NAME_LENGTH];
    snprintf(tmp, sizeof(tmp), "Pupil %d name: ", i + 1);
    read_line(tmp, studentNames[i], sizeof(studentNames[i]));
    if (studentNames[i][0] == '\0') { strcpy(studentNames[i], "Unnamed"); }
  }

  /* zero arrays */
  for (int t = 0; t < TESTS; ++t) {
    test_locked[t] = 0;
    tests_entered[t] = 0;
    for (int s = 0; s < STUDENTS; ++s) marks[t][s] = 0;
  }
}

/* --- option 1: teacher enters marks for a given test --- */
static void enterMarks(void) {
  int t = read_int_bounded("Enter test number (1..10): ", 1, TESTS) - 1;

  if (test_locked[t]) {
    printf("Marks for Test %d are locked. Use Supervisor mode to change.\n", t + 1);
    return;
  }

  /* enter marks for each student */
  printf("\nEntering marks for Test %d (0 if no mark):\n", t + 1);
  for (int i = 0; i < currentStudents; ++i) {
    char prompt[96];
    snprintf(prompt, sizeof(prompt), "  %s: ", studentNames[i]);
    marks[t][i] = read_int_bounded(prompt, 0, 100);
  }

  /* simple correction pass before lock */
  printf("\nCheck & correct any mark before locking.\n");
  while (1) {
    int doFix = read_int_bounded("Correct a mark? 1=Yes 2=No: ", 1, 2);
    if (doFix == 2) break;
    int sIdx = read_int_bounded("  Student number (1..N): ", 1, currentStudents) - 1;
    int newMark = read_int_bounded("  New mark (0..100): ", 0, 100);
    marks[t][sIdx] = newMark;
    printf("  Updated %s to %d.\n", studentNames[sIdx], newMark);
  }

  /* confirm: once confirmed, lock for teacher */
  int confirm = read_int_bounded("Confirm and lock Test marks? 1=Yes 2=No: ", 1, 2);
  if (confirm == 1) {
    test_locked[t] = 1;
    tests_entered[t] = 1;
    printf("Test %d marks locked.\n", t + 1);
  } else {
    tests_entered[t] = 1; /* still count as entered so far, but not locked yet */
    printf("Test %d marks saved (not locked).\n", t + 1);
  }
}

/* --- option 2: display table + averages so far --- */
static void displayMarks(void) {
  int enteredCount = 0;
  for (int t = 0; t < TESTS; ++t) if (tests_entered[t]) enteredCount++;

  if (enteredCount == 0) {
    printf("No tests entered yet.\n");
    return;
  }

  printf("\nMarks Table (Average over %d test(s) so far)\n", enteredCount);
  for (int i = 0; i < currentStudents; ++i) {
    double sum = 0.0;
    printf("%-20s ", studentNames[i]);
    for (int t = 0; t < TESTS; ++t) {
      if (tests_entered[t]) {
        printf("%3d ", marks[t][i]);
        sum += marks[t][i];
      }
    }
    double avg = sum / (double)enteredCount;
    printf(" | Avg: %6.2f\n", avg);
  }

  printf("\nPress <enter> to return to main menu.");
  clear_stdin();
}

/* --- supervisor actions --- */
static void changePin(void) {
  int np = read_int_bounded("Enter new 4-digit PIN: ", 1000, 9999);
  currentPIN = np;
  printf("PIN changed.\n");
}

static void changeMark(void) {
  int t = read_int_bounded("Test number (1..10): ", 1, TESTS) - 1;
  int s = read_int_bounded("Student number (1..N): ", 1, currentStudents) - 1;
  int m = read_int_bounded("New mark (0..100): ", 0, 100);
  marks[t][s] = m;
  tests_entered[t] = 1; /* ensure included in averages */
  printf("Mark updated for %s, Test %d -> %d\n", studentNames[s], t + 1, m);
}

static void addingStudent(void) {
  if (currentStudents >= STUDENTS) {
    printf("Class is at max capacity (%d).\n", STUDENTS);
    return;
  }
  read_line("New student name: ", studentNames[currentStudents],
            sizeof(studentNames[currentStudents]));
  for (int t = 0; t < TESTS; ++t) marks[t][currentStudents] = 0;
  currentStudents++;
  printf("Student added. Total now %d.\n", currentStudents);
}

static void correctingStudentName(void) {
  int s = read_int_bounded("Student number (1..N): ", 1, currentStudents) - 1;
  char tmp[STUDENT_MAX_NAME_LENGTH];
  printf("Current name: %s\n", studentNames[s]);
  read_line("New name: ", tmp, sizeof(tmp));
  if (tmp[0]) { strncpy(studentNames[s], tmp, sizeof(studentNames[s]) - 1); }
  printf("Name updated.\n");
}

static void supervisorMode(void) {
  int pin = read_int_bounded("Enter supervisor PIN: ", 0, 999999);
  if (pin != currentPIN) { printf("Incorrect PIN.\n"); return; }

  int choice;
  do {
    printf("\nSupervisor Menu\n");
    printf(" 1) Change PIN\n");
    printf(" 2) Change a mark\n");
    printf(" 3) Add a student\n");
    printf(" 4) Correct a student's name\n");
    printf(" 5) Return to main menu\n");
    choice = read_int_bounded("Choose: ", 1, 5);

    switch (choice) {
      case 1: changePin(); break;
      case 2: changeMark(); break;
      case 3: addingStudent(); break;
      case 4: correctingStudentName(); break;
      case 5: /* back */ break;
    }
  } while (choice != 5);
}

/* --- main menu loop --- */
int main(void) {
  printf("Welcome to the Student Marks System\n");
  initializeStudentNames();

  int choice;
  do {
    printf("\nMain Menu\n");
    printf(" 1) Enter marks\n");
    printf(" 2) Display marks\n");
    printf(" 3) Supervisor mode\n");
    printf(" 4) Exit program\n");
    choice = read_int_bounded("Choose: ", 1, 4);

    switch (choice) {
      case 1: enterMarks(); break;
      case 2: displayMarks(); break;
      case 3: supervisorMode(); break;
      case 4: printf("Exiting...\n"); break;
    }
  } while (choice != 4);

  return 0;
}
