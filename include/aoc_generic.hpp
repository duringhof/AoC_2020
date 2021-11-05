#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<int> readInput(std::string file);

std::vector<std::string> readLines(std::string file);

std::vector<std::string> split(const std::string &original, char delimiter = ' ', int maxSplits = -1);

std::vector<std::string> split(const std::string &original, const std::string &delimiter, int maxSplits = -1);