#include <cstdlib>
#include <cstdio>
#include "RoundRobin.hpp"

int _quantum;
int newround;
int prioridad2;

RoundRobin::RoundRobin()
{
	start = NULL;
	last = NULL;
}

//Destructor
RoundRobin::~RoundRobin()
{
	if(start != NULL) delete start;
	if(last != NULL) delete last;
}

bool RoundRobin::insertquantum(int quantum)
{
    _quantum = quantum;
    return true;
}

bool RoundRobin::insert(int dato, int prioridad)
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

    bool RoundRobin::insert2(int newround, int prioridad2)
    {
        Node *new_node = new Node(newround, prioridad2);
        last->next(new_node);
        last = new_node;
        return true;
    }

void RoundRobin::FinalOrderR()
{
    int tiempo=0;
    int promedio;
    int cont = 0;

	Node *current = start;

	while(current != NULL)
	{
        Node *aux = current;
        tiempo += current->dato();
        current = current->next();
    }

    Node *aux = start;
    tiempo = 0;
    puts ("Orden de procesos:");

    while(aux != NULL)
        {
            tiempo += aux->dato();
            if (aux->dato() < _quantum)
                {
                if (aux != last) {printf("%i -> ", aux->dato());}
                else {printf("%i", aux->dato());}
                aux = aux->next();
                ++cont;
                }
            else //*****************************
            {
                printf("%i ->", _quantum);
                prioridad2 = aux->prioridad();
                aux = aux->next();
                ++cont;
                newround = aux->dato() - _quantum;
                insert2(newround,prioridad2);
            }
        }

	printf("\nTiempo de retorno final: %i\n", tiempo);
	promedio = tiempo/cont;
	printf("Quantum: %i\n", _quantum);
	printf("Tiempo promedio: %i\n", promedio);

}
