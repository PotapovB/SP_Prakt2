#include <iostream>
#include "Queue.h"

int main()
{
    setlocale(LC_ALL, "RU-ru");
    Queue my_q(5);
    
    bool running = true;
    int current_command;
    while (running)
    {
        cout << endl << "0. �����" << endl;
        cout << "1. �������� �������" << endl;
        cout << "2. ���������� ������ �������" << endl;
        cout << "3. ���������� � ������� ������ �������" << endl;
        cout << "4. �������� ������� ������ �������" << endl;
        cout << "������� ����� �������: ";

        cin >> current_command;

        switch (current_command)
        {
        case 0:
            running = false;
            break;
        case 1:
            int x;
            cout << "������� ����� ��� ����������: ";
            cin >> x;
            my_q.enqueue(x);
            cout << "������� ��� ��������." << endl;
            break;
        case 2:
            cout << "������ �������: " << my_q.peek() << endl;
            break;
        case 3:
            cout << "������ ������� (��������): " << my_q.dequeue() << endl;
            break;
        case 4:
            cout << "������� ������ �������: " << my_q.getSize() << endl;
            break;
        default:
            cout << "������� �� �������." << endl;
            break;
        }
    }
}