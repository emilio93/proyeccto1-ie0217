#ifndef NODE_CLASS
#define NODE_CLASS

#include <stddef.h>//This gets NULL
#include "Color.hh"

template<typename T>
/**
 * @breif The node class defines a multiset element.
 *
 * The node class defines a multiset element within it's red-black tree
 * implementation. It contains the data and the multiplicity, which are
 * related to the multiset concept. It also contains the tree elements
 * which are, key, color, left child and right child. In addition, this
 * implementation will know it's parent Node, (kind of like a doubly
 * linked list).
 */
class Node{
    private:
        /**
         * @breif The key of the Node defines it's position in the tree.
         */
        int key;

        /**
         * @breif This is the data contained in the Node. Keep in mind that
         *        this class should have a way to be compared in order to arrange
         *        the tree.
         */
        T data;

        /**
         * @breif This number indicates how many elements does the node contain(how
         *        many can it provide).
         */
        int multiplicity;

        /**
         * @breif Indicates the parent Node.
         */
        Node * parent = NULL;

        /**
         * @breif Indicates the left child Node.
         */
        Node * left;

        /**
         * @breif Indicates the right child Node.
         */
        Node * right;

        /**
         * @breif Indicates the color of the Node.
         */
        Colors color;

    public:
        /**
         * @breif Creates a Node with data. By default, the Node's color is red.
         *        Also the multiplicity will be 1. This is the constructor for
         *        the root node.
         * @param data The data which the node will contain.
         */
        Node(int key, T data);

        /**
         * @breif Creates a Node with data. By default, the Node's color is red.
         *        Also the multiplicity will be 1.
         * @param data The data which the node will contain.
         * @param parent The parent node.
         */
        Node(int key, T data, Node<T> * parent);

        /**
         * @breif Destructs the Node.
         */
        ~Node(void);

        /**
         * @breif Returns the Nodes key.
         * @return The Nodes key.
         */
        int getKey(void);

        /**
         * @breif Returns data in the node.
         * @return The data in the node.
         */
        T getData(void);

        /**
         * @breif Returns the multiplicity of the node.
         * @return The multiplicity of the node.
         */
        int getMultiplicity(void);

        /**
         * @breif Returns the parent node.
         * @return The parent node.
         */
        Node * getParent(void);

        /**
         * @breif Returns the left child node.
         * @return The left child node.
         */
        Node * getLeft(void);

        /**
         * @breif Returns right child node.
         * @return The right child node.
         */
        Node * getRight(void);

        /**
         * @breif Returns the nodes color.
         * @return The color of the current node.
         */
        Colors getColor(void);

        /**
         * @breif Toggle the Node's color.
         */
        void recolor(void);

        /**
         * @breif Changes the Node's color to a specific color.
         * @param c The color which the Node is going to have.
         */
        void recolor(Colors c);

        /**
         * @breif Adds an element, this is, increases the multiplicity.
         */
        void add(void);

        /**
         * @breif Removes an element, this is, decreases the multiplicity, when it
         *        reaches 0, it indicates returning true.
         * @return  True if the multipliciti reaches 0, ie, the Node must be deleted.
         */
        bool remove(void);

        /**
         * @breif Read the data within the Node.
         * @return  Data within the node
         */
        const T * read(void);

        /**
         * @breif Adds a child node on the left side;
         * @param left The pointer to the node to add.
         */
        void addLeft(Node<T> * left);

        /**
         * @breif Sets the child node on the left side;
         * @param left The pointer to the node to add.
         */
        void setLeft(Node<T> * left);

        /**
         * @breif Adds a child node on the right side;
         * @param left The pointer to the node to add.
         */
        void addRight(Node<T> * right);

        /**
         * @breif Sets the child node on the right side;
         * @param right The pointer to the node to add.
         */
        void setRight(Node<T> * right);

        /**
         * @breif Determines wheter Node is a left Node.
         * @return  True if left Node.
         */
        bool isLeft(void);

        /**
         * @breif Determines wheter Node is a right Node.
         * @return  True if right Node.
         */
        bool isRight(void);
};


/******************************
 *                            *
 *  THE CLASS IMPLEMENTATION  *
 *                            *
 ******************************/

template<typename T>
Node<T>::Node(int key, T data) {
    this->key = key;
    this->data = data;
    this->parent = NULL;
    this->left = NULL;
    this->right = NULL;
    this->color = RED;
}

template<typename T>
Node<T>::Node(int key, T data, Node<T> * parent) {
    this->key = key;
    this->data = data;
    this->parent = parent;
    this->left = NULL;
    this->right = NULL;
    this->color = RED;
    this->multiplicity = 1;
}


template<typename T>
Node<T>::~Node(void) {
    int a = 1;
}

template<typename T>
int Node<T>::getKey(void) {
    return this->key;
}

template<typename T>
T Node<T>::getData(void) {
    return this->data;
}

template<typename T>
int Node<T>::getMultiplicity(void) {
    return this->multiplicity;
}

template<typename T>
Node<T> * Node<T>::getParent(void) {
    return this->parent;
}

template<typename T>
Node<T> * Node<T>::getLeft(void) {
    return this->left;
}

template<typename T>
Node<T> * Node<T>::getRight(void) {
    return this->right;
}

template<typename T>
Colors Node<T>::getColor(void) {
    if (this == NULL) return BLACK;//it's a leaf, it's BLACKKKKKK
    return this->color;
}

template<typename T>
void Node<T>::recolor(void) {
    if (this->color == RED) this->color = BLACK;
    else this->color = RED;
}

template<typename T>
void Node<T>::recolor(Colors c) {
    this->color = c;
}

template<typename T>
void Node<T>::add(void) {
    ++this->multiplicity;
}

template<typename T>
bool Node<T>::remove(void) {
    bool empty = false;
    --this->multiplicity;
    if (this->multiplicity == 0) {
        empty = true;
    }
    return empty;
}

template<typename T>
const T * Node<T>::read(void) {
    return this->data;
}

template<typename T>
void Node<T>::addLeft(Node<T> * left) {
    if (this->left == NULL) this->left = left;
}

template<typename T>
void Node<T>::setLeft(Node<T> * left) {
    this->left = left;
}

template<typename T>
void Node<T>::addRight(Node<T> * right) {
    if (this->right == NULL) this->right = right;
}

template<typename T>
void Node<T>::setRight(Node<T> * right) {
    this->right = right;
}

template<typename T>
bool Node<T>::isLeft(void) {
    return this->parent->left == this;
}

template<typename T>
bool Node<T>::isRight(void) {
    return this->parent->right == this;
}

int compareKeys(int * leftKey, int * rightKey) {
    if (leftKey < rightKey) return -1;
    else if (leftKey > rightKey) return 1;
    else if (leftKey == rightKey) return 0;
    else return 0;
}

#endif
