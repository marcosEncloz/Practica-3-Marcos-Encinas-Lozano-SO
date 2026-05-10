# Practica-3-Marcos-Encinas-Lozano-SO
Practica 2 Marcos Encinas Lozano Sistemas Operativos 10/5/26
# + REQUISITOS
Linux / WSL

Python 3 (para ejecutar el servidor)

g++ (compilador de C++)

Permisos de ejecución para ejecutar scripts .sh

Conexión local mediante sockets TCP/IP

# + ARCHIVOS PRINCIPALES
ServidorCamara.py  --  Servidor en Python que genera un array de 768 bytes y lo envía al cliente mediante un socket TCP.

cliente.cpp  --  Programa en C++ que se conecta al servidor, recibe los datos byte a byte y los almacena en un archivo de texto.

datos_recibidos.txt  --  Archivo generado automáticamente por el cliente con los 768 valores recibidos.

run_cliente.sh  --  Script en Bash que compila y ejecuta el cliente de forma automática.

# + COMO EJECUTAR LA PRACTICA
1. Ejecutar el servidor (Python):  
Debe hacerse en una terminal independiente.

  python3 ServidorCamara.py

El servidor deberia mostrar:  Servidor escuchando en 127.0.0.1:12345


2. Ejecutar el cliente (C++):  
En otra terminal distinta:

./run_cliente.sh

El script compila el cliente y lo ejecuta automáticamente.


3. Ver el archivo generado:
   
cat datos_recibidos.txt


# + SALIDA GENERADA
El archivo datos_recibidos.txt incluye:

· Los 768 bytes enviados por el servidor Python.

· Tres ciclos completos de valores entre 0 y 255.

· Cada valor en una línea independiente para facilitar su lectura.

Además, la terminal muestra:

· Mensaje de compilación del cliente.

· Conexión establecida correctamente.

· Impresión por pantalla de todos los bytes recibidos.
