#include <iostream>
#include <chrono>
#include <limits>
#include <random>
using namespace std;
// �������� �������������� ������� ������� size, � ������� ����� ��������� �����
const int n = 1000000;
int arr[1000000];
int temp[1000000]; // ������ ��� ������

// �������, �������� �������� ������� �������
void swap_us(int arr[], int i, int j)
{
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] =tmp;
}

// �������, ���������� ������
void print_arr(int arr[], int begining, int ending)
{
    for(int i = begining; i < ending; i++){cout << arr[i] << ' ';}
    cout << '\n';
}


int min_int(int a, int b)
{
    if(a < b){return a;}
    else{return b;}
}

// ������� ��������� ��� ��������������� ����� � ����
void merge_parts(int arr[], int begining, int center, int ending)
{
    // ������� ����� �������� �����
    // ��������� �� ������ �� ������� �������� ����� ������� ��� �� ������� � ��������� ������ temp (��� ������ � ����� ������)
    int shift_l = 0;
    int shift_r = 0;
    int counter = 0;
    do{
        if(arr[begining + shift_l] < arr[center + shift_r]){temp[begining + counter] = arr[begining + shift_l]; shift_l++;}
        else{temp[begining + counter] = arr[center + shift_r]; shift_r++;}
        counter++;
    }while(shift_l < center - begining && shift_r < ending - center);
    // ����������� �������
    if(shift_l < center - begining)
        {
            for(int i = shift_l; i < center - begining; i++)
            {
                temp[begining + counter] = arr[begining + i];
                counter++;
            }
        }

    if(shift_r < ending - center)
    {
        for(int i = shift_r; i < ending - center; i++)
        {
            temp[begining + counter] = arr[center +i];
            counter++;
        }
    }
    //������������ � �������� ������ arr
    for(int i = begining; i < ending; i++){arr[i] = temp[i];}
}

// ������� � ������� ���� ������, ������� ������ � ������ ������������� ����� (����� � ����� �� �������!)
void merge_sort(int arr[], int begining, int ending)
{
    if(ending - begining > 1)
        {
            merge_sort(arr, begining, (begining + ending)/2);
            merge_sort(arr, (begining + ending)/2, ending);
            merge_parts(arr, begining, (begining + ending)/2, ending);
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
        //print_arr(arr, 0, size); //������ ��� ��������
        // �������� ����������
        merge_sort(arr, 0, size);
        //print_arr(arr, 0,  size); //������ ��� ��������
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

