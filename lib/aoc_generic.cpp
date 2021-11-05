#include "aoc_generic.hpp"

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
};

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

vector<string> split(const string &original, char delimiter, int maxSplits) {

	vector<string> result;
	string buffer;
	istringstream source(original);
	int splits = 0;

	while (getline(source, buffer, delimiter) && splits != maxSplits)
	{
		result.push_back(buffer);
		splits++;
	}
	return result;
}

vector<string> split(const string &original, const string &delimiter, int maxSplits) {
	
	vector<string> result;
	int splits = 0;
	size_t offset = 0;

	while (true)
	{
		if (splits == maxSplits)
		{
			break;
		}
		size_t pos = original.find(delimiter, offset);
		if (pos == string::npos)
		{
			break;
		}
		result.push_back(original.substr(offset, pos - offset));
		offset = pos + delimiter.length();
	}
	result.push_back(original.substr(offset));
	return result;
}