#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int poisonousPlants(vector<int>& p) {
    int n = p.size();
    vector<int> days(n, 0); // Tracks the days each plant takes to die
    stack<int> s; // Monotonic stack for indices
    int maxDays = 0;

    for (int i = 0; i < n; i++) {
        while (!s.empty() && p[s.top()] >= p[i]) {
            s.pop();
        }
        if (!s.empty()) {
            days[i] = days[s.top()] + 1;
        }
        s.push(i);
        maxDays = max(maxDays, days[i]);
    }
    return maxDays;
}
int main() {
    // Example 1
    vector<int> p1 = {3, 6, 2, 7, 5};
    cout << "Days until no plants die for example 1: " << poisonousPlants(p1) << endl;
    // Example 2
    vector<int> p2 = {6, 5, 8, 4, 7, 10, 9};
    cout << "Days until no plants die for example 2: " << poisonousPlants(p2) << endl;
    return 0;
}
