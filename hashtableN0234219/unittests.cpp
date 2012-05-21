#include "stdafx.h"
#include "table.h"
#include "gtest/gtest.h"


using namespace std; 

class HashTableTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
	testTable.insert("One", "Chris");	
	testTable.insert("Two", "Bill");
	testTable.insert("Three", "Richard");
	testTable.insert("Four", "John");
	testTable.insert("Five", "Keith");
	testTable.insert("Six", "Peter");
	testTable.insert("Seven", "Mark");
	testTable.insert("Eight", "Andrew");
	testTable.insert("Nine", "Gary");
	testTable.insert("Ten", "Matthew");
	testTable.insert("Eleven", "Steve");
	testTable.insert("Twelve", "Chris");	
	testTable.insert("Thirteen", "Bill");
	testTable.insert("Fourteen", "Richard");
	testTable.insert("Fifteen", "John");
	testTable.insert("Sixteen", "Keith");
	testTable.insert("Seventeen", "Peter");
	testTable.insert("Eighteen", "Mark");
	testTable.insert("Nineteen", "Andrew");
	testTable.insert("Twenty", "Gary");

	testTable.remove("Nineteen");
	testTable.remove("Twenty");
  }

  // virtual void TearDown() {}

  HashTable<string> testTable;
};

TEST_F(HashTableTest, RemovalTest) {
	EXPECT_TRUE(testTable.remove("Eighteen")) << "Removal method not successful";
}

TEST_F(HashTableTest, ExistenceTest) {
	EXPECT_TRUE(testTable.exists("Twenty")) << "Existence method not successful";
}

TEST_F(HashTableTest, ValueTest) {
	string actual = testTable.get("Ten");
	string expected = "Matthew";
	//ASSERT_STREQ(expected, actual) << "Get method not successful";
}

int main(int argc, _TCHAR* argv[]) {
testing::InitGoogleTest(&argc, argv); 
    RUN_ALL_TESTS(); 
    std::getchar(); // keep console window open until keystroke
}