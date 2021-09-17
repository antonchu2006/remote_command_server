/*************************************************************************************/
/* @file    client_1.c                                                               */
/* @brief   This clients connects,                                                   */
/*          sends a text, reads what server and disconnects                          */
/*************************************************************************************/
#include <stdbool.h>
#include <netdb.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h> 
#include <unistd.h>

#define SERVER_ADDRESS  "192.168.0.18"     /* server IP */
#define PORT            8080

/* Test sequences */
                    /* receive buffer */
 
char buf_rx[100]; 
 
/* This clients connects, sends a text and disconnects */
int main() 
{ 
    

    char *buf_tx = malloc(sizeof(char) + 256);
    printf("bash $ ");
    /* scanf("%[^\n]", hello); */

    scanf("%[^\n]", buf_tx);
    

    int sockfd; 
    struct sockaddr_in servaddr; 
    
    /* Socket creation */
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) 
    { 
        printf("CLIENT: socket creation failed...\n"); 
        return -1;  
    } 
    /*
    else
    {
        printf("CLIENT: Socket successfully created..\n"); 
    }
    */
    
    memset(&servaddr, 0, sizeof(servaddr));

    /* assign IP, PORT */
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = inet_addr( SERVER_ADDRESS ); 
    servaddr.sin_port = htons(PORT); 
  
    /* try to connect the client socket to server socket */
    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) 
    { 
        printf("connection with the server failed...\n");  
        return -1;
    } 
    
    /* printf("connected to the server..\n"); */ 
  
    /* send test sequences*/
    write(sockfd, buf_tx, sizeof(buf_tx));     
    read(sockfd, buf_rx, sizeof(buf_rx));
    printf("%s \n", buf_rx);

    

    /* close the socket */
    close(sockfd);

    memset(buf_rx,0 ,sizeof(buf_rx));

    memset(buf_tx,0 ,sizeof(buf_tx));

    
} 