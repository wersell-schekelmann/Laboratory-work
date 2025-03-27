#include <iostream>
using namespace std;

void backward_step(unsigned arr[], unsigned const begin_idx, unsigned const end_idx) {
    for (unsigned i = end_idx; i > begin_idx; --i) {
        if (arr[i] < arr[i - 1]) {
            unsigned buff = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = buff;
        }
    }
}

void forward_step(unsigned arr[], unsigned const begin_idx, unsigned const end_idx) {
    for (unsigned i = begin_idx; i < end_idx; ++i) {
        if (arr[i] > arr[i + 1]) {
            unsigned buff = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = buff;
        }
    }
}

void shaker_sort (unsigned arr [], unsigned begin_idx, unsigned end_idx)
{
    //int l = 1;
    //int r = sizeof(arr)/sizeof(arr[0]) - 1;
    int l = begin_idx;
    int r = end_idx;
    int counter = 0;
    while (l < r){
        forward_step(arr, l, r);
        r --;
        backward_step(arr, l, r);
        l ++;
        counter ++;
        cout << "\nИтерация:" << counter;
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

    shaker_sort(A, 0,sze - 1); // сортировка

    cout << "\nМассив после сортировки:\n";
    for (int k = 0; k < sze; k++)
    {
        cout << A[k] << " | ";
    }
    cout << endl;
    system("PAUSE");
}
