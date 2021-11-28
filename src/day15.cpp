#include "aoc_generic.hpp"

using namespace std;
struct Number {
    int value;
    int age;
};

vector<Number> createGame(vector<int> startSet) {
    vector<Number> game;
    for (int i = 0; i < startSet.size(); i++) {
        int age = startSet.size()-i;
        Number number = {startSet[i], age};
        game.push_back(number);
    }
    return game;
}

int sayNumber(vector<Number> &game, int previous) {
    int result = 0;
    for (auto &number : game) {
        if (number.value == previous) {
            result = number.age;
            number.age = 0;
        }
        number.age += 1;
    }
    if (result == 0) {
        Number newNumber = {previous, 1};
        game.push_back(newNumber);
    }
    return result;
}

int main() {
    vector<int> input = {11, 0, 1, 10, 5, 19};
    vector<Number> game = createGame(input);

    int turns = input.size()+1;
    int previous = 0;

    for (int i = turns+1; i < 2021; i++) {
        previous = sayNumber(game, previous);
    }
    
    cout << "Part 1 - In turn 2020, the number " << previous << " was spoken." << endl
         << "Part 2 - Not done yet... " << endl;

    return 0;
}