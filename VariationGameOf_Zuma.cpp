//Variation game of zuma(hard).
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include<climits>
using namespace std;

// Function to remove consecutive groups of three or more balls
string removeConsecutive(string board) {
    int n = board.size();
    bool reduced = true;

    while (reduced) {
        reduced = false;
        int i = 0;

        while (i < n) {
            int j = i;
            while (j < n && board[j] == board[i]) {
                j++;
            }

            if (j - i >= 3) {
                board = board.substr(0, i) + board.substr(j);
                reduced = true;
                n = board.size();
                break;
            }

            i = j;
        }
    }

    return board;
}

// Helper function for DFS
int dfs(string board, unordered_map<char, int>& hand) {
    board = removeConsecutive(board);
    if (board.empty()) return 0;

    int ans = INT_MAX;
    int n = board.size();

    for (int i = 0; i < n; i++) {
        for (auto& [color, count] : hand) {
            if (count <= 0) continue;

            string newBoard = board.substr(0, i) + color + board.substr(i);
            hand[color]--;
            int temp = dfs(newBoard, hand);
            if (temp != -1) {
                ans = min(ans, temp + 1);
            }
            hand[color]++;
        }
    }

    return ans == INT_MAX ? -1 : ans;
}

// Main function to calculate the minimum number of balls
int findMinInsertions(string board, string hand) {
    unordered_map<char, int> handCount;
    for (char c : hand) {
        handCount[c]++;
    }

    return dfs(board, handCount);
}

int main() {
    // Example 1
    string board1 = "WRRBBW";
    string hand1 = "RB";
    cout << "Minimum insertions for \"WRRBBW\": " << findMinInsertions(board1, hand1) << endl;

    // Example 2
    string board2 = "WWRRBBWW";
    string hand2 = "WRBRW";
    cout << "Minimum insertions for \"WWRRBBWW\": " << findMinInsertions(board2, hand2) << endl;

    // Example 3
    string board3 = "G";
    string hand3 = "GGGGG";
    cout << "Minimum insertions for \"G\": " << findMinInsertions(board3, hand3) << endl;

    return 0;
}
