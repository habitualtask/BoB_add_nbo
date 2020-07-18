#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf
#include <netinet/in.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	FILE *fd1, *fd2;
	char buf[64];
	char buf2[64];
	uint32_t address1, address2;

	fd1=fopen(argv[1], "r");
	fd2=fopen(argv[2], "r");
	fgets(buf, 64, fd1);
       	fgets(buf2,64, fd2);
	
	address1=(uint32_t) strtoll(buf, NULL, 16);
	address2=(uint32_t) strtoll(buf, NULL, 16);

	address1 += address2;
	printf("%x\n", htonl(address1));
	fclose(fd2);
	fclose(fd1);
	return 0;	
}
