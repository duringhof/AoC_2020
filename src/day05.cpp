
#include "aoc_generic.hpp"

using namespace std;

pair<int, int> splitRange(pair<int, int> range, char direction) {
    int low = range.first;
    int high = range.second;
    int mid = (low + high) / 2;
    if (direction == 'F' || direction == 'L') {
        return make_pair(low, mid);
    } else {
        return make_pair(mid+1, high);
    }
}

int calcId(string input) {

    pair<int, int> row = make_pair(0, 127);
    pair<int, int> column = make_pair(0, 7);
    
    for (auto letter : input) {
        if (letter == 'F' || letter == 'B') {
            row = splitRange(row, letter);
        } else {
            column = splitRange(column, letter);
        }
    }
    return row.first * 8 + column.first;
}

int main() {

    vector<string> boardingpasses = readLines("../input/day05.txt");
    
    int highestId = 0;

    for(auto boardingpass : boardingpasses) {
        if (calcId(boardingpass) > highestId) {
            highestId = calcId(boardingpass);
        }
    }

    cout << "The highest boarding pass Id is:  " << highestId << endl;
    return 0;
}