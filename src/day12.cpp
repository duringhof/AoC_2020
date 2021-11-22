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

void executeInstruction(Instruction instruction, int& x, int& y, char& facing) {
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
            if (facing == 'N') {
                facing = 'W';
            } else if (facing == 'W') {
                facing = 'S';
            } else if (facing == 'S') {
                facing = 'E';
            } else if (facing == 'E') {
                facing = 'N';
            }
        }
    } else if (instruction.direction == 'R') {
        for (int i = 0; i < instruction.distance/90; i++) {
            if (facing == 'N') {
                facing = 'E';
            } else if (facing == 'E') {
                facing = 'S';
            } else if (facing == 'S') {
                facing = 'W';
            } else if (facing == 'W') {
                facing = 'N';
            }
        }
    } else if (instruction.direction == 'F') {
        if (facing == 'N') {
            y += instruction.distance;
        } else if (facing == 'S') {
            y -= instruction.distance;
        } else if (facing == 'E') {
            x += instruction.distance;
        } else if (facing == 'W') {
            x -= instruction.distance;
        }
    }
}

int main() {

    vector<Instruction> instructions = readInstructions(readLines("../input/day12.txt"));

    char facing = 'E';
    int x = 0;
    int y = 0;

    for (auto instruction : instructions) {
        executeInstruction(instruction, x, y, facing);
    }

    cout << "Part 1 - The Manhattan Distance between new and original location: "
         << abs(x) + abs(y) << endl;

    return 0;
}