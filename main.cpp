#include <iostream>
#include <memory>
#include "Person.h"
#include "HashTable.h"

int main() {
    HashTable<long, Person> hashTable;

    hashTable.put(81646674987, Person(81646674987, "Eduardo"));
    hashTable.put(11111111111, Person(11111111111, "Marcelo"));
    hashTable.put(22222222222, Person(22222222222, "Hanae"));
    hashTable.put(88868397900, Person(88868397900, "Djovana"));
    hashTable.put(12312312334, Person(12312312334, "Eduardo"));
    hashTable.put(12312312334, Person(32131232132, "Eduardo"));

    cout << "Percentage of use: " << hashTable.percentualFull() << "% (slots occupied)" << endl;
    cout << "Qtd of objects   : " << hashTable.getSize() << endl;

    // find() test
    Node<long, Person>* np = hashTable.get(81646674987);

    if (np != nullptr) {
        Person p = np->data();
        cout << "Founded: " << p << endl;
    } else {
        cout << "Not Founded" << endl;
    }


    // exists() test
    cout << "Exists person 'hanae'? " << (hashTable.exists(22222222222) ? "Yes" : "No") << endl;

    hashTable.remove(22222222222);
    cout << "Exists person 'hanae' after remove her? " << (hashTable.exists(22222222222) ? "Yes" : "No") << endl;

    return EXIT_SUCCESS;
}