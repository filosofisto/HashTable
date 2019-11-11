//
// Created by Eduardo Ribeiro da Silva on 05/11/19.
//

#ifndef HASHTABLE_PERSON_H
#define HASHTABLE_PERSON_H

#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    explicit Person(long cpf, const string& name);
    virtual ~Person() = default;

    long getCpf() const;

    string getName() const;

    bool operator==(const Person& other);
    bool operator!=(const Person& other);

    friend ostream& operator<<(ostream& os, const Person& person);
private:

    long cpf;
    string name;
};

#endif //HASHTABLE_PERSON_H
