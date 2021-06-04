#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 25

int main(){
	int fd;
	char *myfifo = "/tmp/myfifo";
	char msg[BUFFER_SIZE];
	
	//make command pipe
	mkfifo(myfifo, 0644);

while (1){
	printf("Enter command: ");
	scanf("%s", msg);
	
	//Open command pipe and write what was scanned
	fd = open(myfifo, O_WRONLY);
	write(fd, msg, sizeof(msg));
	
	//If what was scanned was "quit", then exit loop
	if(strcmp("quit", msg) == 0){
		break;
	}
}	
//close command pipe
close(fd);
return 0;
}
