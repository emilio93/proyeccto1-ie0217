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
    printProprerties(rbt->getRoot()->getLeft()->getRight(),"roots lefts right");
    printProprerties(rbt->getRoot()->getLeft()->getLeft()->getLeft(),"roots lefts lefts left");
    /*
    Node<string> * root = rbt->getRoot();
    Node<string> * rootLeft = new Node<string>(3, "soy 3");
    Node<string> * rootRight = new Node<string>(6, "soy 6");
    Node<string> * leftLeft = new Node<string>(2, "soy 2");
    Node<string> * leftRight = new Node<string>(4, "soy 4");
    rootLeft->setColor(BLACK);
    rootRight->setColor(BLACK);

    root->setLeft(rootLeft);
    root->setRight(rootRight);

    rootLeft->setLeft(leftLeft);
    rootLeft->setRight(leftRight);
    */
    /* tree structure now
                     |---------root-------|
            |----rootLeft----|         rootRight
        leftLeft         leftRight
     */

    //ROTATION TEST
    /*
    printProprerties(root, "root");
    printProprerties(rootLeft, "rootLeft");
    printProprerties(rootRight, "rootRight");
    printProprerties(leftLeft, "leftLeft");
    printProprerties(leftRight, "leftRight");

    if (rbt->rules()) {
        cout << "Tree follows the rules." << endl;
    } else {
        cout << "Tree DOESN'T follow the rules." << endl;
    }

    rbt->rotateRight(root);
    */
    /* tree structure now
                     |---------rootLeft-------|
                 leftLeft                 |----rootLeft----|
                                      leftRight        rootRight
     */
    /*
    cout<<endl<<"Rotated right"<<endl;
    printProprerties(root, "root");
    printProprerties(rootLeft, "rootLeft");
    printProprerties(rootRight, "rootRight");
    printProprerties(leftLeft, "leftLeft");
    printProprerties(leftRight, "leftRight");

    if (rbt->rules()) {
        cout << "Tree follows the rules." << endl;
    } else {
        cout << "Tree DOESN'T follow the rules." << endl;
    }
*/


}
