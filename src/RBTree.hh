#ifndef RBTREE_CLASS
#define RBTREE_CLASS

#include <stddef.h>//This gets NULL
#include "Node.hh"
#include "RBTree.hh"

using namespace std;

template<typename T>
/**
 * @breif The RBTree(Red-Black Tree) defines a collection of ordered
 *        elements of a multiset, each element is a node, with a given
 *        multiplicity and data.
 */
class RBTree{
    private:
        /**
         * @breif The root of the tree, this is, the first element,
         *        this is the only one that needs to be known, since
         *        all the other ones are derived from this.
         */
        Node<T> * root;

        Node<T> * createNode(int key, T data);

        void rotateLeft(Node<T> * node);
        void rotateRight(Node<T> * node);
        void replaceNode(Node<T> *oldNode, Node<T> * newNode);

    public:

        RBTree(int key, T data);

        /**
         * @breif Inserts an element into the tree, indicates if
         *        data was inserted correctly by returning true.
         *        If element is already in the tree, the multiplicity
         *        of the element will be increased.
         *
         * @param  data The data to insert.
         * @return      True if the insertion was made correctly.
         */
        bool insert(T data);

        /**
         * @breif Determines wether an element exists in the tree, if
         *        it does, the function returns the multiplicity of the
         *        element, else it will return 0.
         * @param  data The data to search for.
         * @return      The multiplicity of the element, 0 meaning the
         *              element was not found.
         */
        int exists(T data);

        /**
         * @breif Determines wether an element exists in the tree, if
         *        it does, the function returns true.
         * @param  data The data to search for.
         * @return      True if the element is found, false else.
         */
        bool exists(T data);

        /**
         * @breif Extracts an element from the tree if it's found.
         * @param  data The data to extract.
         * @return      The extracted data.
         */
        T extract(T data);

        T next(Node<T> * node);
        T previous(Node<T> * node);
        T first(Node<T> * node);
        T last(Node<T> * node);

};

#endif
