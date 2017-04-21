#include <cstdlib>
#include <cstdio>
#include "Node.cpp"

class SortList{

    private:
        Node *start;
        Node *last;

    public:
        SortList();
        ~SortList();
        bool insert(int);
        void FinalOrder();
};
