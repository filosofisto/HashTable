//
// Created by Eduardo Ribeiro da Silva on 05/11/19.
//

#ifndef SIMPLEHASHTABLETEMPLATE_DOUBLELINKEDLIST_H
#define SIMPLEHASHTABLETEMPLATE_DOUBLELINKEDLIST_H

#include <memory>
#include <iostream>
#include "Node.h"

using namespace std;

template <typename K, typename T>
class DoubleLinkedList {
public:
    DoubleLinkedList();
    ~DoubleLinkedList();

    Node<K, T>* search(const K& key) const;

    void insert(const T& data, const K& key);

    void remove(Node<K, T>* node);

    size_t getSize() const;

    void print();
private:
    Node<K, T>* head;
    size_t size;
};

template<typename K, typename T>
DoubleLinkedList<K, T>::DoubleLinkedList(): size(0)
{

}

template<typename K, typename T>
DoubleLinkedList<K, T>::~DoubleLinkedList()
{
    auto node = head;
    auto nodeBefore = head;

    while (node != nullptr) {
        node = node->next();

        delete nodeBefore;
        nodeBefore = node;
    }

    if (nodeBefore != nullptr) {
        delete nodeBefore;
    }
}

template<typename K, typename T>
Node<K, T>* DoubleLinkedList<K, T>::search(const K& key) const {
    auto node = head;

    while (node != nullptr && node->key() != key) {
        node = node->next();
    }

    return node;
}

template<typename K, typename T>
void DoubleLinkedList<K, T>::insert(const T& data, const K& key) {
    auto node = new Node<K, T>(data, key);
    node->next(head);

    if (head != nullptr) {
        head->before(node);
    }

    head = node;
    node->before(nullptr);

    size++;
}

template<typename K, typename T>
void DoubleLinkedList<K, T>::remove(Node<K, T>* node)
{
    if (node == nullptr) {
        return;
    }

    if (node->before() == nullptr) {
        // head -> X -> Y
        // head = X.next (Y)
        // head -> Y
        head = node->next();

        // Y.before -> null (due to head -> Y)
        if (node->next() != nullptr) {
            node->next()->before(nullptr);
        }
    } else {
        // head -> W -> X -> Y
        // W.next = Y
        node->before()->next(node->next());

        // Y.before = W
        // head -> W -> Y
        if (node->next() != nullptr) {
            node->next()->before(node->before());
        }
    }

    size--;
}

template<typename K, typename T>
void DoubleLinkedList<K, T>::print()
{
    auto node = head;

    cout << "[";

    while (node != nullptr) {
        cout << *node->data();

        node = node->next();

        if (node != nullptr) {
            cout << " | ";
        }
    }

    cout << "]";
}

template<typename K, typename T>
size_t DoubleLinkedList<K, T>::getSize() const {
    return size;
}

#endif //SIMPLEHASHTABLETEMPLATE_DOUBLELINKEDLIST_H
