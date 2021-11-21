#include "aoc_generic.hpp"

using namespace std;

struct seat {
    bool occupied;
    bool floor;
};

vector<vector<seat>> readSeatMap(string file) {
	vector<vector<seat>> seatmap;
	ifstream inputFile(file);
	string line;
	while (getline(inputFile, line)){
		vector<seat> row;
		for (char c : line) {
			if (c == '#') {
				row.push_back({true, false});
			} else if (c == 'L') {
                row.push_back({false, false});
			} else if (c == '.') {
                row.push_back({false, true});
            }
		}
		seatmap.push_back(row);
	}
	inputFile.close();
	return seatmap;
}

int countAdjOccSeats(vector<vector<seat>>& seatmap, int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            if (x+i < 0 || x+i >= seatmap.size()) {
                continue;
            }
            if (y+j < 0 || y+j >= seatmap[0].size()) {
                continue;
            }
            if (seatmap[x + i][y + j].occupied) {
                count++;
            }
        }
    }
    return count;
}

vector<vector<seat>> swapSeats(vector<vector<seat>> oldseatmap) {
    vector<vector<seat>> newseatmap = oldseatmap;
    for (int i = 0; i < oldseatmap.size(); i++) {
        for (int j = 0; j < oldseatmap[0].size(); j++) {
            if (oldseatmap[i][j].floor) {
                continue;
            }
            if (!oldseatmap[i][j].occupied && countAdjOccSeats(oldseatmap, i, j) == 0) {
                newseatmap[i][j].occupied = true;
            }
            if (oldseatmap[i][j].occupied && countAdjOccSeats(oldseatmap, i, j) >= 4) {
                newseatmap[i][j].occupied = false;
            }
        }
    }
    return newseatmap;
}

int countOccupiedSeats(vector<vector<seat>> seatmap) {
    int count = 0;
    for (int i = 0; i < seatmap.size(); i++) {
        for (int j = 0; j < seatmap[0].size(); j++) {
            if (seatmap[i][j].occupied) {
                count++;
            }
        }
    }
    return count;
}

int main() {

    vector<vector<seat>> seatmap = readSeatMap("../input/day11.txt");

    while (countOccupiedSeats(swapSeats(seatmap)) != countOccupiedSeats(seatmap)) {
        seatmap = swapSeats(seatmap);
    }

    cout << "Part 1 - The number of occupied seats after stabilization is: " << countOccupiedSeats(seatmap) << endl;

    return 0;
}