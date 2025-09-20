
#include <iostream>
#include <iomanip>
using namespace std;

struct Employee {
    char name[50];
    char position[50];
    double salary;
};

void input_employee(Employee& emp) {
    cout << "Введите имя сотрудника: ";
    cin.ignore();
    cin.getline(emp.name, 50);

    cout << "Введите должность: ";
    cin.getline(emp.position, 50);

    cout << "Введите зарплату: ";
    cin >> emp.salary;
    cout << endl;
}

void print_employee(const Employee& emp) {
    cout << "Имя: " << emp.name
        << ", Должность: " << emp.position
        << ", Зарплата: " << fixed << setprecision(2) << emp.salary
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

    cout << "Введите количество сотрудников: ";
    cin >> n;

    Employee* employees = new Employee[n];


    for (int i = 0; i < n; i++) {
        cout << "Сотрудник #" << i + 1 << ":" << endl;
        input_employee(employees[i]);
    }


    double average_salary = calculate_averate_salary(employees, n);
    cout << "Средняя зарплата: " << fixed << setprecision(2)
        << average_salary << endl << endl;


    cout << "Сотрудники с зарплатой ниже среднего:" << endl;
    bool found = false;

    for (int i = 0; i < n; i++) {
        if (employees[i].salary < average_salary) {
            print_employee(employees[i]);
            found = true;
        }
    }

    if (!found) {
        cout << "Сотрудников с зарплатой ниже среднего не найдено." << endl;
    }

    delete[] employees;
}
