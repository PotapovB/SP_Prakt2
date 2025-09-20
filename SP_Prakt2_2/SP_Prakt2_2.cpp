#include <iostream>
#include <climits>
using namespace std;

void print_stats(int** arr, int rows, int cols) {
    cout << "\n���������� ��� ������� �������:" << endl;
    cout << "�������\t���\t����\t�������" << endl;
    cout << "--------------------------------" << endl;

    for (int j = 0; j < cols; j++) {
        int min_val = INT_MAX;
        int max_val = INT_MIN;

        for (int i = 0; i < rows; i++) {
            if (arr[i][j] < min_val) {
                min_val = arr[i][j];
            }
            if (arr[i][j] > max_val) {
                max_val = arr[i][j];
            }
        }

        int difference = max_val - min_val;
        cout << j << "\t" << min_val << "\t" << max_val << "\t" << difference << endl;
    }

    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

int main() {
    setlocale(LC_ALL, "RU-ru");
    int rows, cols;

    cout << "������� ���������� �����: ";
    cin >> rows;
    cout << "������� ���������� ��������: ";
    cin >> cols;

    if (rows <= 0 || cols <= 0) {
        cout << "������� ������� ������ ���� �������������� �������." << endl;
        return 1;
    }

    int** arr = new int* [rows]; // ��������� �� ������ ���������� �� ���������� (������)

    // ���� ��������� �������
    cout << "������� �������� �������:" << endl;
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            cout << "������� [" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }

    print_stats(arr, rows, cols);
}