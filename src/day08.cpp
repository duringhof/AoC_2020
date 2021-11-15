#include "aoc_generic.hpp"

using namespace std;

enum Operation {nop, acc, jmp};

struct Instruction {
    Operation op;
    int arg;
};

vector<Instruction> readInstructions(vector<string> lines) {
    vector<Instruction> instructions;
    for (auto line : lines) {
        stringstream ss(line);
        string op;
        ss >> op;
        Instruction instruction;
        if (op == "nop") {
            instruction.op = nop;
        } else if (op == "acc") {
            instruction.op = acc;
        } else if (op == "jmp") {
            instruction.op = jmp;
        } else {
            throw runtime_error("Unknown operation");
        }
        ss >> instruction.arg;
        instructions.push_back(instruction);
    }
    return instructions;
}

int runProgram(vector<Instruction> instructions) {
    vector<bool> hasRun(instructions.size(), false);
    int accumulator = 0;
    for (int i = 0; i < instructions.size(); i++) {
        if (hasRun[i]) {
            break;
        }
        hasRun[i] = true;
        Instruction instruction = instructions[i];
        if (instruction.op == nop) {
            continue;
        } else if (instruction.op == acc) {
            accumulator += instruction.arg;
        } else if (instruction.op == jmp) {
            i += instruction.arg - 1;
            continue;
        }
    }
    return accumulator;
}

int main() {

    vector<string> lines = readLines("../input/day08.txt");
    vector<Instruction> instructions = readInstructions(lines);   
    
    cout << "Part 1 - The value in the accumulator before entering the loop is: " << runProgram(instructions) << endl;

    cout << "Day 8 is not finished" << endl;

    return 0;
}