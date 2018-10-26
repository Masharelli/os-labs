
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define meg (1024)

int main(){
	char *sm;
	int sta = meg;
	int mo = 0;
	int ko = 0;
	while(1){
		for(ko = 0; ko < 1024; ko++){
			sm = (char *)malloc(sta);
			if(sm == NULL) exit(EXIT_FAILURE);
			sprintf(sm, "Hola");
		}
		mo++;
		printf("Now allocated %d Megabytes\n", mo);
	}
	exit(EXIT_SUCCESS);
}