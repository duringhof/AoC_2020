#include "aoc_generic.hpp"

using namespace std;

struct Memory {
    int address;
    long value;
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

string toBinary(long int n, int length) {
    string r;
    while(n!=0) {
        r = (n%2 == 0 ? "0" : "1") + r;
        n /= 2;
    }
    while(r.length() < length) {
        r = "0" + r;
    }
    return r;
}

long applyMask(long n, string mask) {
    string binary = toBinary(n, mask.length());
    long result = 0;
    for (int i = 0; i < binary.length(); i++) {
        if (mask[mask.length()-i-1] != 'X') {
            binary[mask.length()-i-1] = mask[mask.length()-i-1];
        }
        result += binary[mask.length()-i-1] == '1' ? pow(2,i) : 0;
    }
    return result;
}

long sumValuesInMemory(vector<Memory> memory) {
    long sum = 0;
    for (auto m : memory) {
        sum += m.value;
    }
    return sum;
}

int main() {

    vector<string> lines = readLines("../input/day14.txt");
    vector<Instruction> instructions = parseInstructions(lines);
    vector<Memory> memory = {};

    for (auto instruction : instructions) {
        for (auto operation : instruction.operations) {
            bool done = false;
            for (Memory& mem : memory) {
                if (mem.address == operation.address) {
                    mem.value = applyMask(operation.value, instruction.mask);
                    //cout << "Overwritten " << mem.address << " with " << mem.value << endl;
                    done = true;
                }
            }
            if (!done) {
                memory.push_back({operation.address, applyMask(operation.value, instruction.mask)});
                //cout << "Added " << memory.back().address << " with value " << memory.back().value << endl;
            }
        }
    }
    
    cout << "Part 1 - The sum of all values in memory is: "
         << sumValuesInMemory(memory) << endl
         << "Part 2 - Not done yet... " << endl;

    return 0;
}