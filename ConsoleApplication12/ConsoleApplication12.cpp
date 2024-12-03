#include <iostream>
using namespace std;

void swap(int* a, int* b) {
    int* temp = a;
    a = b;
    b = temp;
}

int main() {
    setlocale(LC_ALL, "Russian");

    //Сортировка пузырьком
    int bubble[10]{ 0, 4, 7, 5, 2, 9, 6, 3, 1, 8 }, size1 = 10;
    for (int i = 1; i < size1; i++) {
        for (int j = 0; j < size1 - 1; j++) {
            if (bubble[j + 1] < bubble[j])
                swap(bubble[j + 1], bubble[j]);
        }
    }
    cout << endl << "Сортировка пузырьком: ";
    for (int i = 0; i < 10; i++)
        cout << bubble[i] << ' ';
    cout << endl;

    //Сортировка выбором минимального значение
    int minVal[10]{ 1, 15, 1, 6, 8, 7, -1, 4, 9, 30 }, size2 = 10, index, min, step = 1;
    for (int i = 0; i < size2 - 1; i++) {
        min = minVal[i];
        for (int j = step; j < size2; j++) {
            if (minVal[j] < min) {
                index = j;
                min = minVal[j];
            }
        }
        step += 1;
        swap(minVal[index], minVal[i]);
    }
    cout << endl << "Сортировка выбором минимального значения: ";
    for (int i = 0; i < 10; i++)
        cout << minVal[i] << ' ';
    cout << endl;

    //Сортировка простым включением
    int turnOn[10]{ 3, 5, 1, 44, 2, 8, 45, 12, 0, 7 }, size3 = 10;
    for (int i = 1; i < size3; i++) {
        int j = i - 1;
        while ((j >= 0) && (turnOn[i] > turnOn[j])) {
            j -= 1;
        }
        j += 1;

        int temp = turnOn[i];

        for (int k = i; k > j; k--)
            turnOn[k] = turnOn[k - 1];
        turnOn[j] = temp;
    }
    cout << endl << "Сортировка простым включением: ";
    for (int i = 0; i < 10; i++)
        cout << turnOn[i] << ' ';
    cout << endl;

    return 0;
}
