#include "sort_algorithms.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>

using namespace std;

void printArray(const vector<int>& arr, int highlight1, int highlight2, int sortedIndex) {
    for (int i = 0; i < arr.size(); i++) {
        if (i <= sortedIndex) cout << "\033[1;32m"; // green
        else if (i == highlight1 || i == highlight2) cout << "\033[1;31m"; // red
        cout << string(arr[i], '#') << "\033[0m" << "\n";
    }
    cout << string(30, '-') << "\n";
    this_thread::sleep_for(chrono::milliseconds(150));
}

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                printArray(arr, j, j + 1, n - i - 1);
            }
        }
    }
}

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            printArray(arr, j, i, i - 1);
            j--;
        }
        arr[j + 1] = key;
    }
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
            printArray(arr, i, j);
        }
    }
    swap(arr[i + 1], arr[high]);
    printArray(arr, i + 1, high);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
        printArray(arr, k, mid, k - 1);
    }

    while (i < n1) {
        arr[k++] = L[i++];
        printArray(arr, k, mid, k - 1);
    }

    while (j < n2) {
        arr[k++] = R[j++];
        printArray(arr, k, mid, k - 1);
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
