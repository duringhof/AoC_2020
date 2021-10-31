#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<int> readInput(string file){
    // Reads input file and return a vector<int> called input
	vector<int> input;
	ifstream inputFile(file);
	int number;
	while (inputFile >> number){
		input.push_back(number);
	}
	inputFile.close();
	return input;
}

vector<int> twoSum(vector<int>& nums, int target) {
    // Returns the product of the first found pair of numbers whos sum is equal to target
    int len = nums.size();
    for(int i = 0; i < len; i++) {
        for(int j = i + 1; j < len; j++) {
            if(nums[j] == target - nums[i])
                return { i, j };
        }
    }
    return {-1, -1};
};

int main() {

    vector<int> expenseReport = readInput("../input/day1.txt");
    vector<int> answer = twoSum(expenseReport, 2020);
	cout << "Part 1: " << expenseReport[answer[0]] << " x " << expenseReport[answer[1]] << " = " << expenseReport[answer[0]]*expenseReport[answer[1]] << endl;
    return 0;
}