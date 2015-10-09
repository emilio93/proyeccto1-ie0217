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
 * always be changed from red to black, but not necessarily vice versa, this
 * rule has little effect on analysis.
 * 	3 - All leaves (NIL) are black.
 *  4 - If a node is red, then both its children are black.
 *  5 - Every path from a given node to any of its descendant NIL nodes contains
 * the same number of black nodes. The uniform number of black nodes in the
 * paths from root to leaves is called the black-height of the red–black tree.
 */
class RBTree{
    private:
        /**
         * @breif The root of the tree, this is, the first element,
         *        this is the only one that needs to be known, since
         *        all the other ones are derived from this.
         */
        Node<T> * root;

        /**
         * @breif Creates a node.
         * @param key The nodes key.
         * @param data The nodes data.
         * @return The created node.
         */
        Node<T> * createNode(int key, T data, Node<T> * parent);

        /**
         * @breif Makes a left rotation on a given node.
         * @param rbt The tree to rotate.
         * @param node The pivot.
         */
        void rotateLeft(RBTree rbt, Node<T> * node);

        /**
         * @breif Makes a right rotation on a given node.
         * @param rbt The tree to rotate.
         * @param node The pivot.
         */
        void rotateRight(RBTree rbt, Node<T> * node);

        /**
         * Replaces a node.
         * @param rbt The tree in which to replace.
         * @param oldNode The node to remove.
         * @param newNode The node to place.
         */
        void replaceNode(RBTree rbt, Node<T> *oldNode, Node<T> * newNode);

        /**
         * Checks 1st rbtree rule on a node.
         * @param  node Node to check.
         */
        bool rule1(Node<T> * node);


        //Leaves are null, therefore cannot have a color, we assume theyre black.
        //bool rule3(Node<T> * rootNode);

        /**
         * Checks 4th rbtree rule on a node.
         * @param  node Node to check.
         */
        bool rule4(Node<T> * node);

        /**
         * Checks 5th rbtree rule on a node.
         * @param  node Node to check.
         */
        bool rule5(Node<T> * rootNode);

        /**
         * Checks 5th rbtree rule on a node.
         * @param  node Node to check.
         */
        bool rule5(Node<T> * rootNode, int count, int * count2);

    public:

        /**
         * Checks 1st rbtree rule on the tree.
         */
        bool rule1(void);

        /**
         * Checks 2nd rbtree rule.
         */
        bool rule2(void);

        /**
         * Checks 4th rbtree rule on the tree.
         */
        bool rule4(void);

        /**
         * Checks 5th rbtree rule on the tree.
         */
        bool rule5(void);

        /**
         * @breif Creates a red-black tree with the root Node of the given key
         *        and data.
         * @param key The root nodes key.
         * @param data The root nodes data.
         */
        RBTree(int key, T data);


        RBTree(Node<T> * node);

        /**
         * @breif Inserts an element into the tree, indicates if
         *        data was inserted correctly by returning true.
         *        If element is already in the tree, the multiplicity
         *        of the element will be increased.
         *
         * @param  data The data to insert.
         * @return      True if the insertion was made correctly.
         */
        bool insert(Node<T> * node);

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
         * @breif Removes an element from the tree, this will remove the element
         * @param  data Data to search and remove.
         * @return      True if element was removed.
         */
        bool remove(Node<T> * node);

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
         * @breif Returns nodes left child.
         * @param node The reference node.
         * @return The reference nodes left child.
         */
        Node<T> * leftChild(Node<T> * node);

        /**
         * @breif Returns nodes right child.
         * @param node The reference node.
         * @return The reference nodes right child.
         */
        Node<T> * rightChild(Node<T> * node);


/*
X        rbtree rbtree_create();
        void* rbtree_lookup(rbtree t, void* , compare_func compare);
        void rbtree_insert(rbtree t, void* , void* , compare_func compare);
        void rbtree_delete(rbtree t, void* , compare_func compare);
        node grandparent(node n);
        node sibling(node n);
        node uncle(node n);
        void verify_properties(rbtree t);
X        void verify_property_1(node root);
X        void verify_property_2(node root);
X        color node_color(node n);
X        void verify_property_4(node root);
X        void verify_property_5(node root);
X        void verify_property_5_helper(node n, int , int*);
X        node new_node(void* key, void* , color , node , node);
        node lookup_node(rbtree t, void* , compare_func compare);
        void rotate_left(rbtree t, node n);
        void rotate_right(rbtree t, node n);
X        void replace_node(rbtree t, node oldn, node newn);
        void insert_case1(rbtree t, node n);
        void insert_case2(rbtree t, node n);
        void insert_case3(rbtree t, node n);
        void insert_case4(rbtree t, node n);
        void insert_case5(rbtree t, node n);
        node maximum_node(node root);
        void delete_case1(rbtree t, node n);
        void delete_case2(rbtree t, node n);
        void delete_case3(rbtree t, node n);
        void delete_case4(rbtree t, node n);
        void delete_case5(rbtree t, node n);
        void delete_case6(rbtree t, node n);
*/

};

template<typename T>
RBTree<T>::RBTree(int key, T data) {
    this->root = this->createNode(key, data, NULL);
}

