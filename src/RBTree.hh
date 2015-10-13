#ifndef RBTREE_CLASS
#define RBTREE_CLASS

#include <stddef.h>//This gets NULL
#include "Node.hh"


using namespace std;

template<typename T>
/**
 * @breif The RBTree(Red-Black Tree) defines a collection of ordered
 *        elements of a multiset, each element is a node, with a given
 *        multiplicity and data.
 *
 * Some rules must be verified.
 * 	1 - A node is either red or black.
 *  2 - The root is black. This rule is sometimes omitted. Since the root can
 *  	always be changed from red to black, but not necessarily vice versa,
 *  	this rule has little effect on analysis.
 * 	3 - All leaves (NIL) are black.
 *  4 - If a node is red, then both its children are black.
 *  5 - Every path from a given node to any of its descendant NIL nodes contains
 *  	the same number of black nodes. The uniform number of black nodes in the
 *   	paths from root to leaves is called the black-height of the red–black
 *   	tree.
 */
class RBTree{
    private:
        /**
         * @breif The root of the tree, this is, the first element,
         *        this is the only one that needs to be known, since
         *        all the other ones are derived from this.
         */
        Node<T> * root;

    public:
        /**
         * @breif Creates a red-black tree with the root Node of the given key
         *        and data.
         * @param key The root nodes key.
         * @param data The root nodes data.
         */
        RBTree(int key, T data);

        /**
         * @breif Creates a red-black tree with the root Node being the given.
         * @param node The root nodes.
         */
        RBTree(Node<T> * node);

        /**
         * @breif Creates a red-black tree with empty root Node.
         */
        RBTree(void);

        /**
         * @breif Destructs the Tree.
         */
        ~RBTree(void);

        /**
         * @breif Gets the root node.
         * @return The tree's root node.
         */
        Node<T> * getRoot(void);

        /**
         * @breif Sets the root node.
         * @param rootNode The tree's root node.
         */
        void setRoot(Node<T> * rootNode);

        /**
         * Replaces a node.
         * @param oldNode The node to remove.
         * @param newNode The node to place.
         */
        void replaceNode(Node<T> *oldNode, Node<T> * newNode);

        /**
         * @breif Makes a left rotation on a given node.
         * @param node The pivot.
         */
        void rotateLeft(Node<T> * rootPivot);

        /**
         * @breif Makes a right rotation on a given node.
         * @param rbt The tree to rotate.
         * @param node The pivot.
         */
        void rotateRight(Node<T> * rootPivot);

        /**
         * Checks 1st rbtree rule on a node.
         * @param  node Node to check.
         */
        bool rule1(Node<T> * node);

        /**
         * Checks 1st rbtree rule on the tree.
         */
        bool rule1(void);

        /**
         * Checks 2nd rbtree rule.
         */
        bool rule2(void);

        /**
         * Checks 4th rbtree rule on a node.
         * @param  node Node to check.
         */
        bool rule4(Node<T> * node);

        /**
         * Checks 4th rbtree rule on the tree.
         */
        bool rule4(void);

        /**
         * Checks 5th rbtree rule on a node.
         * @param  node Node to check.
         */
        bool rule5(Node<T> * rootNode);

        /**
         * Checks 5th rbtree rule on a node.
         * @param  rootNode Node to check.
         * @param  blackCount how many black nodes.
         * @param  pathCount The black nodes height.
         */
        bool rule5(Node<T> * rootNode, int blackCount, int * pathCount);

        /**
         * Checks 5th rbtree rule on the tree.
         */
        bool rule5(void);

        /**
         * @breif Checks all the rules.
         * @return  True if the tree is correct.
         */
        bool rules(void);

        /**
         * @breif Determines wether an element exists in the tree, if
         *        it does, the function returns the multiplicity of the
         *        element, else it will return 0.
         * @param  data The data to search for.
         * @return      The multiplicity of the element, 0 meaning the
         *              element was not found.
         */
        int exists(int key);

        /**
         * @breif Extracts an element from the tree if it's found.
         * @param  data The data to extract.
         * @return      The extracted data.
         */
        T extract(int key);

        /**
         * @breif Returns the next element in the tree.
         * @param node  The reference node.
         * @return      The node following the reference node.
         */
        Node<T> * next(Node<T> * node);
        /**
         * @breif Returns the previous element in the tree.
         * @param node  The reference node.
         * @return      The node preceding the reference node.
         */
        Node<T> * previous(Node<T> * node);

