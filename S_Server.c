#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {


	/*open file to server*/
	FILE *comm_data;
	comm_data = fopen("comment.txt", "r");
	
	char response_data[1024];
	fgets(response_data, 1024, comm_data);
	
	char http_header[2048] = "HTTP/1.1 200 OK\r\n\n";
	strcat(http_header, response_data);
	
	
	char server_message[256] = "You have reached the server";
	
	/*create server socket*/
	int server_socket;
	server_socket = socket(AF_INET, SOCK_STREAM, 0);
	
	/*declare server address */
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9002);
	server_address.sin_addr.s_addr = INADDR_ANY;
	
	//bind the socket 
	bind(server_socket, (struct sockaddr*) &server_address, 	
	sizeof(server_address));
	
	listen(server_socket, 5);
	
	int client_socket;
	
	while(1) {
		client_socket = accept(server_socket, NULL, NULL);
		/*send*/
		send(client_socket, http_header, sizeof(http_header),0);
		close(server_socket);
	}
	
	
	
	
	return 0;
}
	
	