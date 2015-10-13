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
        /* CLASS ATTRIBUTES
        1    int     key
        2    T       data
        3    int     multiplicity
        4    Node    * parent
        5    Node    * left
        6    Node    * right
        7    Colors  color
         */

        /**
         * @breif The key of the Node defines it's position in the tree.
         */
        int key;

        /**
         * @breif This is the data contained in the Node. Keep in mind that
         *        this class should have a way to be compared in order to
         *        arrangethe tree.
         */
        T data;

        /**
         * @breif This number indicates how many elements does the node contain
         *        (how many can it provide).
         */
        int multiplicity;

        /**
         * @breif Indicates the parent Node.
         */
        Node * parent = NULL;

        /**
         * @breif Indicates the left child Node.
         */
        Node * left = NULL;

        /**
         * @breif Indicates the right child Node.
         */
        Node * right = NULL;

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

        /**********************************************************************
         *                                                                   **
         * GETTERS                                                           **
         *                                                                   **
         **********************************************************************/
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

        /**********************************************************************
         *                                                                   **
         * SETTERS                                                           **
         *                                                                   **
         **********************************************************************/

         /**
          * @breif Sets the Node's key.
          * @param key The key to set.
          */
         void setKey(int key);

         /**
          * @breif Sets the Nodes's data.
          * @param data The data to set.
          */
         void setData(T data);

         /**
          * @breif Sets the Nodes's multiplicity.
          * @param data The multiplicity to set.
          */
         void setMultiplicity(int multiplicity);

         /**
          * @breif Sets the parent node.
          * @param parent The pointer to the node to add.
          */
         void setParent(Node<T> * node);

         /**
          * @breif Sets the child node on the left side, and indicates that
          *        this Node is now it's parent.
          * @param left The pointer to the node to add.
          */
         void setLeft(Node<T> * node);

         /**
          * @breif Sets the child node on the right side, and indicates that
          *        this Node is now it's parent.
          * @param right The pointer to the node to add.
          */
         void setRight(Node<T> * node);

        /**
         * @breif Changes the Node's color to a specific color.
         * @param c The color which the Node is going to have.
         */
        void setColor(Colors c);

        /**********************************************************************
         *                                                                   **
         * OTHER METHODS                                                     **
         *                                                                   **
         **********************************************************************/

        /**
         * @breif Adds an element, this is, increases the multiplicity.
         */
        void add(void);

        /**
         * @breif Removes an element, this is, decreases the multiplicity, when
         *        it reaches 0, it indicates returning true.
         * @return  True if the multiplicity reaches 0, ie, the Node must be
         *               deleted.
         */
        bool remove(void);

        /**
         * @breif Determines wheter Node is a Parent Node, it has either left or
         *        right.
         * @return  True if parent Node.
         */
        bool isParent(void);

        /**
         * @breif Determines wheter Node is a left Node, it doesn't mean it's
         *        right.
         * @return  True if left Node.
         */
        bool isLeft(void);

        /**
         * @breif Determines wheter Node is a right Node, it doesn't mean is
         *        left.
         * @return  True if right Node.
         */
        bool isRight(void);

        /**
         * @breif Determines wheter Node has a Parent Node.
         * @return  True if has parent Node.
         */
        bool hasParent(void);

        /**
         * @breif Determines wheter Node has a left Node.
         * @return  True if has left Node.
         */
        bool hasLeft(void);

        /**
         * @breif Determines wheter Node has a right Node.
         * @return  True if has right Node.
         */
        bool hasRight(void);
};


/******************************************************************************
 *                                                                           **
 * CLASS IMPLEMENTATION                                                      **
 *                                                                           **
 ******************************************************************************/

template<typename T>
Node<T>::Node(int key, T data) {
    this->setKey(key);
    this->setData(data);

    this->setMultiplicity(1);
    this->setColor(RED);
}

template<typename T>
Node<T>::Node(int key, T data, Node<T> * parent) {
    this->setKey(key);
    this->setData(data);
    this->setParent(parent);

    this-setMultiplicity(1);
    this->setColor(RED);
}


template<typename T>
Node<T>::~Node(void) {
    // REMOVE ALL REFERENCES
    this->setParent(NULL);
    this->setLeft(NULL);
    this->setRight(NULL);
    // REMOVE ALL ELEMENTS**
    while(this->remove() != true) { ;}
}

/******************************************************************************
 *                                                                           **
 * GETTERS                                                                   **
 *                                                                           **
 ******************************************************************************/

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

/******************************************************************************
 *                                                                           **
 * SETTERS                                                                   **
 *                                                                           **
 ******************************************************************************/

 template<typename T>
 void Node<T>::setKey(int key) {
     this->key = key;
 }

 template<typename T>
 void Node<T>::setData(T data) {
     this->data = data;
 }

 template<typename T>
 void Node<T>::setMultiplicity(int multiplicity) {
     this->multiplicity = multiplicity;
 }

 template<typename T>
 void Node<T>::setParent(Node<T> * node) {
     if (node == NULL) {
         this->parent = NULL;
         return;
     }
     this->parent = node;
 }

 template<typename T>
 void Node<T>::setLeft(Node<T> * node) {
     if (node == NULL) {
         this->left = NULL;
         return;
     }
     node->setParent(this);
     this->left = node;
 }

 template<typename T>
 void Node<T>::setRight(Node<T> * node) {
     if (node == NULL) {
         this->right = NULL;
         return;
     }
     node->setParent(this);
     this->right = node;
 }

 template<typename T>
 void Node<T>::setColor(Colors color) {
     this->color = color;
 }

/******************************************************************************
 *                                                                           **
 * OTHER METHODS                                                             **
 *                                                                           **
 ******************************************************************************/

template<typename T>
void Node<T>::add(void) {
    //this->setMultiplicity(this->getMultiplicity()+1);
    // Shouldn't be below 0, if lesser or equal to 0, then value after adding
    // is 1
    int value = this->getMultiplicity() <= 0? 1: this->getMultiplicity() + 1;
    this->setMultiplicity(value);
}

template<typename T>
bool Node<T>::remove(void) {
    // Shouldn't be lesser than 0.
    int value = this->getMultiplicity() <= 0? 0: this->getMultiplicity() - 1;
    this->setMultiplicity(value);
    bool empty = this->getMultiplicity() <= 0? true: false;
    return empty;
}

template<typename T>
bool Node<T>::isParent(void) {
    return this->hasLeft() || this->hasRight();
}

template<typename T>
bool Node<T>::isLeft(void) {
    // Is neither left or right, then is-Not-Left, not meaning it's right
    if (this->getParent() == NULL) return false;

    // NULL shouldn't be left.
    if (this->getParent()->getLeft() == NULL) return false;

    return this->getParent()->getLeft() == this;
}

template<typename T>
bool Node<T>::isRight(void) {
    // Is neither left or right, then is-Not-Right, not meaning it's left
    if (this->getParent() == NULL) return false;

    // NULL shouldn't be right.
    if (this->getParent()->getRight() == NULL) return false;

    return this->getParent()->getRight() == this;
}

template<typename T>
bool Node<T>::hasParent(void) {
    return this->getParent() != NULL;
}

template<typename T>
bool Node<T>::hasLeft(void) {
    return this->getLeft() != NULL;
}

template<typename T>
bool Node<T>::hasRight(void) {
    return this->getRight() != NULL;
}

#endif
