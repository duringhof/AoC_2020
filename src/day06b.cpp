#include "aoc_generic.hpp"

using namespace std;

int main() {

    vector<string> lines = readLines("../input/day06.txt");

    vector<char> cdf, cdftmp;
    int count = 0;
    bool cdfchecked = false;
    for(string line : lines) {
        if(line.empty()) {
            cdf.erase(unique(cdf.begin(),cdf.end()),cdf.end());
            count = count + cdf.size();
            cdf.clear();
            cdfchecked = false;
            continue;
        }
        if(cdf.empty() && cdfchecked == false) {
            for(char c : line) {
                cdf.push_back(c);
            }
        } else {
            cdftmp = cdf;
            for(char c : cdftmp) {
                if(find(line.begin(),line.end(),c) == line.end()) {
                    cdf.erase(remove(cdf.begin(),cdf.end(),c),cdf.end());
                }
            }
            if(cdf.empty()) {
                cdfchecked = true;
            }
        }
    }
    cdf.erase(unique(cdf.begin(),cdf.end()),cdf.end());
    count = count + cdf.size();

    cout << "The sum of counts is: " << count << endl;
    return 0;
}