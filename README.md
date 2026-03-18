# CGPA Calculator (C++)

This project is a **CGPA Calculator** written in C++.  
It allows a student to enter multiple courses, their credit hours, and grades, and then calculates the total credits, semester GPA, and overall CGPA (including previous semesters if required).

## Features

- Take input for any number of courses.
- Input course name, credit hours, and grade for each course.
- Convert grade letters to grade points using a fixed scale.
- Calculate:
  - Total credits
  - Total grade points
  - Semester GPA
  - Overall CGPA (with previous CGPA and credits).
- Display a clean summary table of all courses and final results.

## How It Works

1. User enters the number of courses for the current semester.
2. For each course:
   - Enter course name.
   - Enter credit hours.
   - Enter grade (e.g., A, A-, B+, B, C, D, F).
3. The program converts each grade into a numeric grade point.
4. It multiplies grade points by credit hours to get total grade points.
5. Semester GPA = total grade points / total credits.
6. Optionally, the user can enter previous CGPA and total credits to calculate updated CGPA.

## Technologies Used

- Language: C++
- Standard Library: `<iostream>`, `<iomanip>`, `<vector>`, `<string>`, `<limits>`

## File Structure

- `main.cpp` – Contains the implementation of:
  - `struct Course`
  - `convertGradeToPoint()` function
  - Main logic for input, calculation, and output

## How to Compile and Run

```bash
g++ main.cpp -o cgpa_calculator
./cgpa_calculator
