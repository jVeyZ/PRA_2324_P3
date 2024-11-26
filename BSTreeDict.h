#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "BSTree.h"
#include "TableEntry.h"

template <typename V>
class BSTreeDict: public Dict<V> {

    private:
        BSTree<TableEntry<V>>* tree;

    public:
        BSTreeDict() : tree(new BSTree<TableEntry<V>>()) {}
        ~BSTreeDict(){ delete tree; }
        friend std::ostream& operator<<(std::ostream &out, const BSTreeDict<V> &bs){
            out << "cout << bstree: " << std::endl << bs.getTree() << std::endl;
            return out;
        }

        BSTree<TableEntry<V>>* getTree() const {
            return tree;
        }
        
        V operator[](std::string key){
            return search(key);
        }

        void insert(const std::string &key, V value){
            tree->insert(key, value);
        }
        V search(const std::string &key){
            TableEntry<V> entry(key);
            TableEntry<V>* result = tree->search(entry);
            if (result == nullptr) {
                throw std::runtime_error("Key not found");
            }
            return result->getValue();
        }
        
        V remove(const std::string &key){
            TableEntry<V> entry(key);
            TableEntry<V>* result = tree->search(entry);
            if (result == nullptr) {
                throw std::runtime_error("Key not found");
            }
            V value = result->getValue();
            tree->remove(entry);
            return value;
        }
        
        int entries() {
            return tree->size();
        }
        
};

#endif