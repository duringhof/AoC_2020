
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

bool validValue(string value, string field) {
    bool valid = true;
    if (field == "byr") {
        if (value.size() != 4) {
            valid = false;
        } else {
            int year = stoi(value);
            if (year < 1920 || year > 2002) {
                valid = false;
            }
        }
    } else if (field == "iyr") {
        if (value.size() != 4) {
            valid = false;
        } else {
            int year = stoi(value);
            if (year < 2010 || year > 2020) {
                valid = false;
            }
        }
    } else if (field == "eyr") {
        if (value.size() != 4) {
            valid = false;
        } else {
            int year = stoi(value);
            if (year < 2020 || year > 2030) {
                valid = false;
            }
        }
    } else if (field == "hgt") {
        if (value.size() < 3) {
            valid = false;
        } else {
            int height = stoi(value.substr(0, value.size() - 2));
            string unit = value.substr(value.size() - 2);
            if (unit == "cm") {
                if (height < 150 || height > 193) {
                    valid = false;
                }
            } else if (unit == "in") {
                if (height < 59 || height > 76) {
                    valid = false;
                }
            } else {
                valid = false;
            }
        }
    } else if (field == "hcl") {
        if (value.size() != 7) {
            valid = false;
        } else {
            if (value[0] != '#') {
                valid = false;
            }
            for (int i = 1; i < value.size(); i++) {
                if (!isxdigit(value[i])) {
                    valid = false;
                }
            }
        }
    } else if (field == "ecl") {
        if (value != "amb" && value != "blu" && value != "brn" && value != "gry" && value != "grn" && value != "hzl" && value != "oth") {
            valid = false;
        }
    } else if (field == "pid") {
        if (value.size() != 9) {
            valid = false;
        } else {
            for (int i = 0; i < value.size(); i++) {
                if (!isdigit(value[i])) {
                    valid = false;
                }
            }
        }
    }
    return valid;
}

bool validPassportB(const vector<pair<string, string>>& passport) {
    bool valid = true;
    int nrOfFields = 0;
    vector<string> mustHaveFields = {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"};
    
    for (auto field : mustHaveFields) {
        for (auto entry : passport) {
            if (entry.first == field && validValue(entry.second, field)) {
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
    int countValidPassportsB = 0;
    for (auto passport : passports) {
        if (validPassportB(passport)) {
            countValidPassportsB++;
        }
    }

    cout << "The number of valid passports on file is: " << countValidPassports << endl;
    cout << "Following revised validity rules, the number is: " << countValidPassportsB << endl;
    return 0;
}