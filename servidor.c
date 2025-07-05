#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

#define PORT 8080

int main()
{
    printf("\t\t-------------- TCP SERVER --------------\n");

    int server_fd, cliente_cocket;
    struct sockaddr_in address;
    int addrsz = sizeof(address);
    char buffer[1024] = {0};

    if (server_fd = socket(AF_INET, SOCK_STREAM, 0))
    {
        perror("Error en creacion de socket");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; // escucha cualquier IP
    address.sin_port = htons(PORT);       // puerto en el que escucha

    if (bind(server_fd, (struct sockaddr *)&address, addrsz) < 0)
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
    if ((cliente_cocket = accept(server_fd, (struct sockaddr *)&address, (struct socklen_t *)&addrsz)) < 0)
    {
        perror("Error en el accept");
        exit(EXIT_FAILURE);
    }
    While(1)
    {
        int bytes_recibidos = recv(cliente_cocket, buffer, sizeof(buffer), 0);
        if (bytes_recibidos <= 0)
            ;
        {
            break;
        }
        printf("mesaje recibido: %s\n", buffer);
        send(client_socket, buffer, bytesrecibidos, 0);
        memset(buffer, 0, sizeof(buffer));
    }
    close(cliente_cocket);
    close(server_fd);
    return 0;
}
}
