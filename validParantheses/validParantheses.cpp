#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (const char ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }
            else {
                if (st.empty()) {
                    return false; // If stack is empty and a closing bracket is found, it's invalid
                }
                if ((ch == ')' && st.top() == '(') ||
                    (ch == '}' && st.top() == '{') ||
                    (ch == ']' && st.top() == '[')) {
                    st.pop();
                } else {
                    return false; // Mismatch found
                }
            }
        }
        return st.empty(); // Check if stack is empty at the end
    }
};
