#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include "get_next_line.h"

int main ()
{
	char *pippo;

	int fd = open("/Users/amerlino/Desktop/gnlTester/files/empty",  O_RDONLY);
sleep(30);
pippo = get_next_line( fd);
printf(">%s", pippo);


pippo = get_next_line( fd);
 printf("\n%s", pippo);
 pippo = get_next_line( fd);
 printf("\n%s", pippo);
 pippo = get_next_line( fd);
 printf("\n%s", pippo);
/* pippo = get_next_line( fd);
 printf("\n%s", pippo);
 pippo = get_next_line( fd);
 printf("\n%s", pippo);
 pippo = get_next_line( fd);
 printf("\n%s", pippo);
  pippo = get_next_line( fd);
 printf("\n%s", pippo);
 pippo = get_next_line( fd);
 printf("\n%s", pippo);
 pippo = get_next_line( fd);
 printf("\n%s", pippo);*/
}
