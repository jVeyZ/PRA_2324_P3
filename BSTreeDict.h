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
            out << "cout << bstree: " << std::endl << *bs.tree << std::endl;
            return out;
        }

        V operator[](std::string key){
            return search(key);
        }

        void insert(const std::string &key, V value){
             tree->insert(TableEntry<V>(key, value));
        }
        V search(const std::string &key){
            TableEntry<V> entry(key);
            BSNode<TableEntry<V>>* result = tree->search(entry);
            if (result == nullptr) {
                throw std::runtime_error("Key not found");
            }
            return result->elem.value;
        }
        
        V remove(const std::string &key){
            TableEntry<V> entry(key);
            BSNode<TableEntry<V>>* result = tree->search(entry);
            if (result == nullptr) {
                throw std::runtime_error("Key not found");
            }
            V value = result->elem.value;
            tree->remove(entry);
            return value;
        }
        
        int entries() {
            return tree->size();
        }
        
};

#endif