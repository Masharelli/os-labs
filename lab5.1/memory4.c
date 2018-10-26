
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


#define KB (1024)

int main(){
	char *sm;
	char *sp;
	sm = (char *)malloc(KB);
	if(sm == NULL) exit(EXIT_FAILURE);
	sp = sm;
	while(1){
		*sp = '\0';
		sp++;
	}
	exit(EXIT_SUCCESS);
}