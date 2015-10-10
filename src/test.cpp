#include <iostream>
#include <stddef.h>//This gets NULL
#include "Color.hh"
#include "Node.hh"
#include "RBTree.hh"

using namespace std;

template<typename T>
string whichColor(Node<T> * n) {return n->getColor() == RED? "RED": "BLACK";}

/**
 * @breif Tests.
 */
int main(void) {
    Node<int> * a = new Node<int>(13,5);
    Node<int> * b = new Node<int>(18,5);
    Node<int> * c = new Node<int>(17,5);
    Node<int> * d = new Node<int>(1,89);
    Node<int> * e = new Node<int>(11,5);
    Node<int> * f = new Node<int>(15,5);
    Node<int> * g = new Node<int>(25,5);
    Node<int> * h = new Node<int>(6,56);
    Node<int> * i = new Node<int>(22,5);
    Node<int> * j = new Node<int>(27,255);

    RBTree<int> * rbt = new RBTree<int>(a);
    rbt->insert(b);
    rbt->insert(c);
    rbt->insert(d);
    rbt->insert(e);
    rbt->insert(f);
    rbt->insert(g);
    rbt->insert(h);
    rbt->insert(i);
    rbt->insert(j);
    if(rbt->rules()) cout << "yeah";

}
