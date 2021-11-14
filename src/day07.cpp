#include "aoc_generic.hpp"

using namespace std;

class Bag {
public:
    string brightness;
    string color;
    vector<Bag> children;

    Bag(string brightness, string color) : brightness(brightness),color(color) {}

    void addChild(Bag child) {
        children.push_back(child);
    }

};

bool bagExists(vector<Bag> bags, string brightness, string color) {
    for (auto bag : bags) {
        if (bag.color == color && bag.brightness == brightness) {
            return true;
        }
    }
    return false;
}

vector<Bag> readBags(vector<string> lines) {
    vector<Bag> bags;
    for(auto line : lines) {
        vector<string> words = split(line, ' ');
        switch(words.size()) {
            case 7:
                bags.push_back(Bag(words[0], words[1]));
                break;
            case 8:
                bags.push_back(Bag(words[0], words[1]));
                bags[bags.size()-1].addChild(Bag(words[5], words[6]));
                break;
            case 12:
                bags.push_back(Bag(words[0], words[1]));
                bags[bags.size()-1].addChild(Bag(words[5], words[6]));
                bags[bags.size()-1].addChild(Bag(words[9], words[10]));
                break;
            case 16:
                bags.push_back(Bag(words[0], words[1]));
                bags[bags.size()-1].addChild(Bag(words[5], words[6]));
                bags[bags.size()-1].addChild(Bag(words[9], words[10]));
                bags[bags.size()-1].addChild(Bag(words[13], words[14]));
                break;
            case 20:
                bags.push_back(Bag(words[0], words[1]));
                bags[bags.size()-1].addChild(Bag(words[5], words[6]));
                bags[bags.size()-1].addChild(Bag(words[9], words[10]));
                bags[bags.size()-1].addChild(Bag(words[13], words[14]));
                bags[bags.size()-1].addChild(Bag(words[17], words[18]));
                break;
        }
    }
    return bags;
}

vector<Bag> findParents(vector<Bag> bags, string brightness, string color) {
    vector<Bag> parents;
    for (auto bag : bags) {
        for (auto child : bag.children) {
            if (child.color == color && child.brightness == brightness) {
                parents.push_back(bag);
            }
        }
    }
    return parents;
}


int main() {

    vector<string> lines = readLines("../input/day07.txt");
    vector<Bag> bags = readBags(lines);

    vector<Bag> parents = findParents(bags, "shiny", "gold");
    int parentIndex = 0;
    while(parentIndex < parents.size()) {;
        vector<Bag> newparents = findParents(bags, parents[parentIndex].brightness, parents[parentIndex].color);
        for(auto newparent : newparents) {
            if(!bagExists(parents, newparent.brightness, newparent.color)) {
                parents.push_back(newparent);
            }
        }
        parentIndex++;
    }

    cout << "The number of bags that can contain at least one shiny gold bag is: " << parents.size() << endl;
    return 0;
}