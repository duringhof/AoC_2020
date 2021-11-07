#include "aoc_generic.hpp"

using namespace std;

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
	cout << "Number of valid A passwords is: "
         << count_if(lines.begin(), lines.end(), validPasswordA)
         << endl;
	cout << "Number of valid B passwords is: "
         << count_if(lines.begin(), lines.end(), validPasswordB)
         << endl;
    return 0;
}