#include "aoc_generic.hpp"

using namespace std;

struct Bus {
    int id;
    int offset;
};

pair<int, vector<int>> readBusNote(vector<string> lines) {
    int time = stoi(lines[0]);
    vector<int> buses;
    vector<string> busStrings = split(lines[1], ',', 99999);
    for (string bus : busStrings) {
        if(bus == "x") {
            buses.push_back(0);
        } else {
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
        if (bus != 0 && busdelay(bus, time) < busdelay(bestBus, time)) {
            bestBus = bus;
        }
    }

    vector<Bus> busList;
    for (int i=0; i<buses.size(); i++) {
        if (buses[i] == 0) {
            continue;
        }
        busList.push_back({buses[i],i});
    }

    long timestamp = 0;
    long t = 0;
    long dt = busList[0].id;
    int search_idx = 1;
    
    for (long t = dt; t < __LONG_MAX__; t += dt) {
        bool success = true;
        for (int i=0; i <= search_idx; i++) {
            if ((t + busList[i].offset) % busList[i].id != 0) {
                success = false;
                break;
            }
        }
        if (success && search_idx == busList.size()-1) {
            timestamp = t;
            break;
        }
        if (success) {
            dt *= busList[search_idx].id;
            search_idx++;
        }
    }

    cout << "Part 1 - The earliest bus you can take is: "
         << bestBus << ", multiplied by its delay this gives: " << bestBus*busdelay(bestBus, time)
         << endl
         << "Part 2 - The earliest timestamp that all bus IDs depart at the right offset: " << timestamp << endl;

    return 0;
}