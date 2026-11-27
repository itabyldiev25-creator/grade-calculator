Coding rules for C++
These are the rules I follow in this project.
1. Variables and functions use camelCase with meaningful names
Use a name that explains what the variable stores. One-letter names are allowed only for loop counters (`i`) or names given in the task.
```cpp
int studentCount = 0;      // good
int student_count = 0;     // bad: not camelCase
int sc = 0;                // bad: unclear name
```
2. Constants use UPPER_CASE (no "magic numbers")
```cpp
const int SCORE_COUNT = 5;
const int MAX_SCORE = 100;
```
3. Indent with 4 spaces and always use braces
Do not use tabs. Put the code of every `if`, `for` and `while` in `{ }`, even if it is one line.
```cpp
if (score > MAX_SCORE) {
    cout << "Invalid score" << endl;
}
```
4. Write comments for every logical block
Put a short comment at the top of the file (what the program does and who wrote it) and before each important block of code. Explain why, not only what.
```cpp
// Inner loop: ask again until the score is correct
while (!isValid) {
    ...
}
```
5. One statement per line, maximum 80 characters per line
```cpp
totalScore += score;       // good
count++; total += x;       // bad: two statements on one line
