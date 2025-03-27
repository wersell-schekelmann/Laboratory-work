#include <iostream>
#include <chrono>
#include <random>
#include <vector>
using namespace std;

 chek(unsigned long long arr[], unsigned long long n, unsigned long long step, unsigned long long counter[]){
    bool swapped = false;
    for (unsigned long long i = 0; i + step < n; i += step) {
        if (arr[i] > arr[i + step]) {
            swap(arr[i], arr[i + step]);
            counter[0] += 1;
            swapped = true;
            }
        }
    return swapped;
}

void HairbrushSort(unsigned long long arr[], unsigned long long n, unsigned long long counter[]) {
    bool swapped = true;
    unsigned long long step = n / 2;


    while (step > 1 || swapped == true){
            if (step < 1){
            step = 1;
            }
            swapped = chek(arr, n, step, counter);

            step /= 2;
    }
}

int main()
{
    setlocale(LC_ALL, "rus");


    vector<unsigned long long> v = {};
    vector<unsigned long long> cou = {};

    for (long long i = 0; i <= 10000; i += 100){

        unsigned long long sze = i;
        //cout << "–азмер массива: ";
        //cin >> sze;
        unsigned long long *A = new unsigned long long[sze];

        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dist(0, 1000);

        for (unsigned long long k = 0; k < sze; k++)
        {
            A[k] = dist(gen); // запись случайных значений целых чисел в массив
            //cout << A[k] << " | ";
        }

        unsigned long long midval = 0;
        unsigned long long permut = 0;

        for (int j = 0; j < 10; ++j){
            int sc = 1;
            unsigned long long *counter = new unsigned long long[sc];
            counter[0] = 0;

            auto begin = chrono::steady_clock::now();
            HairbrushSort(A, sze, counter); // сортировка
            auto end = chrono::steady_clock::now();

            auto time_span = chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
            midval += time_span.count();

            permut += counter[0];
            //cout << "\n\n";
            //cout << time_span.count() << endl;
        }
        midval /= 10;
        permut /= 10;

        //cout << midval << endl;
        v.push_back(midval);
        cou.push_back(permut);
    }

    for (int i = 0; i < v.size(); ++ i){
        cout << v[i] << ',';
    }
    cout << endl;
    for (int i = 0; i < cou.size(); ++ i){
        cout << cou[i] << ',';
    }

    cout << "\n оличество переставлений при сортировке:\n";
    //for (unsigned long long k = 0; k < sze; k++)
    //{
    //    cout << A[k] << " | ";
    //}
    //cout << counter[0] << endl;
    //measure_time(HairbrushSort, A, sze);

    system("PAUSE");
}
