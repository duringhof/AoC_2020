#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<int> readInput(string file){
    // Reads input file and return a vector<int> called input
	vector<int> input;
	ifstream inputFile(file);
	int number;
	while (inputFile >> number){
		input.push_back(number);
	}
	inputFile.close();
	return input;
}

vector<string> readLines(string file) {
    // Reads input file and return a vector<string> called input
    vector<string> lines;
    ifstream inputFile(file);
    string line;
    while (getline(inputFile, line)){
        lines.push_back(line);
    }
    inputFile.close();
    return lines;
}

std::vector<std::string> split(const std::string &original, char delimiter = ' ', int maxSplits = -1)
{
	std::vector<std::string> result;
	std::string buffer;
	std::istringstream source(original);
	int splits = 0;

	while (getline(source, buffer, delimiter) && splits != maxSplits)
	{
		result.push_back(buffer);
		splits++;
	}
	return result;
}

std::vector<std::string> split(const std::string &original, const std::string &delimiter, int maxSplits = -1)
{
	std::vector<std::string> result;
	int splits = 0;
	size_t offset = 0;

	while (true)
	{
		if (splits == maxSplits)
		{
			break;
		}
		size_t pos = original.find(delimiter, offset);
		if (pos == std::string::npos)
		{
			break;
		}
		result.push_back(original.substr(offset, pos - offset));
		offset = pos + delimiter.length();
	}
	result.push_back(original.substr(offset));
	return result;
}

int main() {

    vector<string> lines = readLines("../input/day03.txt");
	cout << "Day 3 is not ready " << endl;
    return 0;
}