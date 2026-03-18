#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORTA 8080

int main()
{
    int socket_servidor, socket_cliente;
    struct sockaddr_in endereco;
    int tamanho_endereco = sizeof(endereco);

    char buffer_requisicao[30000] = {0};
    char *resposta_http =
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/plain\r\n"
        "\r\n"
        "Olá, mundo!";

    // Criar socket
    socket_servidor = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_servidor == 0)
    {
        perror("Erro ao criar socket");
        exit(EXIT_FAILURE);
    }

    // Configurar endereço
    endereco.sin_family = AF_INET;
    endereco.sin_addr.s_addr = INADDR_ANY;
    endereco.sin_port = htons(PORTA);

    // Associar porta ao socket (bind)
    if (bind(socket_servidor, (struct sockaddr *)&endereco, sizeof(endereco)) < 0)
    {
        perror("Erro no bind");
        exit(EXIT_FAILURE);
    }

    // Colocar em modo de escuta
    if (listen(socket_servidor, 3) < 0)
    {
        perror("Erro no listen");
        exit(EXIT_FAILURE);
    }

    printf("Servidor rodando em http://localhost:%d\n", PORTA);

    while (1)
    {
        // Aceitar conexão
        socket_cliente = accept(socket_servidor, (struct sockaddr *)&endereco, (socklen_t *)&tamanho_endereco);

        // Ler requisição
        read(socket_cliente, buffer_requisicao, 30000);
        printf("Requisição recebida:\n%s\n", buffer_requisicao);

        // Enviar resposta
        if (strstr(buffer_requisicao, "GET / ") != NULL)
        {
            char *resposta =
                "HTTP/1.1 200 OK\r\n"
                "Content-Type: text/plain\r\n"
                "\r\n"
                "Página inicial";

            write(socket_cliente, resposta, strlen(resposta));
        }
        else if (strstr(buffer_requisicao, "GET /sobre") != NULL)
        {
            char *resposta =
                "HTTP/1.1 200 OK\r\n"
                "Content-Type: text/plain\r\n"
                "\r\n"
                "Página sobre";

            write(socket_cliente, resposta, strlen(resposta));
        }
        else
        {
            char *resposta =
                "HTTP/1.1 404 Not Found\r\n"
                "Content-Type: text/plain\r\n"
                "\r\n"
                "Rota não encontrada";

            write(socket_cliente, resposta, strlen(resposta));
        }

        // Fechar conexão
        close(socket_cliente);
    }

    return 0;
}