        /**
         * @breif The first element of the subtree whose root is the given node.
         * @param node The root of the subtree.
         * @return The first node of the subtree.
         */
        Node<T> * first(Node<T> * node);

        /**
         * @breif The first element of the tree.
         * @return The first node of the tree.
         */
        Node<T> * first();

        /**
         * @breif The last element of the subtree whose root is the given node.
         * @param node The root of the subtree.
         * @return The last node of the subtree.
         */
        Node<T> * last(Node<T> * node);

        /**
         * @breif The last element of the tree.
         * @return The last node of the tree.
         */
        Node<T> * last();

        /**
         * @breif Returns the other parents child.
         * @param node The reference node.
         * @return The reference nodes sibling.
         */
        Node<T> * sibling(Node<T> * node);

        /**
         * @breif Returns nodes parent.
         * @param node The reference node.
         * @return The reference nodes parent.
         */
        Node<T> * parent(Node<T> * node);

        /**
         * @breif Returns nodes grandparent.
         * @param node The reference node.
         * @return The reference nodes grandparent.
         */
        Node<T> * grandpa(Node<T> * node);

        /**
         * @breif Returns nodes uncle, ie, the parents sibling.
         * @param node The reference node.
         * @return The reference nodes uncle.
         */
        Node<T> * uncle(Node<T> * node);


        /**
         * @breif Inserts an element into the tree, indicates if
         *        data was inserted correctly by returning true.
         *        If element is already in the tree, the multiplicity
         *        of the element will be increased.
         * @param  data The data to insert.
         */
        bool insert(Node<T> * node);
        bool insert(int key, T data);
        void insertCase1(Node<T> * node);
        void insertCase2(Node<T> * node);
        void insertCase3(Node<T> * node);
        void insertCase4(Node<T> * node);
        void insertCase5(Node<T> * node);



        /**
         * @breif Removes an element from the tree, this will remove the element
         * @param  data Data to search and remove.
         * @return      True if element was removed.
         */
        bool remove(int key);
};

/******************************************************************************
 *                                                                           **
 * CLASS IMPLEMENTATION                                                      **
 *                                                                           **
 ******************************************************************************/

template<typename T>
RBTree<T>::RBTree(int key, T data) {
    Node<T> * node = new Node<T>(key, data);
    node->setColor(BLACK);//root element is BLACK
    this->setRoot(node);
}

template<typename T>
RBTree<T>::RBTree(Node<T> * node) {
    node->setColor(BLACK);//root element is BLACK
    this->setRoot(node);
}

template<typename T>
RBTree<T>::RBTree(void) {
    ;
}

template<typename T>
RBTree<T>::~RBTree(void) {
    ;
}

template<typename T>
Node<T> * RBTree<T>::getRoot(void) {
    return this->root;
}

template<typename T>
void RBTree<T>::setRoot(Node<T> * node) {
    this->root = node;
}

template<typename T>
void RBTree<T>::replaceNode(Node<T> * oldNode, Node<T> * newNode) {
    if (!oldNode->hasParent()) {
        this->setRoot(newNode);
        newNode->setParent(NULL);
    } else {
        if (oldNode->isLeft()) {
            oldNode->getParent()->setLeft(newNode);
        } else if (oldNode->isRight()) {
            oldNode->getParent()->setRight(newNode);
        }
    }

    if (newNode != NULL) {
        newNode->setParent(oldNode->getParent());
    }
}

/******************************************************************************
 *                                                                           **
 * ROTATIONS                                                                 **
 *                                                                           **
 ******************************************************************************/

template<typename T>
void RBTree<T>::rotateLeft(Node<T> * rootPivot) {
    Node<T> * right = rootPivot->getRight();
    this->replaceNode(rootPivot, right);
    rootPivot->setRight(right->getLeft());
    if (right->hasLeft()) {
        right->getLeft()->setParent(rootPivot);
    }
    right->setLeft(rootPivot);
    rootPivot->setParent(right);
}

template<typename T>
void RBTree<T>::rotateRight(Node<T> * rootPivot) {
    Node<T> * left = rootPivot->getLeft();
    this->replaceNode(rootPivot, left);
    rootPivot->setLeft(left->getRight());
    if (left->hasRight()) {
        left->getRight()->setParent(rootPivot);
    }
    left->setRight(rootPivot);
    rootPivot->setParent(left);
}

