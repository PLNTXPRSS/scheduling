#include <cstdlib>
#include <cstdio>
#include "Node.hpp"

Node::Node(int _dato)
{
	Node::_dato = _dato;
	Node::_next = NULL;
}

Node::~Node()
{
	Node::_dato = 0;
	if(Node::_next != NULL) delete Node::_next;
}

Node *Node::next() {return Node::_next;}

void Node::next(Node* _next) {Node::_next= _next;}

int Node::dato() {return Node::_dato;}

void Node::dato(int _dato) {Node::_dato = _dato;}
