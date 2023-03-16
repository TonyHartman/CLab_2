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

void comb_sort(int arr[], int size)
{
    for(int dist = size - 1; dist >= 1; dist = dist / 1.247) // 1.247 ��� ����������� ������
    {
        for(int i = 0; i + dist < size; i++)
        {
            if(arr[i] > arr[i + dist]){swap_us(arr, i, i + dist);}
        }
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
        comb_sort(arr, size);
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