/******************************************************************************
 *                                                                           **
 * TREE RULES                                                                **
 * 	1 - A node is either red or black.                                       **
 *  2 - The root is black. This rule is sometimes omitted. Since the root    **
 *  	can always be changed from red to black, but not necessarily vice    **
 *  	versa, this rule has little effect on analysis.                      **
 * 	3 - All leaves (NIL) are black.                                          **
 *  4 - If a node is red, then both its children are black.                  **
 *  5 - Every path from a given node to any of its descendant NIL nodes      **
 *  	contains the same number of black nodes. The uniform number of       **
 *  	black nodes in the paths from root to leaves is called the           **
 *  	black-height of the red–black tree.                                  **
 *                                                                           **
 ******************************************************************************/

template<typename T>
bool RBTree<T>::rule1(Node<T> * node) {
    bool a, b, c;
    a = node->getColor() == RED || node->getColor() == BLACK;
    b = true;
    c = true;
    //cout<<node<<endl;
    //cout<<node->getLeft()<<endl;
    if (node->hasRight()) { c = this->rule1(node->getRight()); }
    if (node->hasLeft()) { b = this->rule1(node->getLeft()); }
    return a && b && c;
}

template<typename T>
bool RBTree<T>::rule1() {
    return this->rule1(this->getRoot());
}

template<typename T>
bool RBTree<T>::rule2() {
    return this->getRoot()->getColor() == BLACK;
}

template<typename T>
bool RBTree<T>::rule4(Node<T> * node) {
    if (node == NULL) {
        return true;//pretty basic
    }
    bool a, b, c;
    a = true;
    if (node->getColor() == RED) {
        a = a && node->getLeft()->getColor() == BLACK;
        a = a && node->getRight()->getColor() == BLACK;
        a = a && node->getParent()->getColor() == BLACK;
    }
    if (node->hasLeft()) {
        b = this->rule4(node->getLeft());
    }
    if (node->hasRight()) {
        c = this->rule4(node->getRight());
    }
    return a && b && c;
}

template<typename T>
bool RBTree<T>::rule4(void) {
    return this->rule4(this->getRoot());
}

template<typename T>
bool RBTree<T>::rule5(Node<T> * node) {
    int pathCount = -1;//the number of black nodes to get '+here+'
    return this->rule5(node, 0, &pathCount);
}

template<typename T>
bool RBTree<T>::rule5(Node<T> * node, int blackCount, int * pathCount) {
    bool a, b, c;
    a = true;
    b = true;
    c = true;
    if (node->getColor() == BLACK) {
        ++blackCount;
    }
    if (node == NULL) {
        if (*pathCount == -1) {
            *pathCount = blackCount;
        } else if (blackCount != *pathCount) {
            a = false;
        }
    }
    if(node != NULL) {
        b = this->rule5(node->getLeft(), blackCount, pathCount);
        c = this->rule5(node->getRight(), blackCount, pathCount);
    }
    return a && b && c;
}

template<typename T>
bool RBTree<T>::rule5(void) {
    return this->rule5(this->getRoot());
}

template<typename T>
bool RBTree<T>::rules(void) {
    return this->rule1() && this->rule2() && this->rule4() && this->rule5();
}

/******************************************************************************
 *                                                                           **
 * MISC                                                                      **
 *                                                                           **
 ******************************************************************************/

template<typename T>
int RBTree<T>::exists(int key) {
    Node<T> * node = this->root;
    while (node != NULL) {
        if (node->getKey() == key) {
            break;
        } else if (node->getKey() < key) {
            node = node->getLeft();
        } else {
            node = node->getRight();
        }
    }
    return node->getMultiplicity();
}

