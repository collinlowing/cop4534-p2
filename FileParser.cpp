/***************************************************************
  Student Name: Collin Lowing
  File Name: FileParser.cpp
  Project 2

  Reads files for testing
***************************************************************/

#include "FileParser.hpp"

std::vector<int> FileParser::getTestValuesFromFile(std::string fileName) {
    std::vector<int> values;
    int i = 0;
    std::string line;
    std::ifstream fileInputStream(fileName);

    // if fileInputStream is not opened
    if (!fileInputStream.is_open()) {
        std::cout << "fatal error: " << fileName << " could not be opened." << std::endl;
        return values;
    }

    // read lines from file
    while (std::getline(fileInputStream, line)) {
        // convert string to int value
        values.push_back(std::stoi(line));
        i++;
    }

    fileInputStream.close();

    return values;
}
