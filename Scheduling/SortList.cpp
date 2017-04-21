#include <cstdlib>
#include <cstdio>
#include "SortList.hpp"

//Valores iniciales de la lista
SortList::SortList()
{
	start = NULL;
	last = NULL;
}

//Destructor
SortList::~SortList()
{
	if(start != NULL) delete start;
	if(last != NULL) delete last;
}

bool SortList::insert(int dato)
{
	Node *new_node = new Node(dato);

    //Si la lista esta vacía
	if(start == NULL && last == NULL)
	{
		start = new_node;
		last = new_node;
	}

	else
	{
        //Si dato es menor a inicio->valor() entonces Nodo_nuevo->siguiente(inicio)
		if(dato < start->dato())
		{
			new_node->next(start);
			//indicarle a inicial que el valor inicial ya no es el numero anterior inicial, sino el nuevo
			start = new_node;
		}
        //Si dato es mayor que "ultimo" y se tiene que insertar al final de la lista entonces "último" -> siguiente (nuevo nodo)
		if(dato > last->dato())
		{
			last->next(new_node);
			//indicarle a "último" que ahora es el nuevo nodo
			last = new_node;
		}

		else
		{
            //Inserción por la mitad se creará el nodo aux que será igual al valor inicial
			Node *aux = start;
			// Mientras que aux no agarre como valor siguiente a NULL, aux agarrará el valor del siguiente nodo
			while(aux->next() != NULL)
			{
                //Esta condición es absolutamente necesaria, ya metetelo en la cabeza... zope!!! >_<
                if(dato == aux->dato()) {return false;}

				//Si un dato es mas chico O IGUAL osea IGUAAAAL!!! SI ES AMBAS!!! que aux el cuál tomó el valor del siguiente nodo del recorrido...
				if(dato <= aux->next()->dato())
				{
                    //...Se crea un nuevo nodo delante del nodo con un el dato mayor y a este se le asigna el del mismo para insertar el valor comparado
                    // en el sitio despejado
					new_node->next(aux->next());
					aux->next(new_node);
					return true;
				}

				aux = aux->next();
			}
		}
	}

	return true;
}


void SortList::FinalOrder()
{
	Node *aux = start;
	while(aux != NULL)
	{
		printf("%i           ?\n", aux->dato());
		aux = aux->next();
	}
}
