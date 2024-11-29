#include "Header/TreeMap.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include "Header/Book.h"
//#include <cctype> // For isalpha and tolower

using namespace std;

int main() {
    // Create a TreeMap with char keys and set<string> values
//    TreeMap<char, set<string>> wordMap;
//    // dictionary.txt path
//    ifstream inputFile("/Users/xhanhan/Library/CloudStorage/OneDrive-DundalkInstituteofTechnology/DKIT Year3/Year3 Algorithms and Data Structures/ADS_2024_CA2_Jianfeng_Han//dictionary.txt");
//    string line, word;
//    while (getline(inputFile, line)) {
//        stringstream ss(line);
//        while (ss >> word) {
//            // Ensure the first letter is valid and convert to lowercase
//            char firstLetter = tolower(word[0]);
//            if (!isalpha(firstLetter))
//                continue; // Skip if the first character is not a letter
//            // Insert the word into the TreeMap
//            if (wordMap.containsKey(firstLetter)) {
//                // If the letter exists in the TreeMap, insert the word into the set
//                wordMap.get(firstLetter).insert(word);
//            } else {
//                // If the letter doesn't exist, create a new set and insert the word
//                set<string> newSet;
//                newSet.insert(word);
//                wordMap.put(firstLetter, newSet);
//            }
//        }
//    }
//    inputFile.close();
//
//    // Display the available letters (keys in the TreeMap)
//    BinaryTree<char> keys = wordMap.keySet();  // Get the set of keys
//    auto keysArray = keys.toArray();           // Convert to an array (ensure this returns a dynamically allocated array if needed)
//    int size = keys.count();                   // Get the size of the array
//
//    cout << "Available letters with words:";
//    for (int i = 0; i < size; ++i) {
//        cout << keysArray[i] << " "; // Display each available letter
//    }
//    cout << endl;
//
//    // Query words by letter
//    char query;
//    while (true) {
//        cout << "\nEnter a letter to see words (or '0' to quit): ";
//        cin >> query;
//        if (query == '0')
//            break; //if enters 0, program will exit.
//
//        query = tolower(query); // Convert to lowercase for consistency
//        // Check if the letter exists in the TreeMap
//        if (wordMap.containsKey(query)) {
//            const set<string>& words = wordMap.get(query);  // Get the set of words starting with the query letter
//            cout << "Words starting with '" << query << "':\n";
//            for (const string& w : words) {
//                cout << w << " "; // Display each word starting with the query letter
//            }
//            cout << endl;
//        } else {
//            cout << "No words found for '" << query << "'\n"; // Handle case where no words exist
//        }
//    }
//    // Cleanup dynamic memory if keysArray is dynamically allocated
//    delete[] keysArray;

    // Stage 4
    //csv File path
    string filename = "/Users/xhanhan/Library/CloudStorage/OneDrive-DundalkInstituteofTechnology/DKIT Year3/Year3 Algorithms and Data Structures/ADS_2024_CA2_Jianfeng_Han/books.csv";  // Update with the correct path to your CSV file
    vector<Book> books = loadData(filename);

    // Display menu options
    int choice = 0;
    while (choice != 4) {
        cout << "------------- Book Data Application -------------\n";
        cout << "|   1. Create an index based on a specific field|\n";
        cout << "|   2. View a subset of the data                |\n";
        cout << "|   3. Sort or filter books                     |\n";
        cout << "|   4. Exit                                     |\n";
        cout << "-------------------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            // Allow the user to create an index
            cout << "Choose a field to index:\n";
            cout << "1. Title\n";
            cout << "2. Author\n";
            cout << "3. Year Published\n";
            cout << "4. Genre\n";

            int fieldChoice;
            cout << "Please enter the number you want to search\n";
            cin >> fieldChoice;

            string field;
            switch (fieldChoice) {
                case 1:
                    field = "title";
                    break;
                case 2:
                    field = "author";
                    break;
                case 3:
                    field = "year";
                    break;
                case 4:
                    field = "genre";
                    break;
                default:
                    cout << "Invalid choice. Returning to main menu.\n";
                    continue;
            }
            TreeMap<string, vector<Book>> index;
            createIndex(books, index, field);  // Create the index for the chosen field
            displayIndex(index);              // Display unique values and entry counts

        } else if (choice == 2) {
            // Allow the user to view a subset of the data
            cout << "Choose a field to search by:\n";
            cout << "1. Title\n";
            cout << "2. Author\n";
            cout << "3. Year Published\n";
            cout << "4. Genre\n";
            int fieldChoice;
            cout << "Please enter the number you want to search\n";
            cin >> fieldChoice;

            string field;
            switch (fieldChoice) {
                case 1:
                    field = "title";
                    break;
                case 2:
                    field = "author";
                    break;
                case 3:
                    field = "year";
                    break;
                case 4:
                    field = "genre";
                    break;
                default:
                    cout << "Invalid choice. Returning to main menu.\n";
                    continue;
            }
            TreeMap<string, vector<Book>> index;
            createIndex(books, index, field);  //create the index for the chosen field
            string searchValue;
            cout << "Enter the value to search for: ";
            cin >> searchValue;
            viewSubset(index, searchValue);  // display books matching the key
        } else if (choice == 3) {
            cout << "------------- Sort or Filter Books -------------\n";
            cout << "1. Sort books\n";
            cout << "2. Filter books by price\n";
            cout << "Enter your choice: ";
            int subChoice;
            cout << "Enter 1-2 number that you want to search.\n ";
            cin >> subChoice;
            if (subChoice == 1) {
                // Sort books
                cout << "Choose a field to sort by:\n";
                cout << "1. Title\n";
                cout << "2. Author\n";
                cout << "3. Year Published\n";
                cout << "4. Genre\n";
                int fieldChoice;
                cin >> fieldChoice;

                string field;
                switch (fieldChoice) {
                    case 1:
                        field = "title";
                        break;
                    case 2:
                        field = "author";
                        break;
                    case 3:
                        field = "year";
                        break;
                    case 4:
                        field = "genre";
                        break;
                    default:
                        cout << "Invalid choice. Returning to main menu.\n";
                        continue;
                }
                sortBooks(books, field);

            } else if (subChoice == 2) {
                // Filter books by price
                double minPrice, maxPrice;
                cout << "Enter minimum price: ";
                cin >> minPrice;
                cout << "Enter maximum price: ";
                cin >> maxPrice;

                TreeMap<double, vector<Book>> index; // use TreeMap for price indexing
                createIndexByPrice(books, index);    // index the books by price
                filterBooksByPrice(index, minPrice, maxPrice); // filter using the TreeMap
            } else {
                cout << "Invalid choice. Returning to main menu.\n";
            }
        }else if (choice != 4) {
            cout << "Invalid choice. Please try again.\n";
        }
    }
    cout << "Exiting... bye!\n";
    return 0;
}
