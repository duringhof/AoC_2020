#include "aoc_generic.hpp"

using namespace std;

vector<int> twoSum(vector<long int>& nums, long int target) {
    // Returns the indices of the first found pair of numbers whos sum is equal to target
    int len = nums.size();
    for(int i = 0; i < len; i++) {
        for(int j = i + 1; j < len; j++) {
            if(nums[j] == target - nums[i])
                return { i, j };
        }
    }
    return {-1, -1};
};

vector<long int> createPreamble(vector<long int> nums, long int target) {
    vector<long int> preamble;
    for(int i = target-25; i < target; i++) {
        preamble.push_back(nums[i]);
    }
    return preamble;
};

int main() {

    vector<long int> numbers = readInputLong("../input/day09.txt");

    for(int i = 25; i < numbers.size(); i++) {
        vector<long int> preamble = createPreamble(numbers, i);
        vector<int> indices = twoSum(preamble, numbers[i]);
        if(indices[0] == -1 && indices[1] == -1) {
            cout << "Part 1: At index " << i << ", the number " << numbers[i] << " does not have the XMAS property" << endl;;
            break;
        }
    }
    
    cout << "Day 9 is not done yet, only debugging output for now: " << numbers[999] << endl;

    return 0;
}