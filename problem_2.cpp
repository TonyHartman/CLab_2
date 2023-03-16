#include <iostream>
#include <chrono>
#include <limits>
#include <random>
using namespace std;
// �������� �������������� ������� ������� size, � ������� ����� ��������� �����
const int n = 1000000;
int arr[1000000];

// �������, �������� �������� ������� �������
void swap_us(int arr[], int i, int j)
{
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] =tmp;
}

// �������, ���������� ������
void print_arr(int arr[], int size)
{
    for(int i = 0; i < size; i++){cout << arr[i] << ' ';}
    cout << '\n';
}

// �������� ���� (��������� ������) ��  ������ m ��������� ������� arr[] � ������ � i �������� arr[]
void heapify_first_time(int arr[], int m, int i)
{
    // ������ ��������� ������ arr[i]
    // ������ ���� arr[2*i + 1]
    // ����� ���� arr[2*i + 2]
    if(2*i + 1 < m){heapify_first_time(arr, m, 2*i + 1);}
    if(2*i + 2 < m){heapify_first_time(arr, m, 2*i + 2);}

    // ���� ���� - ��� ������ ������ �� ������
    // ����� ���������� ������ � ������ � ��������, ��� ������������� ������ �� �������
    if((2*i + 2) < m && arr[2*i + 1] < arr[2*i + 2]){swap_us(arr, 2*i + 1, 2*i + 2); heapify_first_time(arr, m, 2*i + 2);}
    if((2*i + 1) < m && arr[i] < arr[2*i + 1]){swap_us(arr, i, 2*i + 1); heapify_first_time(arr, m, 2*i + 2);}
    if((2*i + 2) < m && arr[2*i + 1] < arr[2*i + 2]){swap_us(arr, 2*i + 1, 2*i + 2); heapify_first_time(arr, m, 2*i + 2);}
    // �� �������� �������: ������ ����� �������, ����� ���� ������ �������
}

void heapify(int arr[], int m, int i)
{
    int j = i;
    do{
    // ���� ���� - ��� ������ ������ �� ������
    // ����� ���������� ������ � ������ � ��������, ��� ������������� ������ �� �������
    if((2*j + 2) < m && arr[2*j + 1] < arr[2*j + 2]){swap_us(arr, 2*j + 1, 2*j + 2);}
    if((2*j + 1) < m && arr[j] < arr[2*j + 1]){swap_us(arr, j, 2*j + 1); j = 2*j + 1;}
    if((2*j + 2) < m && arr[2*j + 1] < arr[2*j + 2]){swap_us(arr, 2*j + 1, 2*j + 2); j = 2*j + 2;}
    else{break;}
    }while(2*j + 1 < m);
    // �� �������� �������: ������ ����� �������, ����� ���� ������ �������
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


//���������� �������, ������ � ��� ������
void test(unsigned repeat, int size){
    int time = 0;
    std::default_random_engine rnd(228);
    std::uniform_int_distribution<unsigned> dstr(0, size); // ��������� ���������� �������
    for (unsigned counter = repeat; counter != 0; --counter){
        for (unsigned i = 0; i != n; i++){arr[i] = size - i;}
        // ������ ������� �������
        auto begin = std::chrono::steady_clock::now();
        //print_arr(arr, size); //������ ��� ��������
        // �������� ����������
        heap_sort(arr, size);
        //print_arr(arr, size); //������ ��� ��������
        auto end = std::chrono::steady_clock::now();
        // ����� ������� �������
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
