#include <cstdlib>
#include <cstdio>

#include "Prioridad.hpp"

using namespace std;

Prioridad::Prioridad()
{
	start = NULL;
	last = NULL;
	_size = 0;
	_time = 0;
	quantum = 0;
}

Prioridad::~Prioridad()
{
	if(start != NULL) delete start;
	if(last != NULL) delete last;
}

void Prioridad::Insertar(int tiempo, int prioridad)
{
	Node *new_node = new Node(tiempo, prioridad);

	//Si la lista esta vacía
	if(start == NULL && last == NULL)
	{
		start = new_node;
		last = new_node;
	}

	else
	{
		
		if(prioridad >= start->prioridad())
		{
			new_node->next(start);
			start = new_node;
		}
		
		else if(prioridad <= last->prioridad())
		{
			last->next(new_node);
			last = new_node;
		}

		else
		{
			Node *aux = start;
			while(aux->next() != NULL)
			{
				if(prioridad >= aux->next()->prioridad())
				{
					new_node->next(aux->next());
					aux->next(new_node);
					break;
				}

				aux = aux->next();
			}
		}
	}

	_time += tiempo;
	_size++;
	quantum = _time/_size;
}

void Prioridad::Pop(Node *actual)
{
	actual->dato(actual->dato() - quantum);

	// Muerte proceso
	if (actual->dato() <= 0) 
	{
		if(actual == start)
		{
			start = start->next();
			actual->next(NULL);
			delete actual;
		}

		else
		{
			Node *aux = start;
			while(aux->next() != actual)
				aux = aux->next();

			aux->next(aux->next()->next());
			actual->next(NULL);
			delete actual;
		}
	}
}

void Prioridad::print_all()
{
	printf("\nQuantum: %i\n", quantum);
		Node *aux = start;
		while(aux != NULL)
		{
			Pop(aux);
			printf("Tiempo: %i Prioridad: %i\n", aux->dato(), aux->prioridad());
			aux = aux->next();
		}
		printf("\n");
}

/*
int main(int argc, char const *argv[])
{
	Prioridad *p = new Prioridad();
	for (int i = 0; i < 6; ++i)
	{
		printf("Id %i Tiempo %i Prioridad %i\n", i, i, i);
		p->Insertar(i, i);
	}
	p->print_all();
	p->print_all();
	return 0;
}
*/