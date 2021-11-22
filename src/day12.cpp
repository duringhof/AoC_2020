#include "aoc_generic.hpp"

using namespace std;

struct Instruction {
    char direction;
    int distance;
};

struct Position {
    int x;
    int y;
    char direction;
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

void executeInstruction(Instruction instruction, Position& position) {
    if (instruction.direction == 'N') {
        position.y += instruction.distance;
    } else if (instruction.direction == 'S') {
        position.y -= instruction.distance;
    } else if (instruction.direction == 'E') {
        position.x += instruction.distance;
    } else if (instruction.direction == 'W') {
        position.x -= instruction.distance;
    } else if (instruction.direction == 'L') {
        for (int i = 0; i < instruction.distance/90; i++) {
            if (position.direction == 'N') {
                position.direction = 'W';
            } else if (position.direction == 'W') {
                position.direction = 'S';
            } else if (position.direction == 'S') {
                position.direction = 'E';
            } else if (position.direction == 'E') {
                position.direction = 'N';
            }
        }
    } else if (instruction.direction == 'R') {
        for (int i = 0; i < instruction.distance/90; i++) {
            if (position.direction == 'N') {
                position.direction = 'E';
            } else if (position.direction == 'E') {
                position.direction = 'S';
            } else if (position.direction == 'S') {
                position.direction = 'W';
            } else if (position.direction == 'W') {
                position.direction = 'N';
            }
        }
    } else if (instruction.direction == 'F') {
        if (position.direction == 'N') {
            position.y += instruction.distance;
        } else if (position.direction == 'S') {
            position.y -= instruction.distance;
        } else if (position.direction == 'E') {
            position.x += instruction.distance;
        } else if (position.direction == 'W') {
            position.x -= instruction.distance;
        }
    }
}

int main() {

    vector<Instruction> instructions = readInstructions(readLines("../input/day12.txt"));

    Position ship = {0, 0, 'E'};

    for (auto instruction : instructions) {
        executeInstruction(instruction, ship);
    }

    cout << "Part 1 - The Manhattan Distance between new and original location: "
         << abs(ship.x) + abs(ship.y) << endl;

    return 0;
}