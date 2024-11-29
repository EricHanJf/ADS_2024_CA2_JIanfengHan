//
// Created by Eric Han on 28/11/2024.
//

#ifndef ADS_2024_CA2_JIANFENG_HAN_BOOK_H
#define ADS_2024_CA2_JIANFENG_HAN_BOOK_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "TreeMap.h"
#include "BinaryTree.h"
#include "BSTNode.h"
using namespace std;

// public monostate, I don't understand because i got the error from line73, Clion helps me fixed and added it for me
struct Book : public monostate {
    int ID;
    string Title;
    string Author;
    int yearPublished;
    string Genre;
    double Price;

    // Equality operator (needed if used in containers like sets)
    bool operator==(const Book& other) const {
        return ID == other.ID;
    }
};

// load data from csv file
vector<Book> loadData(const string& filename) {
    vector<Book> books;
    ifstream file(filename);
    string line;
    getline(file, line);
    while (getline(file, line)) {
        stringstream ss(line);
        Book book;
        string year, price;
        getline(ss, line, ','); // Read ID as string first
        book.ID = stoi(line); // Convert to int
        getline(ss, book.Title, ',');
        getline(ss, book.Author, ',');
        getline(ss, year, ',');
        getline(ss, book.Genre, ',');
        getline(ss, price, ',');
        book.yearPublished = stoi(year);
        book.Price = stod(price);
        books.push_back(book);
    }
    return books;
}

// create an index for a specific field using TreeMap
void createIndex(const vector<Book>& books, TreeMap<string, vector<Book>>& index, const string& field) {
    for (const auto& book : books) {
        string key;
        if (field == "title")
            key = book.Title;
        else if (field == "author")
            key = book.Author;
        else if (field == "year")
            key = to_string(book.yearPublished);
        else if (field == "genre")
            key = book.Genre;
        else
            continue;
        if (!index.containsKey(key)) {
            index.put(key, vector<Book>());
        }
        index.get(key).push_back(book);
    }
}

//display the index of unique values
void displayIndex(TreeMap<string, vector<Book>> index) {
    BinaryTree<string> keys = index.keySet();
    auto keysArray = keys.toArray();
    int size = keys.count();
    cout << "Index of unique values:\n";
    for (int i = 0; i < size; i++) {
        const auto& key = keysArray[i];
        const auto& books = index.get(key);
        if (books.size() == 1){
            cout << key << " -> : " << books.size() << " entry\n";
        }else{
            cout << key << " -> : " << books.size() << " entries\n";
        }
    }
    delete[] keysArray; // Free allocated memory
}

// this is the function to view all books associated with a specific key
void viewSubset(TreeMap<string, vector<Book>> index, const string& key) {
    if (index.containsKey(key)) {
        const auto& books = index.get(key);
        cout << "Books with key '" << key << "':\n";
        for (const auto& book : books) {
            cout << "Book Title: "<< book.Title << " by " << book.Author << ", " << book.yearPublished
                 << ", Genre: " << book.Genre << ", Price: €" << book.Price << endl;
        }
    } else {
        cout << "No entries found for '" << key << "'\n";
    }
}

// the function to sort all book with key
void sortBooks(const vector<Book>& books, const string& field) {
    TreeMap<string, vector<Book>> index;
    createIndex(books, index, field); // build the index
    cout << "Books sorted by " << field << ":\n";
    // get the key as a BinaryTree
    BinaryTree<string> keysTree = index.keySet();
    // convert BinaryTree to an array
    auto keysArray = keysTree.toArray();
    int size = keysTree.count();    // Get the count of keys
    for (int i = 0; i < size; ++i) {
        // Access each key
        const string& key = keysArray[i];
        const auto& bookList = index.get(key); // Get books for the current key
        for (const auto& book : bookList) {
            cout << "Book Title: " << book.Title << " by " << book.Author << ", "
                 << book.yearPublished << ", Genre: " << book.Genre << ", Price: €" << book.Price << endl;
        }
    }
    delete[] keysArray;
}


#endif //ADS_2024_CA2_JIANFENG_HAN_BOOK_H
