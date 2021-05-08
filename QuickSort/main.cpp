#include "utilities.h"
#include <iostream>
#include <chrono>

using namespace std::chrono;

int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1);

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            ++i; // increment index of smaller element
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int *arr = read_array();
    auto start = high_resolution_clock::now();
    quickSort(arr, 1, arr[0]);
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
