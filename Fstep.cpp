#include <iostream>
using namespace std;

void forward_step(unsigned arr[], unsigned const begin_idx, unsigned const end_idx) {
    for (unsigned i = begin_idx; i < end_idx; ++i) {
        if (arr[i] > arr[i + 1]) {
            unsigned buff = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = buff;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "rus");

    int sze = 0;
    cout << "Размер массива: ";
    cin >> sze;
    unsigned *A = new unsigned[sze];

    for (int k = 0; k < sze; k++)
    {
        A[k] = sze - k; // запись значений по убыванию
        cout << A[k] << " | ";
    }

    forward_step(A, 0,sze - 1); // сортировка

    cout << "\nМассив после сортировки:\n";
    for (int k = 0; k < sze; k++)
    {
        cout << A[k] << " | ";
    }
    cout << endl;
    system("PAUSE");
}
