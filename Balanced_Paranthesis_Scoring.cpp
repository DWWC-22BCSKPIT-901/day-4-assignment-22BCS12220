//balanced paranthesis scoring
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int scoreOfParentheses(string s) {
    stack<int> st;
    st.push(0); // Initialize stack with a base score of 0

    for (char c : s) {
        if (c == '(') {
            st.push(0); // Push a new frame for an inner score
        } else {
            int innerScore = st.top();
            st.pop();
            int outerScore = st.top();
            st.pop();
            int currentScore = outerScore + max(2 * innerScore, 1);
            st.push(currentScore); // Update the score in the stack
        }
    }

    return st.top();
}

int main() {
    // Example 1
    string s1 = "()";
    cout << "Score of \"()\": " << scoreOfParentheses(s1) << endl;

    // Example 2
    string s2 = "(())";
    cout << "Score of \"(())\": " << scoreOfParentheses(s2) << endl;

    // Example 3
    string s3 = "()()";
    cout << "Score of \"()()\": " << scoreOfParentheses(s3) << endl;

    return 0;
}