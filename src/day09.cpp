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

long int sumOfElements(vector<long int> nums) {
    long int sum = 0;
    for(int i = 0; i < nums.size(); i++) {
        sum += nums[i];
    }
    return sum;
};

int main() {

    vector<long int> numbers = readInputLong("../input/day09.txt");

    long int answer_part_1 = 0;

    for(int i = 25; i < numbers.size(); i++) {
        vector<long int> preamble = createPreamble(numbers, i);
        vector<int> indices = twoSum(preamble, numbers[i]);
        if(indices[0] == -1 && indices[1] == -1) {
            cout << "Part 1: At index " << i << ", the number " << numbers[i] << " does not have the XMAS property" << endl;
            answer_part_1 = numbers[i];
            break;
        }
    }

    int startposition = 0;
    vector<long int> contiguousList = { numbers[0] };
    while (sumOfElements(contiguousList) != answer_part_1) {
        if (sumOfElements(contiguousList) > answer_part_1) {
            contiguousList.erase(contiguousList.begin());
            startposition++;
        } else {
            contiguousList.push_back(numbers[contiguousList.size()+startposition]);
        }
    }
    
    long int smallest = contiguousList[0];
    long int largest = contiguousList[0];

    for(int i = 0; i < contiguousList.size(); i++) {
        if (contiguousList[i] < smallest) {
            smallest = contiguousList[i];
        }
        if (contiguousList[i] > largest) {
            largest = contiguousList[i];
        }
    }

    cout << "Part 2: The encryption weakness is " << smallest+largest << endl;

    return 0;
}