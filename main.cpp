// Grade Calculator
// Author: Sandzhar Tabyldiyev, group sw1-25
// Reads students' names and 5 scores each, then prints the average
// and the grade. Typing "end" instead of a name finishes the program.
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    const int SCORE_COUNT = 5;      // every student has exactly 5 scores
    const int MIN_SCORE = 0;
    const int MAX_SCORE = 100;

    int studentCount = 0;
    double sumOfAverages = 0.0;
    string studentName;

    cout << fixed << setprecision(1);

    // Outer loop: one iteration = one student
    while (true) {
        cout << "Student name (or end to finish): ";
        if (!getline(cin, studentName) || studentName == "end") {
            break;
        }

        int totalScore = 0;

        // Read 5 scores
        for (int i = 1; i <= SCORE_COUNT; i++) {
            int score;
            bool isValid = false;

            // Inner loop: ask again until the score is correct
            while (!isValid) {
                cout << "Score " << i << ": ";
                cin >> score;

                if (cin.fail()) {
                    // Bonus: letters instead of a number
                    if (cin.eof()) {
                        return 0;
                    }
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid score. Enter a value from "
                         << MIN_SCORE << " to " << MAX_SCORE << "."
                         << endl;
                } else if (score < MIN_SCORE || score > MAX_SCORE) {
                    cout << "Invalid score. Enter a value from "
                         << MIN_SCORE << " to " << MAX_SCORE << "."
                         << endl;
                } else {
                    isValid = true;
                }
            }
            totalScore += score;
        }
        cin.ignore(1000, '\n');     // remove Enter before the next name

        double average = (double)totalScore / SCORE_COUNT;

        char grade;
        if (average >= 90) {
            grade = 'A';
        } else if (average >= 75) {
            grade = 'B';
        } else if (average >= 60) {
            grade = 'C';
        } else {
            grade = 'F';
        }

        cout << studentName << ": average " << average
             << ", grade " << grade << endl << endl;

        studentCount++;
        sumOfAverages += average;
    }

    if (studentCount == 0) {
        cout << "No students entered" << endl;
    } else {
        cout << "Students entered: " << studentCount << endl;
        cout << "Class average: " << sumOfAverages / studentCount << endl;
    }
    return 0;
}
