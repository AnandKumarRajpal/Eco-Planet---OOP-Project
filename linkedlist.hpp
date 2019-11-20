#include <iostream>
#include "node.hpp"
using namespace std;

class Linkedlist
{
public:
    Node *head;
    Linkedlist();
    void Push(int v);
    int Pop(int v);
    ~Linkedlist();
};
