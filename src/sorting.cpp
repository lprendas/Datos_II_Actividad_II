#include "sorting.h"
#include <algorithm>

template<typename T>
void bubbleSort(std::vector<T>& arr) {
    bool swapped;
    for (size_t i = 0; i < arr.size() - 1; i++) {
        swapped = false;
        for (size_t j = 0; j < arr.size() - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

template<typename T>
void selectionSort(std::vector<T>& arr) {
    for (size_t i = 0; i < arr.size() - 1; i++) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            std::swap(arr[i], arr[minIndex]);
        }
    }
}

template<typename T>
void merge(std::vector<T>& arr, int left, int mid, int right) {
    std::vector<T> leftArray(arr.begin() + left, arr.begin() + mid + 1);
    std::vector<T> rightArray(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left;
    while (i < leftArray.size() && j < rightArray.size()) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k++] = leftArray[i++];
        } else {
            arr[k++] = rightArray[j++];
        }
    }
    while (i < leftArray.size()) arr[k++] = leftArray[i++];
    while (j < rightArray.size()) arr[k++] = rightArray[j++];
}

template<typename T>
void mergeSort(std::vector<T>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Necesitamos instanciar plantillas para que el compilador genere código concreto
template void bubbleSort<int>(std::vector<int>&);
template void selectionSort<int>(std::vector<int>&);
template void mergeSort<int>(std::vector<int>&, int, int);
