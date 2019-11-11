//
// Created by Eduardo Ribeiro da Silva on 05/11/19.
//

#ifndef HASHTABLE_HASHTABLE_H
#define HASHTABLE_HASHTABLE_H

#include <type_traits>
#include <iostream>

#include "DoubleLinkedList.h"

using namespace std;

constexpr int DEFAULT_CAPACITY = 100;

template <typename K, typename T>
class HashTable
{
public:
    HashTable();

    explicit HashTable(size_t capacity);

    virtual ~HashTable();

    void put(const K& key, const T& data);

    void remove(const K& key);

    Node<K, T>* get(const K& key) const;

    bool exists(const K& key) const;

    double percentualFull() const;

    size_t getSize() const;

    friend ostream& operator<<(ostream& os, const HashTable& hashTable);
private:
    size_t calcPosFromHash(const K& key) const;

    DoubleLinkedList<K, T> *getDoubleLinkedList(size_t pos) ;

    DoubleLinkedList<K, T>** slots;

    size_t capacity;
    size_t slotsCount;
};

template <typename K, typename T>
HashTable<K, T>::HashTable(): capacity(DEFAULT_CAPACITY), slotsCount(0)
{
    slots = new DoubleLinkedList<K, T>*[capacity];
}

template <typename K, typename T>
HashTable<K, T>::HashTable(size_t capacity): capacity(capacity), slotsCount(0)
{
    slots = new DoubleLinkedList<K, T>*[capacity];
}

template <typename K, typename T>
HashTable<K, T>::~HashTable()
{
    for (int i = 0; i < capacity; i++) {
        if (slots[i] != nullptr) {
            delete slots[i];
        }
    }

    delete[] slots;
}

template <typename K, typename T>
void HashTable<K, T>::put(const K& key, const T& data)
{
    size_t pos = calcPosFromHash(key);
    DoubleLinkedList<K, T> *linkedList = getDoubleLinkedList(pos);

    linkedList->insert(data, key);
}

template <typename K, typename T>
DoubleLinkedList<K, T>* HashTable<K, T>::getDoubleLinkedList(size_t pos) {
    DoubleLinkedList<K, T>* linkedList = slots[pos];
    if (linkedList == nullptr) {
        linkedList = new DoubleLinkedList<K, T>();
        slots[pos] = linkedList;
        slotsCount++;
    }
    return linkedList;
}

template <typename K, typename T>
void HashTable<K, T>::remove(const K& key)
{
    size_t pos = calcPosFromHash(key);

    DoubleLinkedList<K, T>* linkedList = slots[pos];
    if (linkedList == nullptr) {
        return;
    }

    auto node = linkedList->search(key);
    if (node != nullptr) {
        linkedList->remove(node);
    }
}

template <typename K, typename T>
Node<K, T>* HashTable<K, T>::get(const K& key) const
{
    size_t pos = calcPosFromHash(key);
    DoubleLinkedList<K, T>* linkedList = slots[pos];
    if (linkedList == nullptr) {
        return nullptr;
    }

    return linkedList->search(key);
}

template <typename K, typename T>
bool HashTable<K, T>::exists(const K& key) const
{
    return get(key) != nullptr;
}

template <typename K, typename T>
size_t HashTable<K, T>::calcPosFromHash(const K& key) const {
    size_t k = hash<K>{}(key);

    return k % capacity;
}

template <typename K, typename T>
ostream& operator<<(ostream& os, const HashTable<K, T>& hashTable)
{
    DoubleLinkedList<K, T>* linkedList;

    for (int i = 0; i < hashTable.capacity; i++) {
        linkedList = hashTable.slots[i];

        if (linkedList != nullptr) {
            os << "[" << i << "]: " << (*linkedList) << endl;
        }
    }

    return os;
}

template<typename K, typename T>
double HashTable<K, T>::percentualFull() const {
    return (static_cast<double>(slotsCount)/capacity)*100;
}

template<typename K, typename T>
size_t HashTable<K, T>::getSize() const {
    size_t total = 0;
    DoubleLinkedList<K, T>* linkedList;

    for (int i = 0; i < capacity; i++) {
        linkedList = slots[i];

        if (linkedList != nullptr) {
            total += linkedList->getSize();
        }
    }

    return total;
}

#endif //HASHTABLE_HASHTABLE_H
