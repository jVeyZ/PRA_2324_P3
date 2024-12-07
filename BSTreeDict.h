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

        void insert(std::string key, V value) override {
            TableEntry<V> entry(key, value);
		    tree->insert(entry);
        }
       V search(std::string key) override
	{
		TableEntry<V> entry(key, V());
		return tree->search(entry).value;
	}
        
        V remove(std::string key) override{
            V aux = search(key);
            tree->remove(key);
            return aux;
        }
        
        int entries() override{
            return tree->size();
        }
        
};

#endif