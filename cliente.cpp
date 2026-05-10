#include <iostream>
#include <vector>
#include <cstdint>
#include <arpa/inet.h>
#include <unistd.h>
#include <fstream>

// ===============================
// 1. Crear socket
// ===============================
int crearSocket() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        std::cerr << "Error al crear el socket" << std::endl;
        exit(1);
    }
    return sockfd;
}

// ===============================
// 2. Configurar dirección del servidor
// ===============================
sockaddr_in configurarServidor(const std::string& ip, int puerto) {
    struct sockaddr_in serv_addr{};
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(puerto);

    if (inet_pton(AF_INET, ip.c_str(), &serv_addr.sin_addr) <= 0) {
        std::cerr << "Direccion invalida o no soportada" << std::endl;
        exit(1);
    }

    return serv_addr;
}

// ===============================
// 3. Conectar al servidor
// ===============================
void conectarServidor(int sockfd, const sockaddr_in& serv_addr) {
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
        std::cerr << "Error al conectar" << std::endl;
        exit(1);
    }
}

// ===============================
// 4. Recibir datos (bytes)
// ===============================
std::vector<uint8_t> recibirDatos(int sockfd) {
    std::vector<uint8_t> datos;
    uint8_t buffer;

    while (recv(sockfd, &buffer, sizeof(buffer), 0) > 0) {
        datos.push_back(buffer);
    }

    return datos;
}

// ===============================
// 5. Guardar archivo
// ===============================
void guardarArchivo(const std::vector<uint8_t>& datos, const std::string& nombre) {
    std::ofstream file(nombre);

    if (!file) {
        std::cerr << "Error al abrir archivo para escritura" << std::endl;
        return;
    }

    for (uint8_t b : datos) {
        file << (int)b << "\n";
    }

    file.close();
}

// ===============================
// 6. Imprimir datos
// ===============================
void imprimirDatos(const std::vector<uint8_t>& datos) {
    std::cout << "Bytes recibidos:" << std::endl;

    for (uint8_t b : datos) {
        std::cout << (int)b << std::endl;
    }
}

// ===============================
// MAIN
// ===============================
int main() {
    int sockfd = crearSocket();
    sockaddr_in serv_addr = configurarServidor("127.0.0.1", 12345);
    conectarServidor(sockfd, serv_addr);

    std::vector<uint8_t> datos = recibirDatos(sockfd);

    guardarArchivo(datos, "datos_recibidos.txt");
    imprimirDatos(datos);

    close(sockfd);
    return 0;
}

