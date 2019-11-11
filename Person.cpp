//
// Created by Eduardo Ribeiro da Silva on 05/11/19.
//
#include "Person.h"

Person::Person(long cpf, const string& name): cpf(cpf), name(name)
{

}

long Person::getCpf() const
{
    return this->cpf;
}

string Person::getName() const
{
    return this->name;
}

bool Person::operator==(const Person &other) {
    return this->cpf == other.cpf;
}

bool Person::operator!=(const Person &other) {
    return this->cpf != other.cpf;
}

ostream& operator<<(ostream& os, const Person& person) {
    os << "Person{cpf: " << person.cpf << ", name: '" << person.name << "}";
    return os;
}

