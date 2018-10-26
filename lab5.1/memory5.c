#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
	char *sm = (char *)0;
	printf("A read from null %s\n", sm);
	sprintf(sm, "A write to null\n");
	exit(EXIT_SUCCESS);
}