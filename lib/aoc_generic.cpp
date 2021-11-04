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