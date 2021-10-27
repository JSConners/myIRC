#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h> 
#include <sys/sockets.h>

#include <netinet/in.h>



int main(){

	//this creates the socket 
	int socket; 
	socket = (AF_INET, SOCK_STREAM, 0); 

	//specificy the address for the socket
	struct sockaddr_in server_address; 
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9002);  
	server_address.sin_addr.s_addr = INADDR_ANY;


	//creates the connection with the specified IP address
	int connection_status = connect(socket, (struct sockaddr *) &server_address, sizeof(server_address));



	// error checking
	if (connection_status == -1){
		printf(stderr, "Failed to connect\n");
	}else
	printf("connected\n");

	// receive the data from the server
	char server_response[256];
	recv(socket, &server_response, sizeof(server_response), 0);

	// print the data from the server

	printf("The server sent the data:\n %s\n", server_response);


	// closes the socket
	close(socket);

	return 0; 

}