#include <cstdlib>
#include <cstdio>

class Node
{
	private:
		int _dato; // Datos del nodo
		Node *_next; // Apuntador al siguiente nodo

	public:
		Node(int); // El apuntador siguiente siempre apunta a NULL
		~Node(); //Destructor
		Node *next(); // Nos devuelve el siguiente nodo (si no existe retorna NULL)
		void next(Node*);
		int dato(); // Nos devuelve el dato almacena
		void dato(int);
};
