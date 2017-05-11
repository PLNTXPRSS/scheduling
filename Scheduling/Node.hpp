#ifndef _node
#define _node
#include <cstdlib>
#include <cstdio>
class Node
{
	private:
		int _dato; // Datos del nodo
		int _prioridad; // prioridad del nodo
		Node *_next; // Apuntador al siguiente nodo

	public:
		Node(int, int); // El apuntador siguiente siempre apunta a NULL
		~Node(); //Destructor
		Node *next(); // Nos devuelve el siguiente nodo (si no existe retorna NULL)
		void next(Node*);
		int dato(); // Nos devuelve el dato almacena
		void dato(int);
		int prioridad(); // Nos devuelve la prioridad
		void prioridad(int);
};
#endif
