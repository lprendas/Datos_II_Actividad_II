# Nombre del proyecto
TEMPLATE = app
TARGET = programa

# Versión mínima requerida de Qt
QT += core gui charts

# Archivos de cabecera (headers)
HEADERS += \
    sorting.h \
    DoublyLinkedList.h \
    binarySearch.h \
    BinarySearchTree.h \
    main.h

# Archivos fuente (cpp)
SOURCES += \
    main.cpp \
    sorting.cpp \
    DoublyLinkedList.cpp \
    binarySearch.cpp \
    BinarySearchTree.cpp

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
