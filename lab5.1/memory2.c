#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define mega (1024 * 1024)
#define meg 1024

int main(){
	char *sm;
	size_t sta = meg;
	int mo;

	while(mo < (mega * 2)){
		sm = (char *)malloc(sta);
		if(sm != NULL){
			mo++;
			sprintf(sm, "Hola");
			printf("%s - now allocated %d Megabytes\n", sm, mo);
		} else {
			exit(EXIT_FAILURE);
		}
	}
	exit(EXIT_SUCCESS);
}
