#ifndef ADS_2024_CA2_Jianfeng_Han_TREEMAP_H
#define ADS_2024_CA2_Jianfeng_Han_TREEMAP_H
#pragma once
#include "BinaryTree.h"
#include "BSTNode.h"
using namespace std;
//#include <set>

template <class K, class V>
class TreeMap {
private:
    BinaryTree<pair<K, V>> tree;

public:
    TreeMap();
    TreeMap(const TreeMap<K, V>& other);
    TreeMap<K, V>& operator=(const TreeMap<K, V>& other);

    void clear(); // clear all the element in the treemap
    bool containsKey(const K& key); // check if the given key exists in the treeMap.
    V& get(const K& key);
    void put(const K& key, const V& value);  // adds a key value pair in the treeMap
    int size(); // returns the number of elements in the treeMap
    bool removeKey(const K& key); // remove key from treemap
    BinaryTree<K> keySet();  // Returns a BinaryTree containing all keys in the TreeMap
    V& operator[](const K& key); //Overloads operator[] to retrieve or update value by key
};

template <class K, class V>
TreeMap<K, V>::TreeMap() {}

template <class K, class V>
TreeMap<K, V>::TreeMap(const TreeMap<K, V>& other) : tree(other.tree) {}

template <class K, class V>
TreeMap<K, V>& TreeMap<K, V>::operator=(const TreeMap<K, V>& other) {
    if (this == &other)
        return *this;
    tree = other.tree;
    return *this;
}

template <class K, class V>
void TreeMap<K, V>::clear() {
    tree.clear();
}

template <class K, class V>
bool TreeMap<K, V>::containsKey(const K& key) {
    BSTNode<pair<K, V>>* current = tree.getRoot();

    while (current != nullptr) {
        if (current->getItem().first == key) {
            return true;
        } else if (key < current->getItem().first) {
            current = current->getLeft();
        } else {
            current = current->getRight();
        }
    }

    return false;  // Key not found
}

template <class K, class V>
V& TreeMap<K, V>::get(const K& key) {
    BSTNode<pair<K, V>>* current = tree.getRoot();
    while (current != nullptr) {
        if (current->getItem().first == key) {
            return current->getItem().second; // Return the value directly
        } else if (key < current->getItem().first) {
            current = current->getLeft();
        } else {
            current = current->getRight();
        }
    }
//    throw runtime_error("Key not found"); // Handle not found case
}

template <class K, class V>
void TreeMap<K, V>::put(const K& key, const V& value) {
    pair<K, V> newItem(key, value);
    if (containsKey(key)) {
        auto& item = get(key); // Use the updated get method
        item = value; // Update the value
    } else {
        tree.add(newItem); // Make sure this method adds the pair correctly
    }
}

template <class K, class V>
int TreeMap<K, V>::size() {
    return tree.count();
}

template <class K, class V>
bool TreeMap<K, V>::removeKey(const K& key) {
    pair<K, V> itemToRemove(key, V{});
    return tree.remove(itemToRemove);
}

template <class K, class V>
BinaryTree<K> TreeMap<K, V>::keySet() {
    BinaryTree<K> keysTree;
    auto items = tree.toArray();
    int size = tree.count();

    for (int i = 0; i < size; ++i) {
        keysTree.add(items[i].first);
    }
    delete[] items;
    return keysTree;
}

template <class K, class V>
V& TreeMap<K, V>::operator[](const K& key) {
    return get(key);
}
#endif //ADS_2024_CA2_Jianfeng_Han_TREEMAP_H
