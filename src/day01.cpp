#include "aoc_generic.hpp"

using namespace std;

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

vector<int> threeSum(vector<int>& nums, int target) {
    // Returns the product of the first found combination of three numbers whos sum is equal to target
    int len = nums.size();
    for(int i = 0; i < len; i++) {
        for(int j = i + 1; j < len; j++) {
            for(int k = j + 1; k < len; k++) {
                if(nums[k] == target - nums[i] - nums[j])
                    return { i, j, k };
            }
        }
    } 
    return {-1, -1, -1};
};

int main() {

    vector<int> expenseReport = readInput("../input/day01.txt");
    vector<int> answer1 = twoSum(expenseReport, 2020);
	cout << "Part 1: "
         << expenseReport[answer1[0]] << " x "
         << expenseReport[answer1[1]] << " = "
         << expenseReport[answer1[0]]*expenseReport[answer1[1]]
         << endl;
    vector<int> answer2 = threeSum(expenseReport, 2020);
	cout << "Part 2: "
         << expenseReport[answer2[0]] << " x "
         << expenseReport[answer2[1]] << " x "
         << expenseReport[answer2[2]] << " = "
         << expenseReport[answer2[0]]*expenseReport[answer2[1]]*expenseReport[answer2[2]]
         << endl;
    return 0;
}