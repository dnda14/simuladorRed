#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

#define PORT 8080

DWORD WINAPI ClientHandler(LPVOID lpParam) {
    SOCKET client = (SOCKET)lpParam;
    char buffer[1024];
    int bytes;

    // Configurar timeout de recepción (30 segundos)
    int timeout = 30000;
    setsockopt(client, SOL_SOCKET, SO_RCVTIMEO, (char*)&timeout, sizeof(timeout));

    while((bytes = recv(client, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes] = '\0';
        printf("Mensaje recibido: %s", buffer);
        send(client, buffer, bytes, 0);
    }

    printf("Cliente desconectado\n");
    closesocket(client);
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

    int si=1;
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

    while(1) {
        SOCKET client = accept(server_fd, NULL, NULL);
        if(client == INVALID_SOCKET) {
            printf("Error en accept: %d\n", WSAGetLastError());
            continue;
        }

        CreateThread(NULL, 0, ClientHandler, (LPVOID)client, 0, NULL);
    }
    if ((cliente_socket = accept(server_fd, (struct sockaddr *)&direccion, &addrsz)) < 0)
    {
        perror("Error en el accept");
        exit(EXIT_FAILURE);
    }
    while (1)
    {
        int bytes_recibidos = recv(cliente_socket, buffer, sizeof(buffer), 0);

        if (bytes_recibidos <= 0)
        {
            break;
        }
        printf("mesaje recibido: %s\n", buffer);
        send(cliente_socket, buffer, bytes_recibidos, 0);
        memset(buffer, 0, sizeof(buffer));
    }

    closesocket(cliente_socket);
    closesocket(server_fd);

    return 0;

}
