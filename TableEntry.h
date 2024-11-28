#ifndef TABLEENTRY_H
#define TABLEENTRY_H

#include <string>
#include <ostream>

template <typename V> 
class TableEntry {
    public:
        std::string key;
        V value;

        TableEntry(const std::string &key, V value):key(key),value(value){}
        TableEntry(const std::string &key):key(key),value(V()){}
        TableEntry():key(""),value(V()){}
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
        friend bool operator<(const TableEntry<V> &te1, const TableEntry<V> &te2){
            return te1.value<te2.value;
        }
        friend bool operator>(const TableEntry<V> &te1, const TableEntry<V> &te2){
            return te1.value>te2.value;
        }
    
};

#endif