#include <stdlib.h>
#include <stdio.h>

#define kb (1024)

int main(){
	char *sm;
	int ec = EXIT_FAILURE;
	sm = (char *)malloc(kb);
	if(sm != NULL){
		free(sm);
		printf("Memory allocaed and freed again\n");
		ec = EXIT_SUCCESS;
	}
	exit(ec);
}