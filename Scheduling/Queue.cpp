#include <cstdio>
#include "Queue.hpp"

// Constructor
Queue::Node::Node(int id, int time, int priority): _id(id), _time(time), _priority(priority) {
    _next = NULL;
}; // El apuntador siguiente siempre apunta a NULL

// Pedimos la informacion del objeto
// Se utiliza const por que no podemos modificar el objeto
int Queue::Node::id() const {
    return _id;
} // Nos devuelve el dato almacena

int Queue::Node::time() const {
    return _time;
} // Nos devuelve el dato almacena

int Queue::Node::priority() const {
    return _priority;
} // Nos devuelve el dato almacena

Queue::Node *Queue::Node::next() const
{
    return _next;
} // Nos devuelve el siguiente nodo (si no existe retorna NULL)

// Metodo que permite modificar el apuntador
// Asigno y me retorna el nuevo nodo
Queue::Node *Queue::Node::next(Queue::Node *p)
{
    return _next = p;
}

/***********************************************
Clase Queue
***********************************************/

// Constructor
Queue::Queue():_s(0), start(NULL),eoq(NULL) {}
// Destructor
Queue::~Queue() {}

// Metodos para colas

// Metodo para insertar nodos al final de la cola
void Queue::enqueue(int id, int time, int priority)
{
    // Vas a agregar n datos por lo que es combeniente no usar la capacidad
    // precondicion
    if(empty()){
        // Creamos la cola
        start = eoq = new Node(id, time, priority);
    } else {
        // Agregamos un nuevo nodo a la cola
        eoq->next(new Node(id, time, priority));
        eoq = eoq->next();
    }

    // Incremento tamaño
    _s++;
}

// Devolvemos el valor almacenado y eliminamos el nodo
int* Queue::dequeue()
{
    // Precondicion
    if(!empty()){
        Node *aux = start;

        // Respaldamos los datos
        int *process = new int[3];
        process[0] = start->id();
        process[1] = start->time();
        process[2] = start->priority();
        
        // Apuntamos al siguiente nodo
        start = start->next();
        // Eliminamos el auxiliar
        delete aux;
        // Decrementamos el tamaño
        _s--;

        // Regresamos un arreglo con los datos del proceso (nodo)
        return process;
    }

    // Imprime un mensaje si la cola esta vacia
    printf("Cola vacia\n");
    return 0;
}

// Obtenemos un dato del primer nodo
int Queue::front()
{
    if(!empty()){
        // Retornamos el dato
        return start->id();
    }

    // Mostramos mensaje en caso de cola vacia
    printf("Cola vacia\n");
    return 0;
}

 void Queue::print_all()
 {
    Node *aux = start;
    while(aux != NULL)
    {
        printf("id: %i time: %i priority: %i\n", aux->id(), aux->time(), aux->priority());
        aux = aux->next();
    }
 }
