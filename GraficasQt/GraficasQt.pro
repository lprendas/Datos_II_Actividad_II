TEMPLATE = app
TARGET = programa

QT += core gui charts


# Archivos de cabecera (headers)
HEADERS += \
    ../src/sorting.h \
    ../src/DoublyLinkedList.h \
    ../src/binarySearch.h \
    ../src/BinarySearchTree.h \
    ../src/main.h

# Archivos fuente (cpp)
SOURCES += \
    ../src/main.cpp \
    ../src/sorting.cpp \
    ../src/DoublyLinkedList.cpp \
    ../src/binarySearch.cpp \
    ../src/BinarySearchTree.cpp

CONFIG += c++11
CONFIG += debug
QT += charts
