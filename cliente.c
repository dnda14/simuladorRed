#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#define PORT 8080

int main()
{
    printf("\t\t-------------- TCP CLIENT --------------\n");
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);

    int cliente_socket;
    struct sockaddr_in serv_direccion;
    char buffer[1024] = {0};

    if ((cliente_socket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
    {
        perror("Error en creacion de socket");
        exit(EXIT_FAILURE);
    }

    serv_direccion.sin_family = AF_INET;
    serv_direccion.sin_port = htons(PORT); // puerto al que se conecta

    if(inet_pton(AF_INET, "127.0.0.1", &serv_direccion.sin_addr) <= 0) // IP del servidor
    {
        perror("direccion invalida");
        exit(EXIT_FAILURE);
    }
    if (connect(cliente_socket,(struct sockaddr *)&serv_direccion, sizeof(serv_direccion)) < 0)
    {
        perror("Error en el connect");
        exit(EXIT_FAILURE);
    }
    printf("Conectado al servidor en el puerto %d, escribe mensajes:\n", PORT);

    while (1)
    {
        printf("> ");
        fgets(buffer, sizeof(buffer), stdin);
        send(cliente_socket,buffer,strlen(buffer),0);
        recv(cliente_socket, buffer, sizeof(buffer), 0);
        printf("Eco: %s\n", buffer);
    }
    shutdown(cliente_socket, SD_SEND); // Indica que no se enviaran mas datos
    recv(cliente_socket, buffer, sizeof(buffer), 0); // Espera a recibir el eco final

    closesocket(cliente_socket);
    return 0;
    

}