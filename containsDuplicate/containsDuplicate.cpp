#include <vector>
#include <algorithm>
#include <unordered_set>

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
