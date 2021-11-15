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

pair<int,bool> runProgram(vector<Instruction> instructions) {
    vector<bool> hasRun(instructions.size(), false);
    int accumulator = 0;
    int j = 0;
    for (int i = 0; i < instructions.size(); i++) {
        j = i;
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
    bool earlyExit = j < instructions.size()-1;
    return make_pair(accumulator, earlyExit);
}

int main() {

    vector<string> lines = readLines("../input/day08.txt");
    vector<Instruction> instructions = readInstructions(lines);   
    
    pair<int,bool> result = runProgram(instructions);
    cout << "Part 1 - The value in the accumulator before entering the loop is: " << result.first << endl;
    
    int j = -1;
    while (result.second) {
        vector<Instruction> newinstructions = instructions;
        j++;
        if (newinstructions[j].op == jmp) {
            newinstructions[j].op = nop;
            result = runProgram(newinstructions);
        } else if (newinstructions[j].op == nop) {
            newinstructions[j].op = jmp;
            result = runProgram(newinstructions);
        }   
    }
    cout << "Part 2 - The value in the accumulator after correct program termination: " << result.first << endl;

    return 0;
}