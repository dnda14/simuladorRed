#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <time.h>

#define PORT 8080
#define MAX_RETRIES 5
#define RETRY_DELAY 3 
char* get_current_time() {
    static char buffer[20]; // YYYY-MM-DD HH:MM:SS
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    // Guardar en formato legible
    snprintf(buffer, sizeof(buffer), "%04d-%02d-%02d %02d:%02d:%02d",
             t->tm_year + 1900,
             t->tm_mon + 1,
             t->tm_mday,
             t->tm_hour,
             t->tm_min,
             t->tm_sec);

    return buffer;
}

int connect_to_server(int *sock) {
    FILE *log = fopen("client.log", "a");
    
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("Dirección inválida\n");
        return -1;
    }

    for (int attempt = 1; attempt <= MAX_RETRIES; attempt++) {
        *sock = socket(AF_INET, SOCK_STREAM, 0);
        if (*sock == INVALID_SOCKET) {
            printf("Error creando socket: %d\n", WSAGetLastError());
            return -1;
        }

        if (connect(*sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == 0) {
            printf("¡Conectado al servidor!\n");
            return 0; // Éxito
        }

        printf("Intento %d/%d fallido. Reintentando en %d segundos...\n", 
               attempt, MAX_RETRIES, RETRY_DELAY);
        fprintf(log, "[%s] Intento de conexión fallido\n", get_current_time());
        closesocket(*sock);
        Sleep(RETRY_DELAY);
    }

    printf("No se pudo conectar después de %d intentos\n", MAX_RETRIES);
    fprintf(log, "[%s] Intento de conexión fallido\n", get_current_time());
    return -1;
}

int main()
{
    printf("\t\t-------------- TCP CLIENT --------------\n");
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);

    int cliente_socket;
    struct sockaddr_in serv_direccion;
    char buffer[1024] = {0};
    while (1)
    {
        if (connect_to_server(&cliente_socket) == 0)
        {
            while (1)
            {
                printf("> ");
                fgets(buffer, sizeof(buffer), stdin);

                if (send(cliente_socket,buffer,strlen(buffer),0)<=0)
                {
                    printf("Error al enviar datos al servidor (REconectando...): %d\n", WSAGetLastError());
                    closesocket(cliente_socket);
                    break; // Salir del bucle si hay error
                }
                
                
                int bytes = recv(cliente_socket, buffer, sizeof(buffer), 0);
                if (bytes <=0)
                {
                    printf("Error al recibir datos del servidor (REconectando...): %d\n", WSAGetLastError());
                    closesocket(cliente_socket);
                    break; // Salir del bucle si hay error
                }
                buffer[bytes] = '\0'; // Asegurarse de que el buffer es una cadena
                printf("Eco: %s\n", buffer);
            }
           
    
        }
        else
        {
            printf("No se pudo conectar al servidor.Reinciando...\n");
            Sleep(RETRY_DELAY * 1000); // Espera antes de reintentar
        }
        
    }
    
    WSACleanup();
    return 0;
    

}