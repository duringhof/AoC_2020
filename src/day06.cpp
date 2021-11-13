#include "aoc_generic.hpp"

using namespace std;

int main() {

    vector<string> lines = readLines("../input/day06.txt");

    vector<vector<char>> cdfs;    
    vector<char> cdf;
    int count = 0;
    for(string line : lines) {
        if(line.empty()) {
            sort(cdf.begin(),cdf.end());
            cdf.erase(unique(cdf.begin(),cdf.end()),cdf.end());
            count = count + cdf.size();
            cdfs.push_back(cdf);
            cdf.clear();
            continue;
        }
        for(char c : line) {
            cdf.push_back(c);
        }
    }
    sort(cdf.begin(),cdf.end());
    cdf.erase(unique(cdf.begin(),cdf.end()),cdf.end());
    count = count + cdf.size();
    cdfs.push_back(cdf);

    cout << "The sum of counts is: " << count << endl;
    return 0;
}