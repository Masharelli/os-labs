#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define mega (1024*1024)

int main(void) {

	char *sm;
	int mb = mega;
	int ec = EXIT_FAILURE;

	sm = (char *)malloc(mb);
	if(sm != NULL){
		sprintf(sm, "Hola\n");
		printf("%s", sm);
		ec= EXIT_SUCCESS;
	}

	exit(ec);

}