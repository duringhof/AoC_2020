
#include "aoc_generic.hpp"

using namespace std;

bool validPassport(const vector<pair<string, string>>& passport) {
    bool valid = true;
    int nrOfFields = 0;
    vector<string> mustHaveFields = {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"};
    for (auto field : mustHaveFields) {
        for (auto entry : passport) {
            if (entry.first == field) {
                nrOfFields++;
            }
        }
    }
    if (nrOfFields != mustHaveFields.size()) {
        valid = false;
    }
    return valid;
}

int main() {

    vector<string> lines = readLines("../input/day04.txt");
    
    vector<vector<pair<string,string>>> passports;
    vector<pair<string,string>> passport;
    for(string line : lines) {
        if(line.empty()) {
            passports.push_back(passport);
            passport.clear();
            continue;
        }
        
        vector<string> buffer = split(line," ",8);
        for(int j = 0; j < buffer.size(); j++) {
            vector<string> buffer2 = split(buffer[j],":",2);
            passport.push_back(make_pair(buffer2[0],buffer2[1]));
        }
    }
    passports.push_back(passport);
    int countValidPassports = 0;
    for (auto passport : passports) {
        if (validPassport(passport)) {
            countValidPassports++;
        }
    }

    cout << "The number of valid passports on file is: " << countValidPassports << endl;
    return 0;
}