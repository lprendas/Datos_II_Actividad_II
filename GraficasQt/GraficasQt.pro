# Nombre del proyecto
TEMPLATE = app
TARGET = programa

# Versión mínima requerida de Qt
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

# Configuración para compilar en modo C++11 o superior
CONFIG += c++11

# Incluir directorios adicionales si es necesario
INCLUDEPATH += .

# Archivos de recursos o recursos de UI (si los necesitas en el futuro)
# RESOURCES += resources.qrc

# Habilitar el depurador (opcional, para pruebas)
CONFIG += debug

# Añadir otras librerías de Qt necesarias, en este caso Qt Charts
QT += charts
