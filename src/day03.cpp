
#include "aoc_generic.hpp"

using namespace std;

bool checkMaze(vector<vector<bool>> maze, int x, int y) {
    if (x < 0 || y < 0 || y >= maze.size()) {
        return false;
    }
    x = x%maze[y].size();
    return maze[y][x];
}

int countTrees(vector<vector<bool>> maze, int dx, int dy) {
    int treecounter = 0;
    int x = 0, y = 0;
    while(y<maze.size()) {
        if (checkMaze(maze, x, y)) {
            treecounter++;
        }
        x+=dx;
        y+=dy;
    }
    return treecounter;
}

int main() {

    vector<vector<bool>> forest = readMaze("../input/day03.txt");
    
	cout << "The number of trees encountered is: " << countTrees(forest, 3, 1) << endl;
    return 0;
}