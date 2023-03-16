#include <iostream>
#include <chrono>
#include <limits>
#include <random>
using namespace std;
// Создание упорядоченного массива размера size, в котором будет проходить поиск
const int n = 1000000;
int arr[1000000];

void bubble_sort(int arr[], int size){
    for (int i = 0; i < size; i++){
            for (int j = size - 1; j > 0; j--){
                if (arr[j] > arr[j-1]){
                    int tmp = arr[j-1];
                    arr[j-1] = arr[j]; arr[j] = tmp;
                }
            }
        }
    }


void insert_sort(int arr[], int size){
    for (int i = 1; i < size; i++){
            int x = arr[i];
            for(int j = i-1; j >= 0; j--){
                if(x < arr[j]){int tmp = arr[j+1]; arr[j+1] = arr[j]; arr[j] = tmp;}
            }
        }
    }

void shaker_sort(int arr[], int size){
    int flag = size - 1;
	int left  = 0;
	int right = size - 1;
	// проходимся по массивы вправа, а потом влево, как в пузырьке, но убираем из сортировки готовые куски (flag)
	do {
		for (int i = left; i < right; i++) {
			if (arr[i] > arr[i + 1]){
                int tmp = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = tmp;
                flag = i;
			}
		}
		right = flag;
		for (int i = right; i > left; i--) {
			if (arr[i] < arr[i - 1]) {
                int tmp = arr[i-1];
                arr[i-1] = arr[i];
                arr[i] = tmp;
                flag = i;
			}
		}
		left = flag;
	} while (left < right);
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

        // три варианта сортировок
        //bubble_sort(arr, size);
        //insert_sort(arr, size);
        shaker_sort(arr, size);

        auto end = std::chrono::steady_clock::now();
        // конец отсчёта времени
        auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        time += time_span.count();
    }
    cout << time << ", ";

}


int main(){
    for (int size = 1000; size <= 10000; size += 500)
    {
        test(20, size);
    }
    return 0;
}
