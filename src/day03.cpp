
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
    vector<pair<int, int>> slopes = {{1,1}, {3,1}, {5,1}, {7,1}, {1,2}};
    int productOfAnswers = 1;
    for (auto slope : slopes) {
        productOfAnswers = productOfAnswers*countTrees(forest, slope.first, slope.second);
    }
	cout << "The number of trees encountered is: " << countTrees(forest, 3, 1) << endl;
    cout << "The product of the number of trees encountered in list of slopes is: " << productOfAnswers << endl;
    return 0;
}