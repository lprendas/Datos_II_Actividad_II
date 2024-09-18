#ifndef SORTING_H
#define SORTING_H

#include <vector>

template<typename T>
void bubbleSort(std::vector<T>& arr);

template<typename T>
void selectionSort(std::vector<T>& arr);

template<typename T>
void mergeSort(std::vector<T>& arr, int left, int right);

#endif // SORTING_H
