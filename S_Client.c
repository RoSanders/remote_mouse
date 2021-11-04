#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define SIZE 1024
void write_fd(int sockfd);


void write_fd(int sockfd)
{
	int n;
	FILE *fp;
	char *filename = "recv.txt";
	char buffer[SIZE];
	
	fp = fopen(filename, "w");
	while(1){
		n = recv(sockfd, buffer, SIZE, 0);
		
		if(n <= 0){
			break;
			return;
			}
			printf(fp, "%s", buffer);
			bzero(buffer, SIZE);
		}
	return;
}	

int main() {
	
	
	
	/*create a socket*/
	int network_socket;
	network_socket = socket(AF_INET,SOCK_STREAM, 0);
	
	/*declare address for the socket*/
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9002);
	server_address.sin_addr.s_addr = INADDR_ANY;
	
	int connection_status = connect(network_socket, (struct sockaddr *) 		&server_address, sizeof(server_address));
	
	//check connection
	if(connection_status == -1)
	{
		printf("There was error making a connection to the remote socket 			\n\n");
	}
	//receive data
	char server_response[256];
	recv(network_socket, &server_response, sizeof(server_response), 0);
	
	//print data given from server
	printf("The server sent the data: %s\n", server_response);
	
	//TBA, puts data into text file
	FILE *rp;
	rp= fopen("data.txt", "w");
		fputs(server_response, rp);
	fclose(rp);	
	
	write_fd(socket);
	close(socket);
	return 0;
}

