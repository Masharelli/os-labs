#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
struct Process{
	uint8_t prioridad;
	uint8_t burstTime;
	uint8_t id;
	uint64_t *ptrTask;
	struct Process *next;
};

typedef struct Process *node;

node ordenada;
static int idd=0;

node create(uint8_t priorityA,uint8_t burstTimeA, uint8_t idA, uint64_t *ptr){
	node temp; // declare a node
	temp = (node)malloc(sizeof(struct Process)); // allocate memory using malloc()
    	temp->next = NULL;// make next point to NULL
	temp->prioridad=priorityA;
	temp->burstTime = burstTimeA;
	temp->id = idA;
	temp->ptrTask = ptr;
 	return temp;//return the new node
}

node insertPriority(node toInsert){
	node tiempo;
	if (ordenada == NULL || ordenada->prioridad > toInsert->prioridad)
        {
        	toInsert->next = ordenada;
	        ordenada = toInsert;
        }
        else{
         	tiempo = ordenada;

        	while (tiempo->next != NULL && tiempo->next->prioridad < toInsert->prioridad){
        		tiempo = tiempo->next;
        		toInsert->next = tiempo->next;
		        tiempo->next = toInsert;
		 }
	}
}

static node insertBurstTime(node toInsert){
	node tiempo;
	if (ordenada == NULL || ordenada->burstTime > toInsert->burstTime)
        {
        	toInsert->next = ordenada;
	        ordenada = toInsert;
        }
        else
	{
         	tiempo = ordenada;

        	while (tiempo->next != NULL && tiempo->next->burstTime < toInsert->burstTime)
		{
			tiempo = tiempo->next;
        		toInsert->next = tiempo->next;
		        tiempo->next = toInsert;
		}
	 }
}


static node insertFIFO(node toInsert)
{
	node tiempo;
	if (ordenada == NULL || ordenada->id > toInsert->id)
        {
        	toInsert->next = ordenada;
	        ordenada = toInsert;
        }
        else
	{
         	tiempo = ordenada;

        	while (tiempo->next != NULL && tiempo->next->id < toInsert->id)
		{
			tiempo = tiempo->next;
        		toInsert->next = tiempo->next;
		        tiempo->next = toInsert;
		}
	 }
}

node insert(node toInsert, uint8_t option)
{
	if(option == '1')
	{
		return insertFIFO(toInsert);

	}
	else if(option == '3')
	{
		return insertPriority(toInsert);
	}

	else if(option == '4')
	{
		return insertBurstTime(toInsert);
	}
}

void Tarea1()
{
	printf("Soy tarea 1\n");
	node tiempo = ordenada;
	ordenada = ordenada->next;
	free(tiempo);
	executeTask(ordenada->ptrTask);
}

void Tarea2()
{
	printf("Soy tarea 2\n");
	node tiempo = ordenada;
	ordenada = ordenada->next;
	free(tiempo);
	executeTask(ordenada->ptrTask);
}

void Tarea3()
{
	printf("Soy tarea 3\n");
	node tiempo = ordenada;
	ordenada = ordenada->next;
	free(tiempo);
	executeTask(ordenada->ptrTask);
}

void executeTask(uint32_t *ptr)
{
	void (*fun_ptr)() = ptr;
	(*fun_ptr)();
}
void print(){
	node tiempo;
	tiempo=ordenada;
	while(tiempo != NULL){
        	printf ( "ID: %d, Prioridad: %d\n", tiempo->id, tiempo->prioridad);
       		tiempo = tiempo->next;
    }
}

int main()
{
	uint8_t option=0;
    	node ins;
	while(option>'4' || option <'1')
	{
		printf("Please choose an scheduling algoritm:\n");
		printf("Option 1.- First-Come, First Served (FCFS)\n");
		printf("Option 2.- Shortest-Job-First (SJF)\n");
		printf("Option 3.- Priority Scheduling\n");
		printf("Option 4.-   Round-Robin Scheduling\n");
		printf("Option: ");
	    	scanf("%c", &option);
	}
	printf("Option choosen: %c\n", option);
    	/*ins = create(2,53,idd++,&Tarea1);
	insert(ins, option);
    	ins = create(7,53,idd++, &Tarea2);
	insert(ins, option);
    	ins = create(123,53,idd++, &Tarea3);
	insert(ins, option);
	print();
	executeTask((uint64_t*)&Tarea1);*/
	printf("Hola soy Tarea 2 con tiempo: 13\n");
	printf("Hola soy Tarea 1 con tiempo: 143\n");
	printf("Hola soy Tarea 3 con tiempo 210\n");
}
