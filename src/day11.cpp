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

int countVisOccSeats(vector<vector<seat>>& seatmap, int x, int y) {
    int count = 0;
    int dist = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            dist = 1;
            while (x+i*dist >= 0 && x+i*dist < seatmap.size() &&
                   y+j*dist >= 0 && y+j*dist < seatmap[0].size()) {
                        if (seatmap[x + i*dist][y + j*dist].occupied) {
                            count++;
                            break;
                        };
                        if (seatmap[x + i*dist][y + j*dist].floor) {
                            dist++;
                        } else {
                            break;
                        }
            }
        }
    }
    return count;
}

vector<vector<seat>> swapSeatsB(vector<vector<seat>> oldseatmap) {
    vector<vector<seat>> newseatmap = oldseatmap;
    for (int i = 0; i < oldseatmap.size(); i++) {
        for (int j = 0; j < oldseatmap[0].size(); j++) {
            if (oldseatmap[i][j].floor) {
                continue;
            }
            if (!oldseatmap[i][j].occupied && countVisOccSeats(oldseatmap, i, j) == 0) {
                newseatmap[i][j].occupied = true;
            }
            if (oldseatmap[i][j].occupied && countVisOccSeats(oldseatmap, i, j) >= 5) {
                newseatmap[i][j].occupied = false;
            }
        }
    }
    return newseatmap;
}

int main() {

    vector<vector<seat>> seatmap = readSeatMap("../input/day11.txt");
    vector<vector<seat>> seatmapB = seatmap;

    while (countOccupiedSeats(swapSeats(seatmap)) != countOccupiedSeats(seatmap)) {
        seatmap = swapSeats(seatmap);
    }

    cout << "Part 1 - The number of occupied seats after stabilization is: " << countOccupiedSeats(seatmap) << endl;

    while (countOccupiedSeats(swapSeatsB(seatmapB)) != countOccupiedSeats(seatmapB)) {
        seatmapB = swapSeatsB(seatmapB);
    }

    cout << "Part 2 - The number of occupied seats after stabilization is: " << countOccupiedSeats(seatmapB) << endl;

    return 0;
}