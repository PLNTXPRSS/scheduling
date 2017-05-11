#include <cstdlib>
#include <cstdio>
#include "Node.cpp"

class RoundRobin{

    private:
        Node *start;
        Node *last;

    public:
        RoundRobin();
        ~RoundRobin();
        bool insertquantum(int);
        bool insert(int, int);
        bool insert2(int, int);
        void FinalOrderR();
};
