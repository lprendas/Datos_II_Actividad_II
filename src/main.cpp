#include "main.h"
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include <QApplication>
#include <QMainWindow>
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

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QMainWindow window;

    // Series para graficar los tiempos
    QtCharts::QLineSeries *bubbleSortSeries = new QtCharts::QLineSeries();
    bubbleSortSeries->setName("BubbleSort");

    QtCharts::QLineSeries *selectionSortSeries = new QtCharts::QLineSeries();
    selectionSortSeries->setName("SelectionSort");

    QtCharts::QLineSeries *mergeSortSeries = new QtCharts::QLineSeries();
    mergeSortSeries->setName("MergeSort");

    QtCharts::QLineSeries *listInsertSeries = new QtCharts::QLineSeries();
    listInsertSeries->setName("Lista Doble Enlazada - Inserción");

    QtCharts::QLineSeries *binarySearchSeries = new QtCharts::QLineSeries();
    binarySearchSeries->setName("Búsqueda Binaria");

    QtCharts::QLineSeries *bstInsertSeries = new QtCharts::QLineSeries();
    bstInsertSeries->setName("Árbol Binario de Búsqueda - Inserción");

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
        long long bubbleSortTime = endTime - startTime;
        bubbleSortSeries->append(N, bubbleSortTime);
        std::cout << "Tiempo BubbleSort: " << bubbleSortTime << " nanosegundos" << std::endl;

        // Medir tiempo de SelectionSort
        arrCopy = arr;  // Restaurar el arreglo original
        startTime = getSystemTimeNano();
        selectionSort(arrCopy);
        endTime = getSystemTimeNano();
        long long selectionSortTime = endTime - startTime;
        selectionSortSeries->append(N, selectionSortTime);
        std::cout << "Tiempo SelectionSort: " << selectionSortTime << " nanosegundos" << std::endl;

        // Medir tiempo de MergeSort
        arrCopy = arr;  // Restaurar el arreglo original
        startTime = getSystemTimeNano();
        mergeSort(arrCopy, 0, arrCopy.size() - 1);
        endTime = getSystemTimeNano();
        long long mergeSortTime = endTime - startTime;
        mergeSortSeries->append(N, mergeSortTime);
        std::cout << "Tiempo MergeSort: " << mergeSortTime << " nanosegundos" << std::endl;

        // Medir tiempo de inserción en lista doblemente enlazada
        DoublyLinkedList<int> list;
        startTime = getSystemTimeNano();
        for (int num : arr) {
            list.insertSorted(num);
        }
        endTime = getSystemTimeNano();
        long long listInsertTime = endTime - startTime;
        listInsertSeries->append(N, listInsertTime);
        std::cout << "Tiempo de inserción en Lista Doble Enlazada: " << listInsertTime << " nanosegundos" << std::endl;

        // Medir tiempo de búsqueda binaria
        std::sort(arr.begin(), arr.end());  // Asegurarse de que el arreglo esté ordenado para búsqueda binaria
        startTime = getSystemTimeNano();
        binarySearch(arr, arr[N / 2]);  // Buscar el elemento en la mitad del arreglo
        endTime = getSystemTimeNano();
        long long binarySearchTime = endTime - startTime;
        binarySearchSeries->append(N, binarySearchTime);
        std::cout << "Tiempo Búsqueda Binaria: " << binarySearchTime << " nanosegundos" << std::endl;

        // Medir tiempo de inserción en Árbol Binario de Búsqueda
        BinarySearchTree<int> bst;
        startTime = getSystemTimeNano();
        for (int num : arr) {
            bst.insert(num);
        }
        endTime = getSystemTimeNano();
        long long bstInsertTime = endTime - startTime;
        bstInsertSeries->append(N, bstInsertTime);
        std::cout << "Tiempo de inserción en Árbol Binario de Búsqueda: " << bstInsertTime << " nanosegundos" << std::endl;
    }

    // Crear el gráfico
    QtCharts::QChart *chart = new QtCharts::QChart();
    chart->addSeries(bubbleSortSeries);
    chart->addSeries(selectionSortSeries);
    chart->addSeries(mergeSortSeries);
    chart->addSeries(listInsertSeries);
    chart->addSeries(binarySearchSeries);
    chart->addSeries(bstInsertSeries);
    chart->setTitle("Tiempos de Ejecución de Algoritmos y Estructuras de Datos");

    // Ejes
    QtCharts::QValueAxis *axisX = new QtCharts::QValueAxis();
    axisX->setTitleText("Tamaño del Arreglo (N)");
    axisX->setLabelFormat("%i");
    chart->addAxis(axisX, Qt::AlignBottom);

    QtCharts::QValueAxis *axisY = new QtCharts::QValueAxis();
    axisY->setTitleText("Tiempo de Ejecución (ns)");
    chart->addAxis(axisY, Qt::AlignLeft);

    // Asociar las series a los ejes
    bubbleSortSeries->attachAxis(axisX);
    bubbleSortSeries->attachAxis(axisY);
    selectionSortSeries->attachAxis(axisX);
    selectionSortSeries->attachAxis(axisY);
    mergeSortSeries->attachAxis(axisX);
    mergeSortSeries->attachAxis(axisY);
    listInsertSeries->attachAxis(axisX);
    listInsertSeries->attachAxis(axisY);
    binarySearchSeries->attachAxis(axisX);
    binarySearchSeries->attachAxis(axisY);
    bstInsertSeries->attachAxis(axisX);
    bstInsertSeries->attachAxis(axisY);

    // Mostrar el gráfico
    QtCharts::QChartView *chartView = new QtCharts::QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    window.setCentralWidget(chartView);
    window.resize(800, 600);
    window.show();

    return app.exec();
}
