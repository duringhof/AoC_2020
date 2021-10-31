#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <sstream>

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

bool validPasswordA(const string& line) {
	auto rule_password = split(line, ':');
	auto range_letter = split(rule_password[0]);
	auto lower_upper = split(range_letter[0], '-');
	int lower = stoi(lower_upper[0]);
	int upper = stoi(lower_upper[1]);
	char letter = range_letter[1][0];
	string password = rule_password[1].substr(1);

	int occurrences = count(password.begin(), password.end(), letter);
	return (occurrences >= lower) && (occurrences <= upper);
}

bool validPasswordB(const string& line) {
	auto rule_password = split(line, ':');
	auto range_letter = split(rule_password[0]);
	auto posA_posB = split(range_letter[0], '-');
	int posA = stoi(posA_posB[0]);
	int posB = stoi(posA_posB[1]);
	char letter = range_letter[1][0];
	string password = rule_password[1].substr(1);

	if (password[posA - 1] == letter) {
		return password[posB - 1] != letter;
	}
	else {
		return password[posB - 1] == letter;
	}
}

int main() {

    vector<string> lines = readLines("../input/day02.txt");
	cout << "Number of valid passwords is: "
         << count_if(lines.begin(), lines.end(), validPasswordB)
         << endl;
    return 0;
}