#include <iostream>
#include <stddef.h>//This gets NULL
#include "Color.hh"
#include "Node.hh"
#include "RBTree.hh"

using namespace std;

template<typename T>
string whichColor(Node<T> * n) {
    //return n == NULL ? "BLACK" : n->getColor() == RED? "RED": "BLACK";
    return n->getColor() == RED? "RED": "BLACK";
}

/**
 * @breif Tests.
 */
int main(void) {

    cout << "TEST DE COLORES \n ---------------" << endl;
        Node<int> * n = new Node<int>(5,5);
        cout << "Coloreado a " << whichColor(n) << endl;
        n->recolor();//BLACK
        cout << "Recoloreado a " << whichColor(n) << endl;
        n->recolor();//RED
        cout << "Recoloreado a " << whichColor(n) << endl;
        n->recolor(BLACK);
        cout << "Recoloreado a " << whichColor(n) << endl;
        n->recolor(RED);
        cout << "Recoloreado a " << whichColor(n) << endl;

        cout << "Asignando n2" << endl;
        Node<int> * n2 = n->getLeft();
        cout << "Asignado n2 a " << n2 << endl;
        cout << "n2 tiene color ";
        cout << whichColor(n2) << endl;
    cout << "TEST DE COLORES LISTO \n ---------------" << endl;

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

    /*
         a
      b        c
    d   e    f   g
     h          i j
     */
    /*
    a->recolor();
    d->recolor();
    e->recolor();
    f->recolor();
    g->recolor();

    a->addLeft(b);
    a->addRight(c);

    b->addLeft(d);
    b->addRight(e);

    c->addLeft(f);
    c->addRight(g);

    d->addRight(h);

    g->addLeft(i);
    g->addRight(j);

    a->recolor();
    b->recolor();
    cout << whichColor(a) << endl;
    cout << whichColor(b) << endl;


    RBTree<int> * rbt = new RBTree<int>(a);

    if (rbt->rule1()) { cout << "rule 1 ok" << endl; }
    else { cout << "rule 1 NOT ok" << endl; }

    if (rbt->rule2()) { cout << "rule 2 ok" << endl; }
    else { cout << "rule 2 NOT ok" << endl; }

    if (rbt->rule4()) { cout << "rule 4 ok" << endl; }
    else { cout << "rule 4 NOT ok" << endl; }

    if (rbt->rule5()) { cout << "rule 5 ok" << endl; }
    else { cout << "rule 5 NOT ok" << endl; }

    cout << "last is " << rbt->last()->getData() << endl;
    cout << "first is " << rbt->first()->getData() << endl;
    cout << "next first is ";
    cout << rbt->next(rbt->first())->getData() << endl;
*/

    RBTree<int> * tree = new RBTree<int>(13,5);\
    cout << "RBT created" << endl;
    tree->insert(b);

}
