#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#define PORT 8080

DWORD WINAPI ClientHandler(LPVOID lpParam)
{
    SOCKET cliente_socket = (SOCKET)lpParam;
    char buffer[1024];
    int bytes;

    // Configurar timeout de recepción (30 segundos)
    int timeout = 30000;
    setsockopt(cliente_socket, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));

    printf("clientee conectado: %d\n", cliente_socket);

    while (1)
    {

        bytes = recv(cliente_socket, buffer, sizeof(buffer), 0);
        if (bytes > 0)
        {
            /* code */
            buffer[bytes] = '\0';
            printf("Mensaje recibido de %d: %s", cliente_socket, buffer);
            if (buffer[strlen(buffer) - 1] == '\n')
            {
                buffer[strlen(buffer) - 1] = '\0';
            }

            // Comando para cerrar conexión
            if (strcmp(buffer, "exit") == 0)
            {
                printf("Cliente %d solicitó cierre\n", cliente_socket);
                break;
            }

            // Responder eco
            if (send(cliente_socket, buffer, bytes, 0) == SOCKET_ERROR)
            {
                printf("Error al responder al cliente %d: %d\n", cliente_socket, WSAGetLastError());
                break;
            }
        }

        else
        {
            int error = WSAGetLastError();
            if (error == WSAETIMEDOUT)
            {
                printf("Timeout con cliente %d\n", cliente_socket);
            }
            else
            {
                printf("Cliente %d desconectado (Error: %d)\n", cliente_socket, error);
            }
            break;
        }
    }

    printf("clientee desconectado\n");
    closesocket(cliente_socket);
    return 0;
}

int main()
{
    printf("\t\t-------------- TCP SERVER --------------\n");
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);

    int server_fd, cliente_socket;
    struct sockaddr_in direccion;
    int addrsz = sizeof(direccion);
    char buffer[1024] = {0};

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
    {
        perror("Error en creacion de socket");
        
        exit(EXIT_FAILURE);
    }

    direccion.sin_family = AF_INET;
    direccion.sin_addr.s_addr = INADDR_ANY; // escucha cualquier IP
    direccion.sin_port = htons(PORT);       // puerto en el que escucha

    int si = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, (char *)&si, sizeof(si)); // Permite reutilizar el puerto

    if (bind(server_fd, (struct sockaddr *)&direccion, addrsz) < 0)
    {
        perror("Error en el bind");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0)
    {
        perror("Error en el listen");
        
        exit(EXIT_FAILURE);
    }

    printf("escuchando puerti %d\n", PORT);

    while (1)
    {
        SOCKET client = accept(server_fd, NULL, NULL);
        if (client == INVALID_SOCKET)
        {
            printf("Error en accept: %d\n", WSAGetLastError());
            continue;
        }

        CreateThread(NULL, 0, ClientHandler, (LPVOID)client, 0, NULL);
    }
    

    printf("Cerrando servidor...\n");
    closesocket(server_fd);
    WSACleanup();

    return 0;
}
