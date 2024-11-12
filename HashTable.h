#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"

#include "../act1/ListLinked.h" 

template <typename V>
class HashTable: public Dict<V> {

    private:
        int n;
        int max;
        ListLinked<TableEntry<V>>* table;
        int h(std::string key){
            int temp = 0;
            int i = 0;
            while (i < key.size()) {
                temp += static_cast<int>(key[i]);
                i++;}
            return temp%max;
        }

    public:
        HashTable(int size):n(0),max(size){
            this->table = new ListLinked<TableEntry<V>>[size];
        }
        ~HashTable(){
            delete table;
        }
        int capacity(){
            return max;
        }
        friend std::ostream& operator<<(std::ostream &out, const HashTable<V> &th){
            for (int i = 0; i < th.capacity(); i++){out << th.table[i].key << "->" << th.table[i].value << std::endl;}
            return out;
        }
        V operator[](std::string key){
            search(key);
        }
        
        void insert(std::string key, V value) override {
            for (V node : table[max]) {
                if (node.key == key) {
                    throw std::runtime_error("Key already exists.");
                }
            }
            ListLinked<TableEntry<V>>::insert(n,value);
            n++;
        }
        V search(std::string key) override {
            int pos = h(key);
            for (V node : table[pos]) {
                if (node.key == key) {
                    return node.value;
                }
            }
            throw std::runtime_error("Key does not exist.");
        }
        V remove(std::string key) override {
            int pos = h(key);
            ListLinked<TableEntry<V>>::remove(pos);
            n--;
        }
        int entries() override {
            return n;
        }

        
};

#endif