
#include "Header.h"

#define PORT 8989
int main(){
    int server_fd,client_fd;
    int length=1;
    char buffer[1024];
    struct sockaddr_in server, client;
    socklen_t sin_size;
    
    //SOCKET 
    server_fd = socket(PF_INET,SOCK_STREAM,0);
    if(server_fd == -1){
        printf("[*]server_fd is Failed\n");
    }
    /*Assigning a ip port family*/ 
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = 0;
    // bind a ip:port
    if(bind(server_fd,(struct sockaddr*)&server,sizeof(struct sockaddr)) == -1){
        printf("[*]Bind is Failed\n");
        exit(-1);
    }

    /*listening  */

    if(listen(server_fd,5)==-1){
        printf("[*]Listening is Failed\n");
    }
    printf("listening Port [%d]\n",PORT);

    /*Accept the connection send and recive the message*/
    
    while(1){
        sin_size = sizeof(struct sockaddr_in);
        client_fd =  accept(server_fd,(struct sockaddr*)&client,&sin_size);
        if(client_fd == -1){
            exit(-1);
        }
        printf("Got a connection [%s] [%d]\n",inet_ntoa(client.sin_addr),ntohs(client.sin_port));
        send(client_fd,"Hellow World\n",14,0);
        length = recv(client_fd,&buffer,BUFSIZ,0);
        while (length>0)
        {
            printf("RECV LEN: %d\n",length);
            length = recv(client_fd,&buffer,BUFSIZ,0);

        }
        
        // while(length>0){
        //     printf("dai yan da mach");
        //     printf("Len of Byte : %d",length);
        //     length = recv(client_fd,&buffer,BUFSIZ,0);
        // }    
    }
}
