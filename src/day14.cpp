#include "aoc_generic.hpp"

using namespace std;

struct Memory {
    int address;
    int value;
};

struct Instruction {
    string mask;
    vector<Memory> operations;
};

vector<Instruction> parseInstructions(vector<string> lines) {
    vector<Instruction> instructions;
    Instruction instruction;
    
    bool notfirst = false;
    for (auto line : lines) {
        vector<string> splittedline = split(line, '=');
        
        if (splittedline[0] == "mask ") {
            if (notfirst) {
                instructions.push_back(instruction);
                instruction.operations.clear();
            }
            instruction.mask = splittedline[1].substr(1);
            notfirst = true;
        } else {
            Memory memory;
            memory.address = stoi(split(splittedline[0].substr(4),']')[0]);
            memory.value = stoi(splittedline[1]);
            instruction.operations.push_back(memory);
        }
    }
    instructions.push_back(instruction);
    return instructions;
}

int main() {

    vector<string> lines = readLines("../input/day14.txt");
    vector<Instruction> instructions = parseInstructions(lines);

    for (auto instruction : instructions) {
        cout << instruction.mask << endl;
        for (auto operation : instruction.operations) {
            cout << operation.address << " " << operation.value << endl;
        }
    }
    
    cout << "Part 1 - Not done yet... "
         << instructions.size() << endl
         << "Part 2 - Not done yet... " << endl;

    return 0;
}