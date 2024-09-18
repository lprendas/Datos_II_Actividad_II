#include "binary_search.h"

template<typename T>
int binarySearch(const std::vector<T>& arr, T key) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

// Instanciamos la plantilla
template int binarySearch<int>(const std::vector<int>&, int);
