#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student
{
    string name;
    int grade;
};

bool compareGrades(const Student& a, const Student& b)
{
    return a.grade > b.grade;
}

int main()
{
    setlocale(LC_ALL, "RU");

    int numStudents;
    cout << "Сколько студентов вы хотите ввести? ";
    cin >> numStudents;

    vector<Student> students;

    for (int i = 0; i < numStudents; ++i) {
        Student student;
        cout << "Введите имя студента " << i + 1 << ": ";
        cin >> student.name;

        cout << "Введите оценку студента " << student.name << ": ";
        cin >> student.grade;

        students.push_back(student);
    }

    sort(students.begin(), students.end(), compareGrades);

    for (const auto& student : students)
    {
        cout << student.name << " получил оценку " << student.grade << endl;
    }

    return 0;
}
