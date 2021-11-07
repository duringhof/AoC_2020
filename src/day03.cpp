
#include "aoc_generic.hpp"

using namespace std;

bool checkMaze(vector<vector<bool>> maze, int x, int y) {
    if (x < 0 || y < 0 || y >= maze.size()) {
        return false;
    }
    x = x%maze[y].size();
    return maze[y][x];
}

int main() {

    vector<vector<bool>> forest = readMaze("../input/day03.txt");
    int counttrees = 0;
    int x = 0, y = 0;
    while(y<forest.size()) {
        if (checkMaze(forest, x, y)) {
            counttrees++;
        }
        x+=3;
        y++;
    }
	cout << "The number of trees encountered is: " << counttrees << endl;
    return 0;
}