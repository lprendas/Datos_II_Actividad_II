#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include <QApplication>
#include <QMainWindow>
#include "main.h"
#include <iostream>
#include <vector>
#include <cstdlib>  // Para generar números aleatorios
#include <chrono>
#include <algorithm>

// Función que devuelve el tiempo actual en nanosegundos
long long getSystemTimeNano() {
    auto now = std::chrono::high_resolution_clock::now();
    auto duration = now.time_since_epoch();
    return std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count();
}

// Función para generar un arreglo de tamaño N con números aleatorios
std::vector<int> generateRandomArray(int N) {
    std::vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        arr[i] = rand() % 10000;  // Generar números aleatorios en el rango [0, 9999]
    }
    return arr;
}

int main() {
    std::srand(time(0));  // Inicializar la semilla de números aleatorios

    // Probar diferentes tamaños de N
    std::vector<int> N_values = {100, 1000, 5000, 10000, 20000};

    // Bucle para probar diferentes valores de N
    for (int N : N_values) {
        std::cout << "\nPruebas con N = " << N << std::endl;

        // Generar arreglo aleatorio de tamaño N
        std::vector<int> arr = generateRandomArray(N);

        // Medir tiempo de BubbleSort
        std::vector<int> arrCopy = arr;  // Copiar el arreglo para no modificar el original
        long long startTime = getSystemTimeNano();
        bubbleSort(arrCopy);
        long long endTime = getSystemTimeNano();
        std::cout << "Tiempo BubbleSort: " << (endTime - startTime) << " nanosegundos" << std::endl;

        // Medir tiempo de SelectionSort
        arrCopy = arr;  // Restaurar el arreglo original
        startTime = getSystemTimeNano();
        selectionSort(arrCopy);
        endTime = getSystemTimeNano();
        std::cout << "Tiempo SelectionSort: " << (endTime - startTime) << " nanosegundos" << std::endl;

        // Medir tiempo de MergeSort
        arrCopy = arr;  // Restaurar el arreglo original
        startTime = getSystemTimeNano();
        mergeSort(arrCopy, 0, arrCopy.size() - 1);
        endTime = getSystemTimeNano();
        std::cout << "Tiempo MergeSort: " << (endTime - startTime) << " nanosegundos" << std::endl;

        // Medir tiempo de inserción en lista doblemente enlazada
        DoublyLinkedList<int> list;
        startTime = getSystemTimeNano();
        for (int num : arr) {
            list.insertSorted(num);
        }
        endTime = getSystemTimeNano();
        std::cout << "Tiempo de inserción en Lista Doble Enlazada: " << (endTime - startTime) << " nanosegundos" << std::endl;

        // Medir tiempo de búsqueda binaria
        std::sort(arr.begin(), arr.end());  // Asegurarse de que el arreglo esté ordenado para búsqueda binaria
        startTime = getSystemTimeNano();
        int index = binarySearch(arr, arr[N / 2]);  // Buscar el elemento en la mitad del arreglo
        endTime = getSystemTimeNano();
        std::cout << "Tiempo Búsqueda Binaria: " << (endTime - startTime) << " nanosegundos" << std::endl;

        // Medir tiempo de inserción en Árbol Binario de Búsqueda
        BinarySearchTree<int> bst;
        startTime = getSystemTimeNano();
        for (int num : arr) {
            bst.insert(num);
        }
        endTime = getSystemTimeNano();
        std::cout << "Tiempo de inserción en Árbol Binario de Búsqueda: " << (endTime - startTime) << " nanosegundos" << std::endl;
    }

    return 0;
}
