#include <iostream>

using namespace std;

template<typename T>
Node<T>::Node(T data) {
    this->data = data;
}

template<typename T>
Node<T>::Node(T data, Node<T> * parent) {
    this->data = data;
    this->parent = parent;
    this->color = this->Colors.RED;
    this->multiplicity = 1;
}

template<typename T>
Node<T>::~Node(void) {
    int a = 1;
}

template<typename T>
void Node<T>::recolor(void) {
    if (this->color == this->Colors.RED) this->color = this->Colors.BLACK;
    else this->color = this->Colors.RED;
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
    this->left = left;
}

template<typename T>
void Node<T>::addRight(Node<T> * right) {
    this->right = right;
}
