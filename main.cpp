#include "sorting.h"
#include "doubly_linked_list.h"
#include "binary_search.h"
#include "binary_search_tree.h"
#include <vector>
#include <iostream>

int main() {
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

    // Prueba BubbleSort
    bubbleSort(arr);
    std::cout << "BubbleSort: ";
    for (int num : arr) std::cout << num << " ";
    std::cout << std::endl;

    // Prueba SelectionSort
    selectionSort(arr);
    std::cout << "SelectionSort: ";
    for (int num : arr) std::cout << num << " ";
    std::cout << std::endl;

    // Prueba MergeSort
    mergeSort(arr, 0, arr.size() -
