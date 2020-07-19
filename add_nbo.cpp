#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf
#include <netinet/in.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	FILE *fd1, *fd2;
	uint32_t buf;
	uint32_t buf2;

	fd1=fopen(argv[1], "rb");
	fd2=fopen(argv[2], "rb");
	
	fread(&buf,sizeof(buf),1,fd1);
       	fread(&buf2,sizeof(buf2),1, fd2);
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",htonl(buf),htonl(buf),htonl(buf2),htonl(buf2),htonl(buf)+htonl(buf2),htonl(buf)+htonl(buf2));
		
	fclose(fd2);
	fclose(fd1);
	return 0;	
}
