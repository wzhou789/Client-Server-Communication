#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main()
{
	int fd;
	char *myfifo = "/tmp/myfifo";	
	
	char read_msg[BUFFER_SIZE];	
	
	//Make command pipe
	mkfifo(myfifo, 0644);

while (1){	
	//Open command pipe and read
	fd = open(myfifo, O_RDONLY);
	read(fd, read_msg, BUFFER_SIZE);
	
	//Return different responses depending on what 	was read
	if (strcmp("knock", read_msg) == 0){
		printf("Who's there?\n");
	}
	else if (strcmp("greet", read_msg) == 0){
		printf("Nice to see you!\n");
	} //if read "quit", then exit loop
	else if (strcmp("quit", read_msg) == 0){
		printf("Goodbye\n");	
		break;
	}
	memset(read_msg, 0, sizeof(read_msg));
}
//close command pipe
close(fd);

return 0;
}
