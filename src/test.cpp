#include <iostream>
#include <stddef.h>//This gets NULL
#include "Color.hh"
#include "Node.hh"
#include "RBTree.hh"

using namespace std;

template<typename T>
/**
 * @breig Returns a representig string of the Node's color.
 * @param  node The node on which we want to know the color.
 * @return      A string indicating if the node is RED or BLACK.
 */
string whichColor(Node<T> * node) {
    return node->getColor() == RED? "RED": "BLACK";
}

template<typename T>
/**
 * @breif Prints all the properties a Node has.
 * @param node    The node of which we are printing its properties.
 * @param varName The name of the variable containing the node.
 */
void printProprerties(Node<T> * node,string varName) {
    if (node == NULL) return;//wont print a NULL Node, if that even makes sense.
    cout << "Printing the properties of " << varName << endl;
    cout << "\tI'm at: " << node << endl;
    cout << "\tKey: " << node->getKey() << endl;
    cout << "\tData: " << node->getData() << endl;
    cout << "\tMultiplicity: " << node->getMultiplicity() << endl;
    cout << "\tParent at: " << node->getParent() << endl;
    cout << "\tLeft child at: " << node->getLeft() << endl;
    cout << "\tRight child at: " << node->getRight() << endl;
    cout << "\tColor: " << whichColor(node) << endl;
}

/**
 * @breif Tests.
 */
int main(void) {
    RBTree<string> * rbt = new RBTree<string>(5, "hola");
    cout << "rbt created, 5 added" << endl;
    rbt->insert(6,"soy 6");
    cout << "6 added" << endl;
    rbt->insert(4,"soy 4");
    cout << "4 added" << endl;
    rbt->insert(3,"soy 3");
    cout << "3 added" << endl;
    rbt->insert(2,"soy 2");
    cout << "2 added" << endl;
    rbt->insert(1,"soy 1");
    cout << "1 added" << endl;

    printProprerties(rbt->getRoot(),"root");
    printProprerties(rbt->getRoot()->getLeft(),"roots left");
    printProprerties(rbt->getRoot()->getRight(),"roots right");
    printProprerties(rbt->getRoot()->getLeft()->getLeft(),"roots lefts left");
    printProprerties(rbt->getRoot()->getLeft()->getRight(),"roots lefts right");
    printProprerties(rbt->getRoot()->getLeft()->getLeft()->getLeft(),"roots lefts lefts left");

    cout << endl << "min value is: " << rbt->first()->getKey() <<
        " and it's data is: " << rbt->first()->getData() << endl;
    cout << endl << "next min value is: " << rbt->next(rbt->first())->getKey() <<
        " and it's data is: " << rbt->next(rbt->first())->getData() << endl;

    cout << endl << "max value is: " << rbt->last()->getKey() <<
    " and it's data is: " << rbt->last()->getData() << endl;
    cout << endl << "previous max value is: " <<
        rbt->previous(rbt->last())->getKey() << " and it's data is: "
        << rbt->previous(rbt->last())->getData() << endl << endl;


    RBTree<double> * rbt2 = new RBTree<double>(15, 5.0);
    cout << "rbt created, 15 added" << endl;
    rbt2->insert(15,5.0);
    cout << "15 added...again(check its multiplicity)" << endl;
    rbt2->insert(60,6.0);
    cout << "60 added" << endl;
    rbt2->insert(24,4.0);
    cout << "24 added" << endl;
    rbt2->insert(33,3.0);
    cout << "33 added" << endl;
    rbt2->insert(2,2.0);
    cout << "2 added" << endl;
    rbt2->insert(10,1.0);
    cout << "10 added" << endl;

    printProprerties(rbt2->getRoot(), "root");
    printProprerties(rbt2->getRoot()->getLeft(), "roots left");
    printProprerties(rbt2->getRoot()->getRight(), "roots right");
    printProprerties(rbt2->getRoot()->getLeft()->getLeft(), "roots lefts left");
    printProprerties(rbt2->getRoot()->getLeft()->getRight(), "roots lefts right");
    printProprerties(rbt2->getRoot()->getLeft()->getLeft()->getLeft(), "roots lefts lefts left");

    cout << endl << "min value is: " << rbt2->first()->getKey() <<
        " and it's data is: " << rbt2->first()->getData() << endl;
    cout << endl << "next min value is: " << rbt2->next(rbt2->first())->getKey()
        << " and it's data is: " << rbt2->next(rbt2->first())->getData() << endl;

    cout << endl << "max value is: " << rbt2->last()->getKey() <<
        " and it's data is: " << rbt2->last()->getData() << endl;
    cout << endl << "previous max value is: " <<
        rbt2->previous(rbt2->last())->getKey() << " and it's data is: " <<
        rbt2->previous(rbt2->last())->getData() << endl;


}
