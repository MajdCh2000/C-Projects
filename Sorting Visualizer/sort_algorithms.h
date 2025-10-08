#ifndef SORT_ALGORITHMS_H
#define SORT_ALGORITHMS_H

#include <vector>

void printArray(const std::vector<int>& arr, int highlight1 = -1, int highlight2 = -1, int sortedIndex = -1);
void bubbleSort(std::vector<int>& arr);
void insertionSort(std::vector<int>& arr);
void quickSort(std::vector<int>& arr, int low, int high);
int partition(std::vector<int>& arr, int low, int high);
void mergeSort(std::vector<int>& arr, int left, int right);
void merge(std::vector<int>& arr, int left, int mid, int right);

#endif
