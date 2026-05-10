#!/bin/bash

echo "=============================="
echo " Compilando cliente C++..."
echo "=============================="

g++ cliente.cpp -o cliente

if [ $? -ne 0 ]; then
    echo "Error: la compilación falló."
    exit 1
fi

echo "Compilación exitosa."
echo ""

echo "=============================="
echo " Ejecutando cliente..."
echo "=============================="

./cliente

echo ""
echo "=============================="
echo " Ejecución finalizada."
echo " Archivo generado: datos_recibidos.txt"
echo "=============================="
