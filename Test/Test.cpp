#include <gtest/gtest.h>
#include "../Header/TreeMap.h"  // Include your TreeMap header
#include "../Header/Book.h"    // Include your Book header
#include <set>
#include <vector>
using namespace std;

// Test for the isValidLetter function
TEST(ValidationTests, ValidLetter) {
    EXPECT_TRUE(isValidLetter('a'));
    EXPECT_TRUE(isValidLetter('z'));
    EXPECT_TRUE(isValidLetter('G'));
    EXPECT_FALSE(isValidLetter('1'));
    EXPECT_FALSE(isValidLetter('@'));
    EXPECT_FALSE(isValidLetter('?'));
}

// Test for loading data from a CSV file
TEST(BookTests, LoadData) {
    string filename = "/Users/xhanhan/Library/CloudStorage/OneDrive-DundalkInstituteofTechnology/DKIT Year3/Year3 Algorithms and Data Structures/ADS_2024_CA2_Jianfeng_Han/books.csv";
    vector<Book> books = loadData(filename);
    EXPECT_FALSE(books.empty()); // Ensure books are loaded
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






