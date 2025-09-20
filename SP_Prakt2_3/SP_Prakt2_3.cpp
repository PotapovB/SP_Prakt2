
#include <iostream>
#include <iomanip>
using namespace std;

struct Employee {
    char name[50];
    char position[50];
    double salary;
};

void input_employee(Employee& emp) {
    cout << "������� ��� ����������: ";
    cin.ignore();
    cin.getline(emp.name, 50);

    cout << "������� ���������: ";
    cin.getline(emp.position, 50);

    cout << "������� ��������: ";
    cin >> emp.salary;
    cout << endl;
}

void print_employee(const Employee& emp) {
    cout << "���: " << emp.name
        << ", ���������: " << emp.position
        << ", ��������: " << fixed << setprecision(2) << emp.salary
        << endl;
}

double calculate_averate_salary(const Employee employees[], int count) {
    double total = 0.0;
    for (int i = 0; i < count; i++) {
        total += employees[i].salary;
    }
    return total / count;
}

int main()
{
    setlocale(LC_ALL, "RU-ru");
    int n;

    cout << "������� ���������� �����������: ";
    cin >> n;

    Employee* employees = new Employee[n];


    for (int i = 0; i < n; i++) {
        cout << "��������� #" << i + 1 << ":" << endl;
        input_employee(employees[i]);
    }


    double average_salary = calculate_averate_salary(employees, n);
    cout << "������� ��������: " << fixed << setprecision(2)
        << average_salary << endl << endl;


    cout << "���������� � ��������� ���� ��������:" << endl;
    bool found = false;

    for (int i = 0; i < n; i++) {
        if (employees[i].salary < average_salary) {
            print_employee(employees[i]);
            found = true;
        }
    }

    if (!found) {
        cout << "����������� � ��������� ���� �������� �� �������." << endl;
    }

    delete[] employees;
}
