#include <stack>

// if popped even once st1 is empty, and everything is in st2,
// if popped but pushed after then,
// the pushed element is in the back of the queue
// we dont use back of the queue until pop or peek needed

class MyQueue {
public:
    MyQueue() {

    }

    void push(int x) {
        st1.push(x);
    }

    int pop() {
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        int result = st2.top();
        st2.pop();
        return result;
    }

    int peek() {
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        return st2.top();
    }

    bool empty() {
        return st1.empty() && st2.empty();
    }

private:
    std::stack<int> st1;
    std::stack<int> st2;
};
