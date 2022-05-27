#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>

int main(){
    //criar buffs(recebem e enviam mensagens)
    char recvbuff[20000];
    char sendbuff[20000];

    WSADATA wsa;

    WSAStartup(MAKEWORD(2,0),&wsa);

    //parametros do socket1(receber do client))
    struct sockaddr_in sckPC;
    //paramentros socket2(enviar pro arduino)
    struct sockaddr_in sckino;

    //client
    sckPC.sin_family = AF_INET;//af_inet é o protocolo para se comunicar via internet.
    sckPC.sin_addr.s_addr = inet_addr("8.8.8.8");
    sckPC.sin_port = htons(75);

    //server
    sckino.sin_family = AF_INET;
    sckino.sin_addr.s_addr = inet_addr("IP arduino");
    sckino.sin_port = htons(80);

    //server para outros projetos
    int server1 = socket(AF_INET, SOCK_STREAM, 0);
    int bind( server1,((struct sockaddr *)&sckPC), (sizeof(sckPC))); 
    listen(server1,1);
    int server2 = socket(AF_INET, SOCK_STREAM,0);
    int bind(server2,((struct sockaddr *)&sckino), (sizeof(sckino)));


    int client,rx;
    const char* resp[3];
    int* clsize  = sizeof(sckPC); //pois a função accept so aceita int*

    printf("connect to server?\n");
    scanf("%s", resp);
    while((resp != "não")||(resp != "nao")){
        
        client = accept(server1,((struct sockaddr *)&sckPC), &clsize);
        rx = recv(client, recvbuff, sizeof(recvbuff),0 );

        sendbuff = recvbuff;
        send(server2, (sendbuff),sizeof(sendbuff),0);
        puts(sendbuff);
    }

    closesocket(client);

    return 0;
}