#include "../utilities.h"
#include <iostream>
#include <chrono>

using namespace std::chrono;

void insertionSort(int arr[])
{
    int i, key, j;
    for (i = 2; i <= arr[0]; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j > 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int *arr = read_array();
    auto start = high_resolution_clock::now();
    insertionSort(arr);
    auto stop = high_resolution_clock::now();
    if(check_array(arr)){
        auto duration = duration_cast<microseconds>(stop - start);
        std::cout << duration.count() << " microseconds\n";
        std::cout << duration.count() / 1000 << " milliseconds\n";
        std::cout << duration.count() / 1000 / 1000 << " seconds\n";
        std::cin.get();
        return 0;
    }
    else{
        return 1;
    }
}
