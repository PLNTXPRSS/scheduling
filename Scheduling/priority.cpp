/*
 * priority.cpp
 */

#include <iostream>
#include <cstdlib>

using namespace std;

struct node
{
    char data;
    int priority;        
    struct node *next;
};

struct queue
{
    node *first;
    node *last;
};

struct node *createNode(char x, int pr)
{
    struct node *newNode = new(struct node);
    newNode->data = x;
    newNode->priority = pr;
    return newNode;
};

void enqueue(struct queue &q, char value, int priority)
{
     struct node *aux = createNode(value, priority);
     aux->next = NULL;
     
     if(q.first == NULL) {
         q.first = aux;   
     } else {
         (q.last)->next = aux;
     }
     q.last = aux;         
}

void DisplayQueue( struct queue q )
{
     struct node *aux;
     
     aux = q.first;
     
     cout << " Caracter  prioritydad " << endl;
     cout << " ------------------- " << endl;
          
     while(aux != NULL) {
            cout<<"    "<< aux->data << "     |   " << aux->priority << endl;
            aux = aux->next;
     }    
}

void SortByPriority( struct queue &q )
{
     struct node *aux1, *aux2;
     int p_aux;
     char c_aux;
     
     aux1 = q.first;
     
     while(aux1->next != NULL) {
            aux2 = aux1->next;
            
            while( aux2 != NULL) {
                   if(aux1->priority > aux2->priority) {
                       p_aux = aux1->priority;
                       c_aux = aux1->data;
                       
                       aux1->priority = aux2->priority;
                       aux1->data   = aux2->data;
                       
                       aux2->priority = p_aux;
                       aux2->data   = c_aux;
                   }
                   
                   aux2 = aux2->next;
            }
            
            aux1 = aux1->next;
     }
}

void Insert( struct queue &q, char c, int pr )
{
     enqueue( q, c, pr );
    
     SortByPriority( q ); 
}

void menu()
{
    cout << "\n\t queueS CON priorityDAD EN C++ \n\n";
    cout << " 1. ENQUEUE"<< endl;
    cout << " 2. DISPLAY"<< endl;
    cout << " 3. FUCK OFF"<< endl;

    cout<< "\n OPTION: ";
}

int main()
{
    struct queue q;
    
    q.first = NULL;
    q.last   = NULL;

    char c ;     
    int pr;      
    int option;      
    int x ;      

    do
    {
        menu();  cin >> option;

        switch(option)
        {
            case 1:
                 cout << "\n CHARACTER: ";
                 cin >> c;
                 
                 cout << "\n PRIORITY: ";   
                 cin >> pr;
                 
                 Insert(q, c, pr);
                 
                 cout << "\n\n\t\tCHARACTER '" << c << "' ENQUEUEING...\n\n";
            break; 
                  
            case 2:
                 cout << "\n\n DISPLAYING QUEUE WITH PRIORITY\n\n";
                 
                 if(q.first != NULL) {
                     DisplayQueue(q);
                 } else {   
                    cout << "\n\n\tQUEUE EMPTY...!" << endl;
                 } 
            break;
            
            case 3:
                return 0;

            default:
                cout << "\n\tNULL..!" << endl;
                return 0;
         }

        cout << endl << endl;

    } while (option != 3);
    
    return 0;
}
