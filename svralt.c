#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>

int main(){
    //criar buffs(recebem e enviam mensagens)
    char recvbuff[2000];
    char sendbuff[2000];

    //parametros do socket1
    struct sockaddr_in sckPC;
    //paramentros socket2
    struct sockaddr_in sckino;

    sckPC.sin_family = AF_INET;//af_inet é o protocolo para se comunicar via internet.
    sckPC.sin_addr.s_addr = inet_addr("IP recebido");
    sckPC.sin_port = htons("porta");

    sckino.sin_family = AF_INET;
    sckino.sin_addr.s_addr = inet_addr("IP svrcliente");
    sckino.sin_port = htons("porta");

    
}