#include "aoc_generic.hpp"

using namespace std;

int main() {

    vector<int> ratings = readInput("../input/day10.txt");

    sort(ratings.begin(), ratings.end());

    vector<int> diffs(ratings.size()+1, 0);

    diffs[0] = ratings[0];
    for(int i = 1; i < ratings.size(); i++) {

        diffs[i] = ratings[i] - ratings[i-1];
    }
    diffs[diffs.size()-1] = 3;
    
    int ones = 0;
    int threes = 0;

    for(int i = 0; i < diffs.size(); i++) {

        if (diffs[i] == 1) {
            ones++;
        } else if (diffs[i] == 3) {
            threes++;
        }
    }

    cout << "Part 1: The number of ones multiplied by the number of threes is:  " << ones * threes << endl;

    return 0;
}