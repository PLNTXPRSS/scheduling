#ifndef __Prioridad
#define __Prioridad

#include <cstdlib>
#include <cstdio>

#include "Node.cpp"

class Prioridad {

	private:
		int quantum;
		Node *start;
		Node *last;
		int _size;
		int _time;

	public:
		Prioridad();
		~Prioridad();

		void Insertar(int, int);
		void Pop(Node*);
		void print_all();
};

#endif /* __Prioridad */