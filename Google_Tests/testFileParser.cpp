/***************************************************************
  Student Name: Collin Lowing
  File Name: testFileParser.cpp
  Project 2

  tests FileParser class methods
***************************************************************/

#include "gtest/gtest.h"
#include "../FileParser.hpp"

TEST(FileParserTests, getTestValuesFromFile) {
    std::string fileName = "../test1.txt";
    int expectedLambda = 2;
    int expectedMu = 3;
    int expectedM = 2;
    int expectedNumberOfEvents = 5000;
    FileParser fp;

    std::vector<int> values = fp.getTestValuesFromFile(fileName);
    std::size_t vectorLength = values.size();

    ASSERT_EQ(vectorLength, 4);
    EXPECT_EQ(values.at(0), expectedLambda);
    EXPECT_EQ(values.at(1), expectedMu);
    EXPECT_EQ(values.at(2), expectedM);
    EXPECT_EQ(values.at(3), expectedNumberOfEvents);
}