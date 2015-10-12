#include <iostream>
#include <stddef.h>//This gets NULL
#include "Color.hh"
#include "Node.hh"

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
 * @breif Node tests.
 */
int main(void) {
    Node<string> * node1 = new Node<string>(1,"foo");
    cout << "node1 created." << endl;
    printProprerties(node1, "node1");
    cout << endl;

    Node<string> * node2 = new Node<string>(2,"bar");
    cout << "node2 created." << endl;
    printProprerties(node2, "node2");
    cout << endl;

    node2->setLeft(node1);
    cout << "node2 left child set to be node1." << endl;
    cout << endl;

    node2->setColor(BLACK);
    cout << "node2 color set to be BLACK." << endl;
    cout << endl;

    printProprerties(node1, "node1");
    cout << endl;

    printProprerties(node2, "node2");
    cout << endl;

    node2->add();
    cout << "node2 multiplicity increased via node2->add()." << endl;
    cout << endl;

    printProprerties(node2, "node2");
    cout << endl;

    node2->remove();
    cout << "node2 multiplicity decreased via node2->remove()." << endl;
    cout << endl;

    printProprerties(node2, "node2");
    cout << endl;

    printProprerties(node2->getLeft(), "node1 via node2->getLeft()");
    cout << endl;

    printProprerties(node1->getParent(), "node2 via node1->getParent()");
    cout << endl;

    //Should print 7 more lines(8 with the ast endl).
    if (node1->isLeft()) {
        cout << "Hi! I'm node1 and I just passed a test on being Left" << endl;
    }

    if (node2->isParent()) {
        cout << "Hi! I'm node2 and I just passed a test on being a Parent" << endl;
    }

    if (!node1->isParent()) {
        cout << "Hi! I'm node1 and I didn't pass a test on being a Parent" << endl;
    }

    if (node1->hasParent()) {
        cout << "Hi! I'm node1 and I just passed a test on having a Parent" << endl;
    }

    if (!node2->hasParent()) {
        cout << "Hi! I'm node2 and I didn't pass a test on having a Parent" << endl;
    }

    if (node2->hasLeft()) {
        cout << "Hi! I'm node2 and I just passed a test on having a Left child" << endl;
    }

    if (!node1->hasLeft()) {
        cout << "Hi! I'm node1 and I didn't pass a test on having a Left child" << endl;
    }

    //Pretty much Node class works OK
}
