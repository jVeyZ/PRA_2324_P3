#ifndef TABLEENTRY_H
#define TABLEENTRY_H

#include <string>
#include <ostream>

template <typename V> 
class TableEntry {
    public:
        std::string key;
        V value;

        TableEntry(std::string key, V value):key(key),value(value){}
        TableEntry(std::string key):key(key),value(NULL){}
        TableEntry():key(NULL),value(NULL){}
        friend bool operator==(const TableEntry<V> &te1, const TableEntry<V> &te2){
            return te1.key==te2.key; 
        }
        friend bool operator!=(const TableEntry<V> &te1, const TableEntry<V> &te2){
            return te1.key!=te2.key;
        }
        friend std::ostream& operator<<(std::ostream &out, const TableEntry<V> &te){
            out << te.key << "->" << te.value << std::endl;
            return out;
        }
    
};

#endif