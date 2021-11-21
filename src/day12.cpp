#include "aoc_generic.hpp"

using namespace std;

struct Instruction {
    char direction;
    int distance;
};

vector<Instruction> readInstructions(vector<string> lines) {
    vector<Instruction> instructions;
    for (auto line : lines) {
        stringstream ss(line);
        Instruction instruction;
        ss >> instruction.direction >> instruction.distance;
        instructions.push_back(instruction);
    }
    return instructions;
}

int main() {

    vector<Instruction> instructions = readInstructions(readLines("../input/day12.txt"));

    char currentDirection = 'E';
    int x = 0;
    int y = 0;

    for (auto instruction : instructions) {
        if (instruction.direction == 'N') {
            y += instruction.distance;
        } else if (instruction.direction == 'S') {
            y -= instruction.distance;
        } else if (instruction.direction == 'E') {
            x += instruction.distance;
        } else if (instruction.direction == 'W') {
            x -= instruction.distance;
        } else if (instruction.direction == 'L') {
            for (int i = 0; i < instruction.distance/90; i++) {
                if (currentDirection == 'N') {
                    currentDirection = 'W';
                } else if (currentDirection == 'W') {
                    currentDirection = 'S';
                } else if (currentDirection == 'S') {
                    currentDirection = 'E';
                } else if (currentDirection == 'E') {
                    currentDirection = 'N';
                }
            }
        } else if (instruction.direction == 'R') {
            for (int i = 0; i < instruction.distance/90; i++) {
                if (currentDirection == 'N') {
                    currentDirection = 'E';
                } else if (currentDirection == 'E') {
                    currentDirection = 'S';
                } else if (currentDirection == 'S') {
                    currentDirection = 'W';
                } else if (currentDirection == 'W') {
                    currentDirection = 'N';
                }
            }
        } else if (instruction.direction == 'F') {
            if (currentDirection == 'N') {
                y += instruction.distance;
            } else if (currentDirection == 'S') {
                y -= instruction.distance;
            } else if (currentDirection == 'E') {
                x += instruction.distance;
            } else if (currentDirection == 'W') {
                x -= instruction.distance;
            }
        }
    }

    cout << "Part 1 - The Manhattan Distance between new and original location: "
         << abs(x) + abs(y) << endl;

    return 0;
}