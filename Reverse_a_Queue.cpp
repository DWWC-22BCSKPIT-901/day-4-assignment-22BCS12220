//Reverse a queue(medium).
#include <iostream>
#include <queue>
using namespace std;
void reverseQueue(queue<int>& q) {
    if (q.empty()) {
        return;
    }
    int front = q.front();
    q.pop();
    reverseQueue(q);
    q.push(front);
}
void printQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}
int main() {
    // Example 1
    queue<int> q1;
    int arr1[] = {5, 24, 9, 6, 8, 4, 1, 8, 3, 6};
    for (int num : arr1) {
        q1.push(num);
    }

    cout << "Original Queue: ";
    printQueue(q1);

    reverseQueue(q1);

    cout << "Reversed Queue: ";
    printQueue(q1);

    // Example 2
    queue<int> q2;
    int arr2[] = {8, 7, 2, 5, 1};
    for (int num : arr2) {
        q2.push(num);
    }

    cout << "Original Queue: ";
    printQueue(q2);

    reverseQueue(q2);

    cout << "Reversed Queue: ";
    printQueue(q2);

    return 0;
}
