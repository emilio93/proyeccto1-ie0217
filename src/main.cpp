#include <iostream>
#include <stddef.h>//This gets NULL
#include "Node.hh"
#include "Color.hh"

using namespace std;

template<typename T>
string whichColor(Node<T> * n) { return n->getColor() == RED? "RED": "BLACK"; }

/**
 * @breif Tests.
 */
int main(void) {
    cout << "hola" << endl;
    Node<int> * n = new Node<int>(5,5);
    cout << "Recoloreado a " << whichColor(n) << endl;
    n->recolor();
    cout << "Recoloreado a " << whichColor(n) << endl;
    n->recolor();
    cout << "Recoloreado a " << whichColor(n) << endl;
    n->recolor(RED);
    cout << "Recoloreado a " << whichColor(n) << endl;
    n->recolor(RED);
    cout << "Recoloreado a " << whichColor(n) << endl;
    n->recolor();
    cout << "Recoloreado a " << whichColor(n) << endl;
    return 0;
}
