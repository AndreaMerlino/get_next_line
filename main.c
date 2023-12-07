#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include "get_next_line.h"

int main ()
{
	char *pippo;

	int fd = open("gnlTester/files/42_no_nl",  O_RDONLY);

pippo = get_next_line( fd);
printf(">%s", pippo);

pippo = get_next_line( fd);
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
 printf("\n%s", pippo);
  pippo = get_next_line( fd);
 printf("\n%s", pippo);
 pippo = get_next_line( fd);
 printf("\n%s", pippo);
 pippo = get_next_line( fd);
 printf("\n%s", pippo);
}
