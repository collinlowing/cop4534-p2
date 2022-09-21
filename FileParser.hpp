/***************************************************************
  Student Name: Collin Lowing
  File Name: FileParser.hpp
  Project 2

  Reads files for testing
***************************************************************/

#ifndef COP4534_P2_FILEPARSER_HPP
#define COP4534_P2_FILEPARSER_HPP

#include <string>
#include <fstream>
#include <iostream>
#include <vector>

class FileParser {
public:
    std::vector<int> getTestValuesFromFile(std::string fileName);
};


#endif //COP4534_P2_FILEPARSER_HPP
