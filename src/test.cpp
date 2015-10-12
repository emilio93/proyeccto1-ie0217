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
    Node<char> * a = new Node<char>(11, 'a');
    Node<char> * b = new Node<char>(12, 'a');
    Node<char> * c = new Node<char>(13, 'a');
    Node<char> * d = new Node<char>(14, 'a');
    Node<char> * e = new Node<char>(15, 'a');
    Node<char> * f = new Node<char>(16, 'a');
    Node<char> * g = new Node<char>(17, 'a');
    Node<char> * h = new Node<char>(18, 'a');
    Node<char> * i = new Node<char>(19, 'a');
    Node<char> * j = new Node<char>(20, 'a');
    RBTree<char> * rbt = new RBTree<char>(a);
    rbt->insert(b);
    
    rbt->insert(c);
    rbt->insert(d);
    rbt->insert(e);
    rbt->insert(f);
    rbt->insert(g);
    rbt->insert(h);
    rbt->insert(i);
    rbt->insert(j);
//    if(rbt->rules()) cout << "yeah";

}
