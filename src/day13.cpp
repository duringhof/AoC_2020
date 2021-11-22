#include "aoc_generic.hpp"

using namespace std;

pair<int, vector<int>> readBusNote(vector<string> lines) {
    int time = stoi(lines[0]);
    vector<int> buses;
    vector<string> busStrings = split(lines[1], ',', 99999);
    for (string bus : busStrings) {
        if(bus != "x") {
            buses.push_back(stoi(bus));
        }
    }
    return make_pair(time, buses);
}

int busdelay(int bus, int time) {
    return bus - (time % bus);
}

int main() {

    pair<int, vector<int>> busNote = readBusNote(readLines("../input/day13.txt"));

    int time = busNote.first;
    vector<int> buses = busNote.second;

    int bestBus = buses[0];
    for (int bus : buses) {
        if (busdelay(bus, time) < busdelay(bestBus, time)) {
            bestBus = bus;
        }
    }

    cout << "Part 1 - The earliest bus you can take is: "
         << bestBus << ", multiplied by its delay this gives: " << bestBus*busdelay(bestBus, time)
         << endl;

    return 0;
}