template<typename T>
T RBTree<T>::extract(int key) {
    Node<T> * node = this->root;
    while (node != NULL) {
        if (node->getKey() == key) {
            break;
        } else if (node->getKey() == key < 0) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    T data = node->getData();
    if (node->remove()) {
        //this->delete(key);
    }
    return data;
}

/******************************************************************************
 *                                                                           **
 * RELATIONS                                                                 **
 *                                                                           **
 ******************************************************************************/

 template<typename T>
 Node<T> * RBTree<T>::next(Node<T> * node) {
     if (node == NULL) {
         return NULL;
     }
     if (node->hasRight()) {
         return this->first(node->getRight());
     }
     Node<T> * a = node->getParent();
     Node<T> * b = node;
     while (a != NULL && b == a->getRight()) {
         b = a;
         a = a->getParent();
     }
     return a;
 }

 template<typename T>
 Node<T> * RBTree<T>::previous(Node<T> * node) {
     if (node == NULL) {
         return NULL;
     }
     if (node->getLeft() != NULL) {
         return this->last(node->getLeft());
     }
     Node<T> * a = node->getParent();
     Node<T> * b = node;
    while (a != NULL && b == a->getLeft()) {
        b = a;
        a = a->getParent();
    }
    return a;
 }

 template<typename T>
 Node<T> * RBTree<T>::first(Node<T> * node) {
     return node->hasLeft()? this->first(node->getLeft()): node;
 }

 template<typename T>
 Node<T> * RBTree<T>::first() {
     return this->first(this->getRoot());
 }

 template<typename T>
 Node<T> * RBTree<T>::last(Node<T> * node) {
     return node->hasRight()? this->last(node->getRight()): node;
 }

 template<typename T>
 Node<T> * RBTree<T>::last() {
     return this->last(this->getRoot());
 }

 template<typename T>
 Node<T> * RBTree<T>::sibling(Node<T> * node) {
     Node<T> * sibling = NULL;
     if (node->isLeft()) sibling = node->getParent()->getLeft();
     if (node->isRight()) sibling = node->getParent()->getRight();
     return sibling;
 }

 template<typename T>
 Node<T> * RBTree<T>::parent(Node<T> * node) {
     return node->getParent();
 }

 template<typename T>
 Node<T> * RBTree<T>::grandpa(Node<T> * node) {
     Node<T> * grandpa = NULL;
     if (node->hasParent() && node->getParent()->hasParent()) {
        grandpa = node->getParent()->getParent();
     }
     return grandpa;
 }

 template<typename T>
 Node<T> * RBTree<T>::uncle(Node<T> * node) {
     Node<T> * uncle = NULL;
     if (node->hasParent() && node->getParent()->hasParent()) {
         if (node->getParent()->isLeft()) {
             uncle = this->grandpa(node)->getRight();
         } else if (node->getParent()->isRight()) {
             uncle = this->grandpa(node)->getLeft();
         }
     }
     return uncle;
 }

/******************************************************************************
 *                                                                           **
 * INSERTION                                                                 **
 *                                                                           **
 ******************************************************************************/

 template<typename T>
 bool RBTree<T>::insert(int key, T data) {
     return this->insert(new Node<T>(key,data));
 }

template<typename T>
bool RBTree<T>::insert(Node<T> * node) {
    if (this->root == NULL) {
        this->root = node;
    } else {
        Node<T> * root = this->getRoot();

        //add where it belongs as if this was a bst
        while (true) {
            if (node->getKey() == root->getKey()) {
                if (node->getData() == root->getData()) {
                    root->add();
                    return true;
                } else {
                    return false;
                }
            } else if (node->getKey() < root->getKey()) {
                if (root->hasLeft()) {
                    root = root->getLeft();
                } else {
                    root->setLeft(node);
                    break;
                }
            } else {
                if (root->hasRight()) {
                    root = root->getRight();
                } else {
                    root->setRight(node);
                    break;
                }
            }
        }

        if (node->getParent()->isLeft()) {
            this->grandpa(node)->setLeft(root);
        } else if (node->getParent()->isRight()) {
            this->grandpa(node)->setRight(root);
        }
    }
    this->insertCase1(node);
    return rules();
}

template<typename T>
void RBTree<T>::insertCase1(Node<T> * node) {
    if (!node->hasParent()) {
        node->setColor(BLACK);
    } else {
        this->insertCase2(node);
    }
}

template<typename T>
void RBTree<T>::insertCase2(Node<T> * node) {
    if (node->getParent()->getColor() == BLACK) {
        return;
    } else {
        this->insertCase3(node);
    }
}

template<typename T>
void RBTree<T>::insertCase3(Node<T> * node) {
    if (this->uncle(node)->getColor() == RED) {
        node->getParent()->setColor(BLACK);
        this->uncle(node)->setColor(BLACK);
        this->grandpa(node)->setColor(RED);
        this->insertCase1(this->grandpa(node));
    } else {
        insertCase4(node);
    }
}

template<typename T>
void RBTree<T>::insertCase4(Node<T> * node) {
    if (node->isRight() && node->getParent()->isLeft()) {
        rotateLeft(node->getParent());
        node = node->getLeft();
    } else if (node->isLeft() && node->getParent()->isRight()) {
        rotateRight(node->getParent());
        node = node->getRight();
    }
    insertCase5(node);
}

template<typename T>
void RBTree<T>::insertCase5(Node<T> * node) {
    node->getParent()->setColor(BLACK);
    this->grandpa(node)->setColor(RED);
    if (node->isLeft() && node->getParent()->isLeft()) {
        rotateRight(this->grandpa(node));
    } else {
        rotateLeft(this->grandpa(node));
    }
}
#endif
