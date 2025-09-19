#include <iostream>
using namespace std;

void print_array(int n, int arr[])
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int* get_unique_elements(int n, int arr[], int& unique_count) {
	int* temp_arr = new int[n];
	unique_count = 0;

	for (int i = 0; i < n; i++) {
		bool found = false;

		for (int j = 0; j < unique_count; j++) {
			if (arr[i] == temp_arr[j]) {
				found = true;
				break;
			}
		}

		if (!found) {
			temp_arr[unique_count] = arr[i];
			unique_count++;
		}
	}

	int* result = new int[unique_count];
	for (int i = 0; i < unique_count; i++) {
		result[i] = temp_arr[i];
	}

	delete[] temp_arr;
	return result;
}

int main()
{
	setlocale(LC_ALL, "ru-RU");

	int n;
	cout << "¬ведите количество элементов: ";
	cin >> n;

	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cout << endl << "»сходный массив:" << endl;
	print_array(n, arr);

	int new_n = 0;
	int* new_arr = get_unique_elements(n, arr, new_n);

	cout << endl << "”никальные элементы: " << endl;
	print_array(new_n, new_arr);
}