template<typename T>
RBTree<T>::RBTree(Node<T> * node) {
    this->root = node;
}

template<typename T>
Node<T> * RBTree<T>::createNode(int key, T data, Node<T> * parent) {
    Node<T> * n = new Node<T>(key, data, parent);
    return n;
}

template<typename T>
void RBTree<T>::replaceNode(RBTree rbt, Node<T> * oldNode, Node<T> * newNode) {
    //So we are replacing the parent
    if (oldNode->parent == NULL) { rbt->root = newNode; }
    else {
        if (oldNode->isLeft()) { oldNode->parent->left = newNode; }
        else { oldNode->parent->right = newNode; }
    }

    if (newNode != NULL) { newNode->parent = oldNode->parent; }
}

template<typename T>
void RBTree<T>::rotateLeft(RBTree rbt, Node<T> * node) {
    Node<int> * r = node->right;
    replaceNode(rbt, node, r);
    node->right = r->left;
    if (r->left != NULL) { r->left->parent = node; }
    r->left = node;
    node->parent = r;
}

template<typename T>
void RBTree<T>::rotateRight(RBTree rbt, Node<T> * node) {
    Node<int> * l = node->left;
    replaceNode(rbt, node, l);
    node->left = l->right;
    if (l->right != NULL) { l->right->parent = node; }
    l->right = node;
    node->parent = l;
}

template<typename T>
bool RBTree<T>::rule1(Node<T> * node) {
    bool a = node->getColor() == RED || node->getColor() == BLACK;
    bool b = true;
    bool c = true;
    if (node->getLeft() != NULL) { b = this->rule1(node->getLeft()); }
    if (node->getRight() != NULL) { c = this->rule1(node->getRight()); }
    return a && b && c;
}

template<typename T>
bool RBTree<T>::rule1() {
    return this->rule1(this->root);
}

template<typename T>
bool RBTree<T>::rule2() {
    return this->root->getColor() == BLACK;
}

template<typename T>
bool RBTree<T>::rule4(Node<T> * node) {
    bool a = true;
    if (node->getColor() == RED) {
        a = a && node->getLeft()->getColor() == BLACK;
        a = a && node->getRight()->getColor() == BLACK;
        a = a && node->getParent()->getColor() == BLACK;
    }
    if (node == NULL) {
        a = false;
    }
    bool b = true;
    bool c = true;
    if (node->getLeft() != NULL) { b = this->rule4(node->getLeft()); }
    if (node->getRight() != NULL) { c = this->rule4(node->getRight()); }
    return a && b && c;
}

template<typename T>
bool RBTree<T>::rule4(void) {
    return this->rule4(this->root);
}

template<typename T>
bool RBTree<T>::rule5(Node<T> * node) {
    int pathCount = -1;
    return this->rule5(node, 0, &pathCount);
}

template<typename T>
bool RBTree<T>::rule5(void) {
    return this->rule5(this->root);
}

template<typename T>
bool RBTree<T>::rule5(Node<T> * node, int blackCount, int * pathCount) {
    bool a = true;
    if (node->getColor() == BLACK) { blackCount++; }
    if (node == NULL)
    {
        if (*pathCount == -1) {
            *pathCount = blackCount;
        }
        else {
            if (blackCount != *pathCount) {
                a = false;
            }
        }
        return true;
    }
    bool b = true;
    bool c = true;
    if (node->getLeft() != NULL) { b = this->rule5(node->getLeft(), blackCount, pathCount); }
    if (node->getRight() != NULL) { c = this->rule5(node->getRight(), blackCount, pathCount); }

    return a && b && c;
}

template<typename T>
int RBTree<T>::exists(int key) {
    Node<T> * node = this->root;
    while (node != NULL) {
        if (node->getKey() == key) {
            return node->getMultiplicity();
        } else if (node->getKey() == key < 0) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    return node->getMultiplicity();
}

template<typename T>
T RBTree<T>::extract(int key) {
    Node<T> * node = this->root;
    while (node != NULL) {
        if (node->getKey() == key) {
            return node->getData();
        } else if (node->getKey() == key < 0) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    return node->getData();
}

template<typename T>
Node<T> * RBTree<T>::next(Node<T> * node) {
    if (node->isLeft()) {
        if (node->getRight() != NULL) {
            return node->getParent();
        } else {
            return this->first(node->getRight());
        }
    }
}

template<typename T>
Node<T> * RBTree<T>::previous(Node<T> * node) {
    if (node->isRight()) {
        if (node->getLeft() != NULL) {
            return node->getParent();
        } else {
            return this->last(node->getLeft());
        }
    }
}

template<typename T>
Node<T> * RBTree<T>::first(Node<T> * node) {
    return node->getLeft() == NULL ? node : this->first(node->getLeft());
}

template<typename T>
Node<T> * RBTree<T>::first() {
    return this->first(this->root);
}

template<typename T>
Node<T> * RBTree<T>::last(Node<T> * node) {
    return node->getRight() == NULL ? node : this->last(node->getRight());
}

template<typename T>
Node<T> * RBTree<T>::last() {
    return this->last(this->root);
}


#endif
