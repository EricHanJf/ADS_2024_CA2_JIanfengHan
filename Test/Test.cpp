#include <gtest/gtest.h>
#include "../Header/TreeMap.h"
#include "../Header/Book.h"
#include <set>
#include <vector>
using namespace std;

// Test for the isValidLetter function
TEST(ValidationTests, ValidLetter) {
    EXPECT_TRUE(isValidLetter('a'));
    EXPECT_TRUE(isValidLetter('z'));
    EXPECT_TRUE(isValidLetter('G'));
    EXPECT_TRUE(isValidLetter('A'));
    EXPECT_TRUE(isValidLetter('B'));
    EXPECT_TRUE(isValidLetter('l'));
    EXPECT_FALSE(isValidLetter('%'));
    EXPECT_FALSE(isValidLetter('.'));
    EXPECT_FALSE(isValidLetter('/'));
    EXPECT_FALSE(isValidLetter('1'));
    EXPECT_FALSE(isValidLetter('@'));
    EXPECT_FALSE(isValidLetter('?'));
}

TEST(TreeMapTest, ContainsKey) {
    TreeMap<char, set<string>> wordMap;
    wordMap.put('c', {"cat", "car"});

    EXPECT_TRUE(wordMap.containsKey('c'));
    EXPECT_FALSE(wordMap.containsKey('z'));
}

// Test for querying words in the TreeMap
TEST(TreeMapTest, QueryWords) {
    TreeMap<char, set<string>> wordMap;
    wordMap.put('a', {"apple", "ant", "animal"});
    wordMap.put('b', {"banana", "berry"});

    EXPECT_TRUE(wordMap.containsKey('a'));
    EXPECT_FALSE(wordMap.containsKey('c'));

    const set<string>& words = wordMap.get('a');
    EXPECT_EQ(words.size(), 3);
    EXPECT_NE(words.find("apple"), words.end());
}

// Test for loading data from a CSV file
TEST(BookTests, LoadData) {
    string filename = "/Users/xhanhan/Library/CloudStorage/OneDrive-DundalkInstituteofTechnology/DKIT Year3/Year3 Algorithms and Data Structures/ADS_2024_CA2_Jianfeng_Han/books.csv";
    vector<Book> books = loadData(filename);
    EXPECT_FALSE(books.empty()); // Ensure books are loaded
}

// Test for sorting books by title

class BookTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Create the test_books.csv file with the expected content
        ofstream outFile("test_books.csv");
        outFile << "ID,Title,Author,Year,Genre,Price\n";
        outFile << "1,The Great Gatsby,Scott Fitzgerald,1925,Fiction,8.99\n";
        outFile << "2,1984,George Orwell,1949,Dystopian,6.99\n";
        outFile << "3,To Kill a Mockingbird,Harper Lee,1960,Fiction,7.99\n";
        outFile.close();
    }

    void TearDown() override {
        // Optionally remove the test file after the test
        remove("test_books.csv");
    }
};

//Test for Loading Books with Invalid Data
TEST_F(BookTest, LoadData) {
    vector<Book> books = loadData("test_books.csv");
    EXPECT_EQ(books.size(), 3);
    EXPECT_EQ(books[0].Title, "The Great Gatsby");
    EXPECT_EQ(books[0].Author, "Scott Fitzgerald");
    EXPECT_EQ(books[0].yearPublished, 1925);
    EXPECT_EQ(books[0].Genre, "Fiction");
    EXPECT_DOUBLE_EQ(books[0].Price, 8.99);
    EXPECT_EQ(books[2].Title, "To Kill a Mockingbird");
    EXPECT_EQ(books[2].Author, "Harper Lee");
    EXPECT_EQ(books[2].yearPublished, 1960);
    EXPECT_EQ(books[2].Genre, "Fiction");
    EXPECT_DOUBLE_EQ(books[2].Price, 7.99);
}

TEST_F(BookTest, CreateIndexByTitle) {
    vector<Book> books = loadData("test_books.csv");
    TreeMap<string, vector<Book>> index;
    createIndex(books, index, "title");
    EXPECT_TRUE(index.containsKey("The Great Gatsby"));
    EXPECT_TRUE(index.containsKey("1984"));
    EXPECT_EQ(index.get("To Kill a Mockingbird").size(), 1);
    EXPECT_EQ(index.get("1984").size(), 1);

}

//Test for displayIndex
TEST_F(BookTest, DisplayIndex) {
    vector<Book> books = loadData("test_books.csv");
    TreeMap<string, vector<Book>> index;
    createIndex(books, index, "author");
    EXPECT_NO_THROW(displayIndex(index));
}

//Test sort by Genre.
TEST_F(BookTest, ViewSubset) {
    vector<Book> books = loadData("test_books.csv");
    TreeMap<string, vector<Book>> index;
    createIndex(books, index, "genre");
    // Check for a valid genre
    EXPECT_NO_THROW(viewSubset(index, "Fiction"));
    EXPECT_NO_THROW(viewSubset(index,"Dystopian"));
    // Check for an invalid genre
    EXPECT_NO_THROW(viewSubset(index, "Romance"));
    EXPECT_NO_THROW(viewSubset(index, "Biography"));
}

//Test sort by title and author
TEST_F(BookTest, SortBooks) {
    vector<Book> books = loadData("test_books.csv");
    EXPECT_NO_THROW(sortBooks(books, "title"));
    EXPECT_NO_THROW(sortBooks(books, "author"));
}

//Test filter books by price
TEST_F(BookTest, FilterBooksByPrice) {
    vector<Book> books = loadData("test_books.csv");
    TreeMap<double, vector<Book>> index;
    createIndexByPrice(books, index);
    // Test filtering
    filterBooksByPrice(index, 5.0, 7.0);
}



