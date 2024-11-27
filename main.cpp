#include "Header/TreeMap.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
//#include <cctype> // For isalpha and tolower

using namespace std;

int main() {
    // Create a TreeMap with char keys and set<string> values
    TreeMap<char, set<string>> wordMap;
    // dictionary.txt path
    ifstream inputFile("/Users/xhanhan/Library/CloudStorage/OneDrive-DundalkInstituteofTechnology/DKIT Year3/Year3 Algorithms and Data Structures/ADS_2024_CA2_Jianfeng_Han//dictionary.txt");
    string line, word;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        while (ss >> word) {
            // Ensure the first letter is valid and convert to lowercase
            char firstLetter = tolower(word[0]);
            if (!isalpha(firstLetter))
                continue; // Skip if the first character is not a letter
            // Insert the word into the TreeMap
            if (wordMap.containsKey(firstLetter)) {
                // If the letter exists in the TreeMap, insert the word into the set
                wordMap.get(firstLetter).insert(word);
            } else {
                // If the letter doesn't exist, create a new set and insert the word
                set<string> newSet;
                newSet.insert(word);
                wordMap.put(firstLetter, newSet);
            }
        }
    }
    inputFile.close();

    // Display the available letters (keys in the TreeMap)
    BinaryTree<char> keys = wordMap.keySet();  // Get the set of keys
    auto keysArray = keys.toArray();           // Convert to an array (ensure this returns a dynamically allocated array if needed)
    int size = keys.count();                   // Get the size of the array

    cout << "Available letters with words:";
    for (int i = 0; i < size; ++i) {
        cout << keysArray[i] << " "; // Display each available letter
    }
    cout << endl;

    // Query words by letter
    char query;
    while (true) {
        cout << "\nEnter a letter to see words (or '0' to quit): ";
        cin >> query;
        if (query == '0')
            break; //if enters 0, program will exit.

        query = tolower(query); // Convert to lowercase for consistency
        // Check if the letter exists in the TreeMap
        if (wordMap.containsKey(query)) {
            const set<string>& words = wordMap.get(query);  // Get the set of words starting with the query letter
            cout << "Words starting with '" << query << "':\n";
            for (const string& w : words) {
                cout << w << " "; // Display each word starting with the query letter
            }
            cout << endl;
        } else {
            cout << "No words found for '" << query << "'\n"; // Handle case where no words exist
        }
    }
    // Cleanup dynamic memory if keysArray is dynamically allocated
    delete[] keysArray;

    return 0;
}
