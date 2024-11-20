#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Dict.h"
#include "TableEntry.h"
#include <ostream>
#include <stdexcept>
#include "../act1/ListLinked.h"

template <typename V>
class HashTable : public Dict<V> {
private:
    int n; 
    int max;
    ListLinked<TableEntry<V> > *table; 

    int h(const std::string &key) const {
        int hash = 0;
        for (size_t i = 0; i < key.size(); ++i) {
            hash += static_cast<int>(key[i]);
        }
        return hash % max;
    }

public:
    HashTable(int size) : n(0), max(size) {
        this->table = new ListLinked<TableEntry<V> >[max];
    }

    ~HashTable() { delete[] table; }

    int capacity() const { return max; }

    friend std::ostream &operator<<(std::ostream &out, const HashTable<V> &th) {
        for (int i = 0; i < th.max; i++) {
            out << i << ": " << th.table[i] << std::endl;
        }
        return out;
    }

    V operator[](const std::string &key) {
        int pos = h(key);
        int idx = table[pos].search(TableEntry<V>(key));
        if (idx == -1) {
            throw std::runtime_error("Key not found.");
        }
        return table[pos].get(idx).value;
    }

    void insert(const std::string &key, V value) override{
        int pos = h(key);
        if (table[pos].search(TableEntry<V>(key)) != -1) {
            throw std::runtime_error("Key already exists.");
        }
        table[pos].append(TableEntry<V>(key, value));
        n++;
    }

    V search(const std::string &key) override{
        int pos = h(key);
        int idx = table[pos].search(TableEntry<V>(key));
        if (idx == -1) {
            throw std::runtime_error("Key does not exist.");
        }
        return table[pos].get(idx).value;
    }

    V remove(const std::string &key) override{
        int pos = h(key);
        int idx = table[pos].search(TableEntry<V>(key));
        if (idx == -1) {
            throw std::runtime_error("Key does not exist.");
        }
        V value = table[pos].get(idx).value;
        table[pos].remove(idx);
        n--;
        return value;
    }

    int entries() override{ return n; }
};

#endif
