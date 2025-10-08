#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "sort_algorithms.h"

using namespace std;

int main() {
    srand(time(0));
    vector<int> arr(5);
    for (int& x : arr) x = rand() % 8 + 1;

    cout << "Choose a sorting algorithm:\n";
    cout << "1. Bubble Sort\n2. Insertion Sort\n3. Quick Sort\n4. Merge Sort\n\n";
    int choice;
    cin >> choice;

    cout << "\nInitial array:\n";
    printArray(arr);

    switch (choice) {
        case 1: bubbleSort(arr); break;
        case 2: insertionSort(arr); break;
        case 3: quickSort(arr, 0, arr.size() - 1); break;
        case 4: mergeSort(arr, 0, arr.size() - 1); break;
        default: cout << "Invalid choice!\n"; return 0;
    }

    cout << "\n \u2714  Sorted array:\n";
    printArray(arr, -1, -1, arr.size() - 1);
}
