/*  Make the necessary includes and set up the variables.  */

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct{
	char operation;
	int valores[10];
} pack;


int main()
{
    int server_sockfd, client_sockfd;
    int server_len, client_len;
    struct sockaddr_un server_address;
    struct sockaddr_un client_address;

/*  Remove any old socket and create an unnamed socket for the server.  */

    unlink("server_socket");
    server_sockfd = socket(AF_UNIX, SOCK_STREAM, 0);

/*  Name the socket.  */

    server_address.sun_family = AF_UNIX;
    strcpy(server_address.sun_path, "server_socket");
    server_len = sizeof(server_address);
    bind(server_sockfd, (struct sockaddr *)&server_address, server_len);

/*  Create a connection queue and wait for clients.  */

    listen(server_sockfd, 5);
    while(1) {
        char ch;

        printf("server waiting\n");

/*  Accept a connection.  */

        client_len = sizeof(client_address);
        client_sockfd = accept(server_sockfd, 
            (struct sockaddr *)&client_address, &client_len);

/*  We can now read/write to client on client_sockfd.  */

	//read(client_sockfd, &ch, 1);
	pack p;
	read(client_sockfd, &p, sizeof(pack));
	int resta = 0;
	int i = 0;
	if(p.operation == '+'){
		for(i=0;i<10;i++){
			resta = resta + p.valores[i];
		}
	}
	else if(p.operation == '-'){
		for(i=0;i<10;i++){
			resta = resta - p.valores[i];
		}
	}
	else if(p.operation == '*'){
		resta = 1;
		for(i=0;i<10;i++){
			resta = resta * p.valores[i];
		}
	}
	else{
		printf("Server: Invalid Operation \n");	
	}


	printf("Server - Resultado: %d \n", resta);


	//printf("server: recived from client operator: %c \n", p.operation);
	//printf("server: recived from client: %d \n", p.valores[2]);
        //ch++;
       // write(client_sockfd, &ch, 1);
        close(client_sockfd);
    }
}
