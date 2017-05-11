#include <cstdlib>
#include <cstdio>
#include "FIFO.hpp"

FIFO::FIFO()
{
	start = NULL;
	last = NULL;
}

//Destructor
FIFO::~FIFO()
{
	if(start != NULL) delete start;
	if(last != NULL) delete last;
}

bool FIFO::insert(int dato, int prioridad)
{
	Node *new_node = new Node(dato, prioridad);

    //Si la lista esta vacía
	if(start == NULL && last == NULL)
	{
		start = new_node;
		last = new_node;
	}

    else
    {
        last->next(new_node);
        last = new_node;
    }
	return true;
}


void FIFO::FinalOrderF()
{
    int tiempo=0;
    int promedio;
    int cont = 0;

	Node *current = start;

	while(current != NULL)
	{
        Node *aux = current;

        while(aux != NULL)
        {
            //**** IMPRESION LISTADO*****
            if (aux->dato() < 10)
            {
                printf("%i           %i        \n", aux->dato(), aux->prioridad());
            }

            else
            {
                printf("%i          %i        \n", aux->dato(), aux->prioridad());
            }
            //***************************
            aux = aux->next();
        }
        tiempo += current->dato();
        printf("Tiempo Retorno: %i\n", tiempo);
        current = current->next();
        puts("");
    }


    Node *aux = start;
    tiempo = 0;
    puts ("Orden de procesos:");

    while(aux != NULL)
        {
            tiempo += aux->dato();
            if (aux != last)
            {
            printf("%i -> ", aux->dato());
            }
            else
            {
            printf("%i", aux->dato());
            }
            aux = aux->next();
            ++cont;
        }

	printf("\nTiempo de retorno final: %i\n", tiempo);
	promedio = tiempo/cont;
	printf("Tiempo promedio: %i\n", promedio);

}
