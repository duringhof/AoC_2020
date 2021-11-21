#include "aoc_generic.hpp"

using namespace std;

int countDiffs(vector<int> ratings, int diff) {
    int count = 0;
    for (int i = 1; i < ratings.size(); i++) {
        if (ratings[i] - ratings[i-1] == diff) {
            count++;
        }
    }
    return count;
}

int mymin(int a, int b) {
    return a < b ? a : b;
}

vector<long int> pathsToEnd(vector<int> ratings) {
    vector<long int> answer(ratings.size(), 0);
    answer[ratings.size()-1] = 1;
    for (int i = ratings.size()-2; i >= 0; i--) {
        for (int j = i+1; j < mymin(i+4, ratings.size()); j++) {
            if (ratings[j] - ratings[i] <= 3) {
                answer[i] += answer[j];
            }
        }
    }
    return answer;
}

int main() {

    vector<int> ratings = readInput("../input/day10.txt");

    ratings.push_back(0);
    sort(ratings.begin(), ratings.end());
    ratings.push_back(ratings.back()+3);

    cout << "Part 1: The number of ones multiplied by the number of threes is:  "
         << countDiffs(ratings, 1) * countDiffs(ratings,3) << endl;

    int start = 0;
    cout << "Part 2: The number of possible combinations is: "
         << pathsToEnd(ratings)[0] << endl;

    return 0;
}