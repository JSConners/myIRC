#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h> 
#include <sys/socket.h>

#include <netinet/in.h>



int main(){


	char server_message[256] = "You win! What do I win? Nothing!";

	//create the socket
	int socket; 
	socket = (AF_INET, SOCK_STREAM, 0);

	//specify the address for the socket
	struct sockaddr_in server_address; 
	server_address.sin_family = AF_INET; 
	server_address.sin_port = htons(9002);
	server_address.sin_addr.s_addr = INADDR_ANY; 


	// bind the socket to the specified IP and port

	bind(socket, (struct sockaddr *) &server_address, sizeof(server_address));

	listen(socket, 100);

	int client_socket; 

	// the 1st null is a struct to get the client IP address, ignoring this because we are using local host
	client_socket = accept(socket, NULL, NULL);

	//sends the data in the message to the client
	send(client_socket, server_message, sizeof(server_message), 0);

	close(socket);

	return 0; 
}