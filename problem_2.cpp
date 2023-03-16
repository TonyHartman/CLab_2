#include <iostream>
#include <chrono>
#include <limits>
#include <random>
using namespace std;
// Создание упорядоченного массива размера size, в котором будет проходить поиск
const int n = 1000000;
int arr[1000000];

// функция, меняющая элементы массива местами
void swap_us(int arr[], int i, int j)
{
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] =tmp;
}

// функция, печатающая массив
void print_arr(int arr[], int size)
{
    for(int i = 0; i < size; i++){cout << arr[i] << ' ';}
    cout << '\n';
}

// создание кучи (бинарного дерева) из  первых m элементов массива arr[] с корнем в i элементе arr[]
void heapify_first_time(int arr[], int m, int i)
{
    // корень бинарного дерева arr[i]
    // правый лист arr[2*i + 1]
    // левый лист arr[2*i + 2]
    if(2*i + 1 < m){heapify_first_time(arr, m, 2*i + 1);}
    if(2*i + 2 < m){heapify_first_time(arr, m, 2*i + 2);}

    // если лист - это корень ничего не делаем
    // иначе сравниваем листья и корень с листьями, при необходимости меняем их местами
    if((2*i + 2) < m && arr[2*i + 1] < arr[2*i + 2]){swap_us(arr, 2*i + 1, 2*i + 2); heapify_first_time(arr, m, 2*i + 2);}
    if((2*i + 1) < m && arr[i] < arr[2*i + 1]){swap_us(arr, i, 2*i + 1); heapify_first_time(arr, m, 2*i + 2);}
    if((2*i + 2) < m && arr[2*i + 1] < arr[2*i + 2]){swap_us(arr, 2*i + 1, 2*i + 2); heapify_first_time(arr, m, 2*i + 2);}
    // мы добились порядка: корень самый большой, левый лист больше правого
}

void heapify(int arr[], int m, int i)
{
    int j = i;
    do{
    // если лист - это корень ничего не делаем
    // иначе сравниваем листья и корень с листьями, при необходимости меняем их местами
    if((2*j + 2) < m && arr[2*j + 1] < arr[2*j + 2]){swap_us(arr, 2*j + 1, 2*j + 2);}
    if((2*j + 1) < m && arr[j] < arr[2*j + 1]){swap_us(arr, j, 2*j + 1); j = 2*j + 1;}
    if((2*j + 2) < m && arr[2*j + 1] < arr[2*j + 2]){swap_us(arr, 2*j + 1, 2*j + 2); j = 2*j + 2;}
    else{break;}
    }while(2*j + 1 < m);
    // мы добились порядка: корень самый большой, левый лист больше правого
}

void heap_sort(int arr[], int size)
{
    heapify_first_time(arr, size, 0);
    swap_us(arr, 0, size - 1);
    for(int i = size - 2; i > 1; i--)
        {
            heapify(arr, i, 0);
            swap_us(arr, 0, i);
        }
}


//Количество поисков, массив и его размер
void test(unsigned repeat, int size){
    int time = 0;
    std::default_random_engine rnd(228);
    std::uniform_int_distribution<unsigned> dstr(0, size); // случайное заполнение массива
    for (unsigned counter = repeat; counter != 0; --counter){
        for (unsigned i = 0; i != n; i++){arr[i] = size - i;}
        // начало отсчёта времени
        auto begin = std::chrono::steady_clock::now();
        //print_arr(arr, size); //принты для проверки
        // варианты сортировок
        heap_sort(arr, size);
        //print_arr(arr, size); //принты для проверки
        auto end = std::chrono::steady_clock::now();
        // конец отсчёта времени
        auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        time += time_span.count();
    }
    cout << time << ", ";

}


int main(){
    for (int size = 20000; size <= 50000; size += 1000)
    {
        test(20, size);
    }
    return 0;
}
