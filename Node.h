//
// Created by Eduardo Ribeiro da Silva on 05/11/19.
//

#ifndef SIMPLEHASHTABLETEMPLATE_NODE_H
#define SIMPLEHASHTABLETEMPLATE_NODE_H

#include <iostream>
#include <memory>

using namespace std;

template <typename K, typename T>
class Node {
public:
    explicit Node(const T&data, const K& key);
    ~Node();

    T data() const;

    K key() const;

    Node<K, T>* before() const;
    void before(Node<K, T>* _before);

    Node<K, T>* next() const;
    void next(Node<K, T>* _next);
private:
    T _data;
    K _key;
    Node<K, T>* _before;
    Node<K, T>* _next;
};

template <typename K, typename T>
Node<K, T>::Node(const T& data, const K& key): _data(data), _key(key)
{

}

template <typename K, typename T>
Node<K, T>::~Node() = default;

template <typename K, typename T>
T Node<K, T>::data() const
{
    return _data;
}

template<typename K, typename T>
K Node<K, T>::key() const
{
    return _key;
}

template <typename K, typename T>
Node<K, T>* Node<K, T>::before() const
{
    return _before;
}

template <typename K, typename T>
void Node<K, T>::before(Node<K, T>* _before)
{
    this->_before = _before;
}

template <typename K, typename T>
Node<K, T>* Node<K, T>::next() const
{
    return _next;
}

template <typename K, typename T>
void Node<K, T>::next(Node<K, T>* _next)
{
    this->_next = _next;
}

#endif //SIMPLEHASHTABLETEMPLATE_NODE_H
