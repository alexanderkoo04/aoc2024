#include <bits/stdc++.h>
#include <iostream>
typedef long long ll;
using namespace std;

void solve1() {
    priority_queue<int, vector<int>, greater<>> left;
    priority_queue<int, vector<int>, greater<>> right;
    int l, r, counter = 0;
    while (cin >> l >> r) {
        left.push(l);
        right.push(r);
        counter++;
    }
    long long sol = 0;
    while (counter) {
        sol += abs(left.top() - right.top());
        left.pop();
        right.pop();
        counter--;
    }
    cout << sol << endl;
}

void solve2() {
    unordered_map<int, int> left;
    unordered_map<int, int> right;
    int l, r;
    long long sol = 0;
    while (cin >> l >> r) {
        left[l]++;
        right[r]++;
    }
    for (const auto& pair : left) {
        if (right.find(pair.first) == right.end()) continue;
        sol += pair.first * pair.second * right[pair.first];
    }
    cout << sol << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // auto t = 0;
    // std::cin >> t;
    // for (int i = 0; i < t; i++) {
    //     solve1();
    // }
    // solve1();
    solve2();
}