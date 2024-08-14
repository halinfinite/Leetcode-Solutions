#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n-1;
        vector<int> squares(n);
        int sq_index = n-1;

        while (left <= right) {
            int sq_left = nums[left] * nums[left];
            int sq_right = nums[right] * nums[right];

            if (sq_left > sq_right) {
                squares[sq_index] = sq_left;
                left++;
            } else {
                squares[sq_index] = sq_right;
                right--;
            }
            sq_index--;
        }
        return squares;
    }
};

int main() {
    Solution solution;
    vector<int> sorted_integers{-5, -2, -1, 0, 4, 5, 6, 7};
    vector<int> result = solution.sortedSquares(sorted_integers);
    for (int elem : result) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
