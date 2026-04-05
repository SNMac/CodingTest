#include <iostream>
#include <string>

using namespace std;

int main() {
    double GPA = 0.0;
    double totalPoint = 0.0;
    for (int i = 0; i < 20; i++) {
        string name;
        double point;
        string grade;
        cin >> name >> point >> grade;
        if (grade == "A+") {
            GPA += point * 4.5;
            totalPoint += point;
        } else if (grade == "A0") {
            GPA += point * 4.0;
            totalPoint += point;
        } else if (grade == "B+") {
            GPA += point * 3.5;
            totalPoint += point;
        } else if (grade == "B0") {
            GPA += point * 3.0;
            totalPoint += point;
        } else if (grade == "C+") {
            GPA += point * 2.5;
            totalPoint += point;
        } else if (grade == "C0") {
            GPA += point * 2.0;
            totalPoint += point;
        } else if (grade == "D+") {
            GPA += point * 1.5;
            totalPoint += point;
        } else if (grade == "D0") {
            GPA += point * 1.0;
            totalPoint += point;
        } else if (grade == "F") {
            GPA += point * 0.0;
            totalPoint += point;
        } else { // grade == "P"
            continue;
        }
    }
    cout << fixed;
    cout.precision(6);
    cout << GPA / totalPoint << '\n';
    return 0;
}
