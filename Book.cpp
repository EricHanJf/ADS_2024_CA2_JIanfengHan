//#include <iostream>
//#include <string>
//#include <vector>
//#include "Header/Book.h"       // Include your Book class and utility functions
//#include "Header/TreeMap.h"    // Include your TreeMap implementation
//
//using namespace std;
//
//int main() {
//    // Load the data from a CSV file
//    string filename = "books.csv";  // Update with the correct path to your CSV file
//    vector<Book> books = loadData(filename);
//
//    // Display menu options
//    int choice = 0; // Initialize choice
//    while (choice != 3) {
//        cout << "\n--- Book Data Application ---\n";
//        cout << "1. Create an index based on a specific field\n";
//        cout << "2. View a subset of the data\n";
//        cout << "3. Exit\n";
//        cout << "Enter your choice: ";
//        cin >> choice;
//
//        if (choice == 1) {
//            // Allow the user to create an index
//            cout << "Choose a field to index:\n";
//            cout << "1. Title\n2. Author\n3. Year Published\n4. Genre\n";
//            int fieldChoice;
//            cin >> fieldChoice;
//
//            string field;
//            switch (fieldChoice) {
//                case 1: field = "title"; break;
//                case 2: field = "author"; break;
//                case 3: field = "year"; break;
//                case 4: field = "genre"; break;
//                default:
//                    cout << "Invalid choice. Returning to main menu.\n";
//                    continue;
//            }
//
//            TreeMap<string, vector<Book>> index;
//            createIndex(books, index, field);  // Create the index for the chosen field
//            displayIndex(index);              // Display unique values and entry counts
//
//        } else if (choice == 2) {
//            // Allow the user to view a subset of the data
//            cout << "Choose a field to search by:\n";
//            cout << "1. Title\n2. Author\n3. Year Published\n4. Genre\n";
//            int fieldChoice;
//            cin >> fieldChoice;
//
//            string field;
//            switch (fieldChoice) {
//                case 1: field = "title"; break;
//                case 2: field = "author"; break;
//                case 3: field = "year"; break;
//                case 4: field = "genre"; break;
//                default:
//                    cout << "Invalid choice. Returning to main menu.\n";
//                    continue;
//            }
//
//            TreeMap<string, vector<Book>> index;
//            createIndex(books, index, field);  // Create the index for the chosen field
//
//            string searchValue;
//            cout << "Enter the value to search for: ";
//            cin.ignore(); // Ignore any leftover newline from previous input
//            getline(cin, searchValue);  // Get the full input as a string
//            viewSubset(index, searchValue);  // Display books matching the key
//
//        } else if (choice != 3) {
//            cout << "Invalid choice. Please try again.\n";
//        }
//    }
//
//    cout << "Exiting application. Goodbye!\n";
//    return 0;
//}
