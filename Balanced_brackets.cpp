//Balanced brackets (easy)
#include <iostream>
#include <stack>
#include <string>
using namespace std;

string isBalanced(string s) {
    stack<char> st;

    for (char ch : s) {
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } else {
            if (st.empty()) {
                return "NO";
            }
            char top = st.top();
            if ((ch == ')' && top == '(') ||
                (ch == '}' && top == '{') ||
                (ch == ']' && top == '[')) {
                st.pop(); 
            } else {
                return "NO";
            }
        }}
    return st.empty() ? "YES" : "NO";
}
int main() {
    int n;
    cin >> n;
    cin.ignore(); 
    while (n--) {
        string s;
        getline(cin, s);
        cout << isBalanced(s) << endl;
    }
    return 0;}
