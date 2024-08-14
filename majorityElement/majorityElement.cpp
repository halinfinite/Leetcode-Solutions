#include <unordered_map>
#include <utility>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    // O(n) time complexity for both naive and Boyer-Moore Majority Vote Algorithm
    // O(n) space complexity for naive, O(1) space complexity for Boyer-Moore Majority Vote Algorithm
    int majorityElementNaive(vector<int>& nums) {
        unordered_map<int, int> hash;

        for (int elem : nums) {
            hash[elem]++;
        }

        int count = 0;
        int majority = nums[0];
        for (const pair<const int, int>& pair : hash) {
            if (pair.second > count) {
                count = pair.second;
                majority = pair.first;
            }
        }
        return majority;
    }

    int majorityElement(vector<int>& nums) {
        // Boyer-Moore Majority Vote Algorithm
        // Key Idea: We are pairing up different elements, since we are looking for say %50 + 1
        // This algorithm assumes that there is a majority element in the array
        // If we don't have this assumption, we need to do a second pass to find how many appearances of the candidate there is.
        // After the second pass, we can check if the candidate is the majority element or not.
        int count = 0;
        int majority = nums[0];

        for (int elem : nums) {
            if (count == 0) {
                majority = elem;
            }
            count += (elem == majority) ? 1 : -1;
        }
        return majority;
    }
};

int main() {
    Solution solution;

    // Modify this array for each test
    vector<int> nums = {3, 3, 4, 2, 4, 4, 2, 4, 4};

    // Test the naive solution
    cout << "Naive Solution - Majority Element: " << solution.majorityElementNaive(nums) << endl;

    // Test the Boyer-Moore solution
    cout << "Boyer-Moore Solution - Majority Element: " << solution.majorityElement(nums) << endl;

    return 0;
}
