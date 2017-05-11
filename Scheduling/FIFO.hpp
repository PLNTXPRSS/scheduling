#include <cstdlib>
#include <cstdio>
#include "Node.cpp"

class FIFO{

    private:
        Node *start;
        Node *last;

    public:
        FIFO();
        ~FIFO();
        bool insert(int, int);
        void FinalOrderF();
};
