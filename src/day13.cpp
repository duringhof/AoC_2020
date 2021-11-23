#include "aoc_generic.hpp"

using namespace std;

struct Bus {
    int id;
    int offset;
};

pair<int, vector<Bus>> readBusNote(vector<string> lines) {
    int time = stoi(lines[0]);
    vector<Bus> buses;
    vector<string> busStrings = split(lines[1], ',', 99999);
    for (int i = 0; i < busStrings.size(); i++) {
        if(busStrings[i] != "x") {
            Bus b;
            b.id = stoi(busStrings[i]);
            b.offset = i;
            buses.push_back(b);
        }
    }
    return make_pair(time, buses);
}

int busdelay(Bus bus, int time) {
    return bus.id - (time % bus.id);
}

int main() {

    pair<int, vector<Bus>> busNote = readBusNote(readLines("../input/day13.txt"));

    int time = busNote.first;
    vector<Bus> buses = busNote.second;

    Bus bestBus = buses[0];
    for (Bus bus : buses) {
        if (busdelay(bus, time) < busdelay(bestBus, time)) {
            bestBus = bus;
        }
    }

    long timestamp = 0;
    long t = 0;
    long dt = buses[0].id;
    int search_idx = 1;
    
    for (long t = dt; t < __LONG_MAX__; t += dt) {
        bool success = true;
        for (int i=0; i <= search_idx; i++) {
            if ((t + buses[i].offset) % buses[i].id != 0) {
                success = false;
                break;
            }
        }
        if (success && search_idx == buses.size()-1) {
            timestamp = t;
            break;
        }
        if (success) {
            dt *= buses[search_idx].id;
            search_idx++;
        }
    }

    cout << "Part 1 - The earliest bus you can take is: "
         << bestBus.id << ", multiplied by its delay this gives: " << bestBus.id*busdelay(bestBus, time)
         << endl
         << "Part 2 - The earliest timestamp that all bus IDs depart at the right offset: " << timestamp << endl;

    return 0;
}