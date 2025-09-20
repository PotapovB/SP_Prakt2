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
        cout << endl << "0. Выход" << endl;
        cout << "1. Добавить элемент" << endl;
        cout << "2. Посмотреть первый элемент" << endl;
        cout << "3. Посмотреть и удалить первый элемент" << endl;
        cout << "4. Получить текущий размер очереди" << endl;
        cout << "Введите номер команды: ";

        cin >> current_command;

        switch (current_command)
        {
        case 0:
            running = false;
            break;
        case 1:
            int x;
            cout << "Введите число для добавления: ";
            cin >> x;
            my_q.enqueue(x);
            cout << "Элемент был добавлен." << endl;
            break;
        case 2:
            cout << "Первый элемент: " << my_q.peek() << endl;
            break;
        case 3:
            cout << "Первый элемент (убранный): " << my_q.dequeue() << endl;
            break;
        case 4:
            cout << "Текущий размер очереди: " << my_q.getSize() << endl;
            break;
        default:
            cout << "Команда не найдена." << endl;
            break;
        }
    }
}