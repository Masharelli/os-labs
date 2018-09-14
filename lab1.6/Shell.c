#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

#define MAX_LINE		80 /* 80 chars per line, per command */

int conwait,count=0,repetir=0,last;
char historial[10][MAX_LINE];
void setup(char Buffer[])
{
    int length,i;
    length = read(STDIN_FILENO, Buffer, MAX_LINE);
	
	if(Buffer[length-2]=='&'){
		conwait = 1;
	}
	if((Buffer[length-2]=='!')&&(Buffer[length-3]=='!')){
		repetir=1;
		last=0;
	}
	else if((Buffer[length-3]=='!')&&((Buffer[length-2]-48)>=0&&(Buffer[length-2]-48)<=9)){
		repetir=1;
		last=(count-(Buffer[length-2]-48));
		int z=0;
	}else{
		for (i=9;i>0;i--)strcpy(historial[i],historial[i-1]);
		strcpy(historial[0],Buffer);
		count++;
		repetir=0;
	}
	Buffer[length-1] = '\0';
} 
void printHistorial(){
	int i,j=0,hcount=count;
	for(i=0;i<hcount;i++){
		printf("%d.-",hcount-i);
		while(historial[i][j]!='\n'&&historial[i][j]!='\0'){
			printf("%c",historial[i][j]);
			j++;
		}
		printf("\n");
		j=0;
	}
}

int main(void)
{
	pid_t pid;
	char *args[MAX_LINE/2 + 1];	/* command line (of 80) has max of 40 arguments */
	char Buffer[MAX_LINE];
	args[0]="/bin/bash";
	args[1]="-c";
	args[3]=NULL;
    while (1){   
        printf("osh>");
	fflush(stdout);  
	conwait = 0;
	setup(Buffer);
	if(repetir!=0){
		int z=0;
		while(historial[last][z]!='\n'&&historial[last][z]!='\0'){
			Buffer[z]=historial[last][z];
			z++;
		}
		Buffer[z] = '\0';
		repetir=0;
	}
	args[2]=Buffer;
	
	pid = fork();
	if (pid < 0) { /* error occurred */
		fprintf(stderr, "Fork Failed\n");
		return 1;
	}
	else if (pid == 0) { /* child process */
		if(strcmp(Buffer,"history")==0||strcmp(Buffer,"history&")==0)printHistorial();
		execvp(*args,args);		 
	}
	else{ /* parent process */
		/* parent will wait for the child to complete */
		if(conwait==0){
			wait(NULL);
			printf("parent wait\n");
		}
	}
    }
	return 0;
}
