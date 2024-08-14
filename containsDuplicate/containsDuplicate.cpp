#include <vector>
#include <algorithm>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
    // O(nlogn) time due to sorting, O(1) space
    bool containsDuplicateNaive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                return true;
            }
        }
        return false;
    }

    // O(n) time, O(n) space
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            if (s.find(nums[i]) != s.end()) { // find returns end() if not found, so find != end() means found
                return true;
            }
            s.insert(nums[i]);
        }
        return false;
    }
};

int main() {
    Solution solution;

    // Modify this array for each test
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 7};  // Test with no duplicates

    // Test the naive solution
    cout << "Naive Solution - Contains Duplicate: " << (solution.containsDuplicateNaive(nums) ? "Yes" : "No") << endl;

    // Test the optimized solution with unordered_set
    cout << "Optimized Solution - Contains Duplicate: " << (solution.containsDuplicate(nums) ? "Yes" : "No") << endl;

    return 0;
}
